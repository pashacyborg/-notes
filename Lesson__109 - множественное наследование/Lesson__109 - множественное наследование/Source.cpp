#include <iostream>
#include <string>

using namespace std;

/*� ������-���������� ����� ���� ��������� �������, ������� ����������� ����� �������
���������: class-child : modifier-name class-parent1, modifier2-name class parent2 
*/

class Car
{
public:
	string cspeed = "500 km/h";

	void Drive()
	{
		cout << "� ���!" << endl;
	}
};

class Airplane
{
public:
	string fspeed = "150 km/h";

	void Flying()
	{
		cout << "� ����!" << endl;
	}
};

class FlyingCar : public Car, public Airplane
{
public:

};

int main()
{
	setlocale(LC_ALL, "ru");

	FlyingCar fc;
	fc.Drive();	//��� ������ ���������, �.�. ��� ��� ����������� ��������� ������ FlyingCar
	fc.Flying();

	Car* ptrc = &fc;	//��� ����������� ���������, �.�. � ��� � ��� ����� �������� ������� ��� FlyingCar
	Airplane* ptra = &fc;
	return 0;
}