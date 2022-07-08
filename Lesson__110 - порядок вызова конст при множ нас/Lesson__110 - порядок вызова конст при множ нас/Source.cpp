#include <iostream>
#include <string>

using namespace std;

/*������� ������ ������������� ������ ��� �������� ������� ������ ���������� ����� �����, � ����� ������� 
�����-��������� ����������� �������� �������-���������. 
*/

class Car
{	
public:
	Car()
	{
		cout << "������ ����������� ������ Car" << endl;
	}
};

class Airplane
{
public:
	Airplane()
	{
		cout << "������ ����������� ������ Airplane" << endl;
	}
};

class FlyingCar : public Airplane, public Car
{
public:
	FlyingCar()
	{
		cout << "������ ����������� ������ FlyingCar" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	FlyingCar fc;		//1. ����������� Airplane 2. ����������� Car 3. ����������� FlyingCar

	return 0;
}