#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

/*fstream.
* Метод open у fstream вторым параметром принимает "режим работы", где fstream::in говорит о том, что мы имеем возможность открытия
* файла для чтения. Этот параметр можно комбинировать из нескольких составляющих, используя битовое или( | ). 
* Пример: fs.open(path, fstream::in | fstream::out | fstream::app);
*/


int main()
{
	setlocale(LC_ALL, "ru");

	fstream fs;
	string path = "maslo.txt";
	fs.open(path, fstream::in | fstream::out | fstream::app);

	int index;
	string str;

	if (fs.is_open())
	{
		cout << "Файл открыт!" << endl;
		cout << "Выберите действие: " << endl;
		cout << "(1) записать данные в файл" << endl;
		cout << "(2) считать и вывести данные из файла" << endl;
		cout << "(3) выйти из программы" << endl;
		cin >> index;

		switch (index)
		{
		case 1:
		{
			cout << "Введите данные с клавиатуры:" << endl;
			SetConsoleCP(1251);
			cin >> str;
			fs << str << "\n";
			SetConsoleCP(866);
			cout << "\n";
			break;
		}

		case 2:
		{
			cout << "Данные считаны:" << endl;
			while (!fs.eof())
			{
				str = "";
				fs >> str;
				cout << str << endl;
			}
			break;
		}

		case 3:
		{
			return 0;
		}

		default:
			break;
		}
	}
	else
	{
		cout << "Ошибка чтения файла!" << endl;
	}

	fs.close();

	return 0;
}