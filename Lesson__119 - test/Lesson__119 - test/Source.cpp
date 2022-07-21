#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

/*���������� ���������� ���������� ����� ������ >> <<
* ���� ����������� ��� ���������, ����� �������� � ���������.
*
* ������� ���� ���� ������, ��� �������� �� ���������� ��� ���������, �� ����� ��� �������� � �������, ��� � ���������� � ����.
* ����������, ��� �������� �� �������, ��� � ��������(���������) �� �����.
*
* ostream, ofstream, ifstream, fstream ������� ����� ����� �� ������� ������������. � ������� ��������� �� ������� �����
* fstream �� ����� ��������� �� �������� ��������� ������� ���� �������.
*
* ��� ���������� ��������� ������������ �������� ����� ������ ��� ������, ������� �� ��������� �� �����(������ ostream).
* ������ ����������� �������� - ������ �� ������ ostream/��� ����������. ������ ���������� �� �������� �����, ��� �������� �����
* ����������� �������� << ��� >>(����� ����� �����������, � �������, �������� ��� ������ �� �������).
* ����� ��������� ������ �� ��������� ������ ���� ostream/����������.
* ���������: ostream& operator<<(ostream& os, const Point& point) { return os }
*
* ������ ����, ������ ������ ��������� �� ������ ������ ��������������, ������ �� ������.
* ����� ������ ����� ����������� ������ ���, ����� ������� ������ �� �������. � ����� ����� ���� ��� ����������� �������� <<
* � ��� ����� �������� �������������.
*
* �����: ��������� � �����, ������������� ������ fstream � �������� ����������/���������� ������ ����������. ���� ����, ���� ������. 
* ������ �������� �� ��������. ������� ����� �������� �������� ofstream � ifstream. 
*
*/

class Point
{
public:
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
		cout << "X = " << x << " Y = " << y << " Z = " << z << endl;
	}
	friend ostream& operator<<(ostream& os, const Point& point);
	friend istream& operator>>(istream& is, Point& point);
	
private:
	int x;
	int y;
	int z;
};

ostream& operator<<(ostream& os, const Point& point)
{
	os << point.x << " " << point.y << " " << point.z; 
	return os;
}

istream& operator>>(istream& is, Point& point)
{
	is >> point.x >> point.y >> point.z;
	return is;
}

int main()
{
	setlocale(LC_ALL, "ru");
	string path = "test.txt";
	Point p(222, 112, 87);
	fstream fs;
	cout << p << endl;


	fs.open(path, fstream::in | fstream::out | fstream::app);

	if (!fs.is_open())
	{
		cout << "������ �������� �����!" << endl;
	}
	else
	{
		cout << "���� ������!" << endl;
		//fs << p << "\n";										

		while (!fs.eof())	//�������� �� ��������
		{
			Point p2;
			fs >> p2;
			if (fs.eof())
			{
				break;
			}
			cout << p2 << endl;
		}
		
	}

	fs.close();

	return 0;
}