#include <iostream>
//#include <string>

using namespace std;
/*Все библиотеки подключать в один заголовочный файл с расширением .h
Хедер - это как прототип функции(объявление). А cpp файл - это реализация самой функции
#pragma once - говорит о том, что все, что написано в данном файле нужно включать в нашу программу один раз. 

Если пишем класс - выносим в отдельный файл.

В классе объявление функциии может быть ниже по коду, тем вызов этой функции/переменной. Это работает только в классе

Константная ссылка на тип данных (const MyString& other) - означает, что мы не копируем объект, а просто заглядываем по какому-то
адресу, смотрим на состояние полей какого-то объекта, поменять там ничего не можем(т.к. константная ссылка)
остановился на 38 минуте

При написании перегрузок рассуждать: вот нам нужно перегрузить оператор [] для строки. Что он возвращает? Очевидно - символ char. 
Что мы вписываем в квадратные скобки элемента массива? Индекс - значение типа int. Это значение и будет принимать наш 
оператор. Что этот оператор возвращает? Какой-то элемент из массива this. 
Для того, чтобы иметь возможность перезаписывать элементы в нашей строке, а не только их выводить, нужно модифицировать
наш оператор: возвращать char& ссылку на символ. 

Конструктор перемещения нужен для оптимизации кода, ускорения программы. В нашей программе(до реализации конструктора 
переноса) во время конкатенации создается новый объект. При return, этот объект попадает в конструктор копирования, копируется, 
затем тупо удаляется. А возвращается его копия - длительный и затратный процесс.

Как работает конструктор переноса: мы тупо говорим, что наша строка this указывает на строку other. Что размер у нашей
строки this такой же как у other. А потом мы тупо присваиваем nullptr объекту other(чтобы не стер данные, на которые
указывает объект this). Все. Мы не выделяем новую динамическую память, не заморачиваемся с поэлементным копированием. Мы просто
меняем адрес указателя на уже существующую память, а старый указатель ставим в nullptr. 
*/

class MyString
{
public:
	MyString()
	{
		str = nullptr;
		length = 0;
	}

	MyString(const char* str)
	{
		length = strlen(str);
		this->str = new char[length + 1];	//Добавляем ячейку под терминирующий ноль, т.к. strlen его не учитывает

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];			//Этот механизм позволяет записать строку, переданную аргументом
		}
		this->str[length] = '\0';
	}

	MyString(const MyString& other)
	{
		length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
	}

	MyString(MyString&& other)
	{
		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
	}

	~MyString()
	{
		delete[] str;
	}

	MyString& operator = (const MyString& other)
	{
		if (this->str != nullptr)
		{
			delete[] this->str;
		}

		length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';

		return *this;
	}

	MyString operator + (const MyString& other)
	{
		MyString newStr;

		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);
		newStr.length = thisLength + otherLength;

		newStr.str = new char[thisLength + otherLength + 1];	//Для нашего нового объекта выделим для поля str новую дин. память

		int i = 0;
		for (; i < thisLength; i++)
		{
			newStr.str[i] = this->str[i];
		}

		for (int j = 0; j < otherLength; j++,i++)
		{
			newStr.str[i] = other.str[j];
		}

		newStr.str[thisLength + otherLength] = '\0';

		return newStr;	//Мы возвращаем новый объект. Поэтому в вощвращаемом значении функции у нас Mystring. 
	}					//Важно: во время return у нас вызывается конструктор копирования
						//Если не реализовать конструктор копирования, программа работать не будет
						//Так же во время return у нас вызовется деструктор, который очистит динамическую память изначального класса newStr(а его копия
						//успешно передастся в функцию main. 
	
	bool operator == (const MyString& other)
	{
		if (this->length == other.length)
		{
			for (int i = 0; i < length; i++)
			{
				if (this->str[i] != other.str[i])
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator != (const MyString& other)
	{
		return !(this->operator==(other));
	}

	char& operator [] (int index)
	{
		return this->str[index];
	}

	void Print()		
	{
		cout << str << endl;
	}

	int Length()
	{
		return length;
	}

private:
	char* str;
	int length;
};


int main()
{
	MyString str("zhopa");
	MyString str2("zhopa");
	MyString result = str + str2;

	cout << str.Length() << endl;
	cout << str2.Length() << endl;
	cout << result.Length() << endl;
	cout << "\n\n\n";

	bool equal = str == str2;
	//bool equal = str.operator==(str2);	//то же самое. str - this, str2 - other

	cout << (str == str2) << endl;
	cout << (str != str2) << endl;

	str.Print();
	str[1] = 'Q';
	str.Print();

	cout << str[0] << endl;

	return 0;
}