#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

/*��� ����, ����� ��������� ����� ������ � �������� � ������� ������ ������ ofstream, ����� ������������ ����� 
* write. ��� ����, ����� �� ���������������, �� ������ �������� ��� ������ � ��������� �� char, � ������ ���������� �������
* ������ ������ ������ - ��� ����� ������� � ������� sizeof() - ���������� ������ ���� ���� � ������.
* ��������: ofstream-object.write((char*)&object-name, sizeof(object-name));
* 
* ����� ������ ������� � ����, �� ����� ��� ������ ������� � ������� ������ ����� ifstream, ��� ����� ����� �������
* ������ ���� ����, ������� �� ���������(���� ����� ���������� ����������)
* 
* ����� read() ���������� true �� ��� ���, ���� ����� ������� ���� ������. ��� ������ ������ ����������, �� ������ false. 
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
	cout << "�������� ��������: " << endl;
	cout << "(1) �������� ������ � ����" << endl;
	cout << "(2) ������� ������ �� �����" << endl;
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
			cout << "���� ������!" << endl;
			fout.write((char*)&point, sizeof(Point));		//��������� ������ ������� ������ Point � ���� maslo.txt
		}
		else
		{
			cout << "������ �������� �����!" << endl;
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
			cout << "���� ������!" << endl;
			while (fin.read((char*)&pnt, sizeof(Point)))		//��������� ������ � ������ pnt ������ Point �� ����� maslo.txt, ����������
			{													//������ ���� Point
				pnt.Print();
			}
		}

		else
		{
			cout << "������ �������� �����!" << endl;
		}

		break;
	}
	default:
		break;
	}

	return 0;
}