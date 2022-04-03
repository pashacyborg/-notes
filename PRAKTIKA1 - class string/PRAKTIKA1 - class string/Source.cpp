#include <iostream>
//#include <string>

using namespace std;
/*Все библиотеки подключать в один заголовочный файл с расширением .h
Хедер - это как прототип функции(объявление). А cpp файл - это реализация самой функции
#pragma once - говорит о том, что все, что написано в данном файле нужно включать в нашу программу один раз. 

Если пишем класс - выносим в отдельный файл.

В классе объявление функциии может быть ниже по коду, тем вызов этой функции/переменной. Это работает только в классе
*/

class MyString
{
public:
	MyString()
	{
		str = nullptr;
	}

	MyString(const char* str)
	{
		int length = strlen(str);
		this->str = new char[length + 1];	//Добавляем ячейку под терминирующий ноль, т.к. strlen его не учитывает

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];			//Этот механизм позволяет записать строку, переданную аргументом
		}
		this->str[length] = '\0';
	}

	MyString(const MyString& other)
	{
		int length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
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

		int length = strlen(other.str);
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
	void Print()		//успешно передастся в функцию main. 
	{
		cout << str << endl;
	}

private:
	char* str;

};


int main()
{
	MyString str("TEST");
	MyString str2("zhopa");

	MyString result = str + str2;

	return 0;
}