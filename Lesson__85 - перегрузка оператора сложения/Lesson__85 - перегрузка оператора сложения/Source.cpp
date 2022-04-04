#include <iostream>
using namespace std;

/*��������� ��� ���������� ��������� + ��� ������������� �������� ������ ������� ��� ������� � �� ����
������� ����� ������, � ���� ������������� �������� ������� ���� ������ Point, � �� Point& � �� 

� ���� ������ �� ���������� ����������� ����������� ��� ����������� �����������. ���� �� �� �������� � ������������
������� � ������ Point, � ��� �� �������� ������ �� ����� Point a = b + c;(� ������ � ������� ������������)

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
	{
		return (this->x == other.x && this->y && other.y);	//��������� �������� ������ ���������� ��������. ������ true/false
	}

	bool operator != (const Point& other)
	{
		return !(this->x == other.x && this->y && other.y);
	}

	Point operator + (const Point& other)
	{
		Point temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;

		return temp;
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
	Point a(10, 2);
	Point b(4, 3);

	//Point c = a + b;		//����� ����������� ������
	Point c = a.operator+(b);
	

	return 0;
}
