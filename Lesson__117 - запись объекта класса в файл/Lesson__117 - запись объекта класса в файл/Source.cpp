#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

/*Для того, чтобы сохранить целый объект в документ с помощью потока вывода ofstream, нужно использовать метод 
* write. Для того, чтобы им воспользоваться, мы должны привести наш объект у указателю на char, а вторым параметром указать
* размер нашего класса - это можно сделать с помощью sizeof() - возвращает размер чего либо в байтах.
* Синтасис: ofstream-object.write((char*)&object-name, sizeof(object-name));
* 
* После записи объекта в файл, мы можем его оттуда считать с помощью потока ввода ifstream, для этого нужно создать
* объект того типа, который мы считываем(туда будем записывать информацию)
* 
* Метод read() возвращает true до тех пор, пока может считать блок данных. Как только данные закончатся, он вернет false. 
*/

class Point
{
public:
	int x;
	int y;
	int z;

	Point()
	{
		x = y = z = 0;
	}

	Point(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void Print()
	{
		cout << "X = " << x << "  Y = " << y << "  Z = " << z << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	string path = "maslo.txt";
	int index;
	cout << "Выберите действие: " << endl;
	cout << "(1) записать данные в файл" << endl;
	cout << "(2) вывести данные из файла" << endl;
	cin >> index;

	switch (index)
	{
	case 1:
	{
		Point point(338, 12, 1111);

		ofstream fout;
		fout.open(path, ofstream::app);

		if (fout.is_open())
		{
			cout << "Файл открыт!" << endl;
			fout.write((char*)&point, sizeof(Point));		//Сохраняем данные объекта класса Point в файл maslo.txt
		}
		else
		{
			cout << "Ошибка открытия файла!" << endl;
		}

		break;
	}
	case 2:
	{
		Point pnt;

		ifstream fin;
		fin.open(path);

		if (fin.is_open())
		{
			cout << "Файл открыт!" << endl;
			while (fin.read((char*)&pnt, sizeof(Point)))		//Считываем данные в объект pnt класса Point из файла maslo.txt, содержащий
			{													//данные типа Point
				pnt.Print();
			}
		}

		else
		{
			cout << "Ошибка открытия файла!" << endl;
		}

		break;
	}
	default:
		break;
	}

	return 0;
}