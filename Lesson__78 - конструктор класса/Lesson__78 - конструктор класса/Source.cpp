#include <iostream>

using namespace std;

/*����������� ������ - ����� ��������, ������� ������������� ��� ����, ����� ���������������� ��������� ������ � 
�����-�� ��������� ��������, ������� ����� ���.
����������� ������ - ��� �������, ������� �� ���������� �������� ��������(��������, ���� void). ���������� ����� �������, 
��� ��� ������ ������, ������� � �������� ��������: Coordinate() {}

������� ������� ������������ ������ �� �� �����, �� ���������� ���, � ������ �������� ������. ����������� ���� � ������ ������, 
���� ���� �� �� ����� ����(����������� �� ���������. �� ������ ������ ��� � ������� ����)

�������� �� �����, ����� � ������� ������ ������ ���� ������������ ��������� ��������. ��� ����, ����� ��� �����������, 
�� ������� ���������� ������������ ������ ������ ���� �� �� ���� ������, ��� � � �������, ��������� �������� ������� �� 
����� ����������. ���������� ���������� ��� �� ������ �� ������. 

������, ����� �� ���� ������� ����������� ������, �� �� ������ ������ ������� ������ ��� ������ ��� ������. ��������
�������� ������ ������� ��������� �� ������ ��� ����������, ������� ��������� ����������� ������.
��� � �����, ���� ������ ��� �� ����� ������ ������� ������ ���� � ������� �������, �� ��������� ������ ������ � �������� 
������� ����� ��� ��� ��������

����� - �����, �� ������� ������ ����������� ������. ������� �������� � ������ �������� ������, ���� �� ����� �� ������

����������� �������(����� ������ � ������) �� ������� �� �����. �� ���������� ������ � ������ �������� ������ �������. 
�����: ���� �� ����� ������������ ������������� ������, �� �� ������ ���� � Public ������. ���� ��������� ��� � private, 
�� �� �� ������ ��������� �������(������ ����� ������ ������������, �������� ��� ���������� ������� �������������� ��������)

*/


class Coordinate
{
private:
	int x;
	int y;

public:
	Coordinate(int numberX, int numberY)
	{
		x = numberX;
		y = numberY;
	}

	int GetX()
	{
		return x;
	}

	void SetX(int numberX)
	{
		x = numberX;
	}

	int GetY()
	{
		return y;
	}

	void SetY(int numberY)
	{
		y = numberY;
	}

	void Print()
	{
		cout << "x = " << x << "\ny = " << y << endl;
	}

};

int main()
{
	setlocale(LC_ALL, "ru");

	Coordinate pointOne(5, 10);
	pointOne.Print();

	Coordinate pointTwo(228, 1337);
	pointTwo.Print();

	Coordinate pointThree(1, 2);
	pointThree.Print();

	return 0;
}
