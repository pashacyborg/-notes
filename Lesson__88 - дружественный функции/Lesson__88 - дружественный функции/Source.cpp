#include <iostream>

using namespace std;


/*������������� ������� �� ��������� � ������ ���������� ����� �������, ������� ���� � �� �������� ������ ������
(��������� ��� ������� ��������� ������), ����� ������ � �������� ����� ������(�� private ��� protected)

��� ����, ����� ������� ����� �������������, �� ����� �������� � ������� ��������� ������ � �������� ������ friend.
�.� friend ��������-�������

����� �������, �� ����� �������� � ���������� ������ � ������� ������� ��� ������. 

��������� this � ������������� �������� �� ��������, �.�. �� �������� ������ ������. ����� �������� ������ � �����
������ ���� ���������� ����� ������

�������� ������������� ������� ����� � ����� ����� ������(Public, private, protected)

���� ������� ����� ���� ������������ ����� � ���������� �������
*/
class Test;


class Point
{
private:
	int x;
	int y;

	friend void ChangeXandY(Point& object, Test& Data, int valueX, int valueY);
public:
	Point()
	{
		x = 0;
		y = 0;
		cout << this << "\t� ����� ������� ��������� ����������� ������" << endl;
	}

	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
		cout << this << "\t� ����� ������� ��������� ����������� ������" << endl;
	}


	void Print()
	{
		cout << endl << "X = " << this->x << "\t" << "Y = " << this->y << "\t\t";
	}

};


class Test
{
private:
	int dataField = 0;
public:
	void Print()
	{
		cout << "DATA = " << dataField << endl;
	}

	friend void ChangeXandY(Point& object, Test& Data, int valueX, int valueY);
};


void ChangeXandY(Point& object, Test& Data, int valueX, int valueY)
{
	
	object.x = valueX;
	object.y = valueY;
	Data.dataField = 100;			//����� ������ � ����� �����, ������� �� �������� ����� ������ ������
}


int main()
{
	setlocale(LC_ALL, "ru");
	Point object1(10, 2);
	Test miniobject;

	object1.Print();

	ChangeXandY(object1, miniobject, 11, 228);
	object1.Print();
	miniobject.Print();
	

	return 0;
}