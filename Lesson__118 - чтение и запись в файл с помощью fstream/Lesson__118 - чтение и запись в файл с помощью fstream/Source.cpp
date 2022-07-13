#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

/*fstream.
* ����� open � fstream ������ ���������� ��������� "����� ������", ��� fstream::in ������� � ���, ��� �� ����� ����������� ��������
* ����� ��� ������. ���� �������� ����� ������������� �� ���������� ������������, ��������� ������� ���( | ). 
* ������: fs.open(path, fstream::in | fstream::out | fstream::app);
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
		cout << "���� ������!" << endl;
		cout << "�������� ��������: " << endl;
		cout << "(1) �������� ������ � ����" << endl;
		cout << "(2) ������� � ������� ������ �� �����" << endl;
		cout << "(3) ����� �� ���������" << endl;
		cin >> index;

		switch (index)
		{
		case 1:
		{
			cout << "������� ������ � ����������:" << endl;
			SetConsoleCP(1251);
			cin >> str;
			fs << str << "\n";
			SetConsoleCP(866);
			cout << "\n";
			break;
		}

		case 2:
		{
			cout << "������ �������:" << endl;
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
		cout << "������ ������ �����!" << endl;
	}

	fs.close();

	return 0;
}