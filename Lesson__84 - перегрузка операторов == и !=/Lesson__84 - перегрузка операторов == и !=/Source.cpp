#include <iostream>

using namespace std;

/*��� ���������� ���������� ���������� ����������: ��� ��� ����� �������� ��� �����. � ����� ������� ��� ����� ����� �������?
���� �� ���� � ������������ � y ���� ����� �����. 
��������� ��������� - ���� true, ���� false. 

��������� == �� ��������� ���
*/

class Point
{
private:
	int x;
	int y;

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

	bool operator == (const Point& other)
	{/*
		if (this->x == other.x && this->y && other.y)
		{
			return true;
		}
		else
		{
			return false;
		}*/

		return (this->x == other.x && this->y && other.y);	//��������� �������� ������ ���������� ��������. ������ true/false
	}

	bool operator != (const Point& other)
	{
		return !(this->x == other.x && this->y && other.y);
	}

	void Setx(int x)
	{
		this->x = x;
	}

	void Sety(int y)
	{
		this->y = y;
	}

	int Getx()
	{
		return x;
	}

	int Gety()
	{
		return y;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	Point a(1, 2);
	Point b(1, 2);
	
	bool result1 = a == b;	//�������� true/false
	bool result2 = a != b;

	return 0;
}