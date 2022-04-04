#include <iostream>

using namespace std;

/*���������� ����� ��� ����, ����� ��������� �������� ��� ����������������� ������ ������, ������� ����������
��� ����� �� �������������(��������, ��������� ���� ��� ����������� ����� ������, � ��� ������ ��� ����� ��������� ������������� ��� ������)

���������� ����������� ���������� � ������������ ���������� ���, ��� � ����������� ������������� �������� ��������� ��������
� ��� �� ���, ��� �� ���������� �� ������� ������, � ������ ������������ ����� �������� �������(��� ����������).
����� �������, ���� �������� ������� ���� ���������, �� ������������ �����, � ������� ���� �� ���������. ������� 
� ����� �������� ������������ ���� ������� d �� ����������, � ���� ������� � ����������, �� ��� ����� �������� ������������
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

	Point& operator ++ ()
	{
		this->x++;
		this->y++;

		return *this;
	}

	Point& operator ++ (int value)
	{
		Point temp(*this);
		this->x++;
		this->y++;

		return temp;
	}

	Point& operator -- ()
	{
		this->x--;
		this->y--;

		return *this;
	}

	Point& operator -- (int value)
	{
		Point temp(*this);
		this->x--;
		this->y--;

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
				
	Point c = a.operator++();
	Point d = c.operator++(5);		//��� �������, �� �� ������ ���������� �����-�� ��������� int �������� ��� ����, 
									//����� ���������� ���� �������� ���������� ��������� �� ������������
	/*Point c = ++a;
	Point d = c++;*/

	Point e = --d;
	Point f = e--;


	return 0;
}