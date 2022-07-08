#include <iostream>
#include <string>

using namespace std;

/*��� ������������ � ������-������ ����� ���� �������� ��������� ������� � ���������� ���������. 
� ����� ������, ���������� �� ������ �������������� ����������� ����� ����� ���� �������. 

�������: ���������� �����. ���������� �������� ������ ������-���������� � ������ ���� ������ ��������, �����
�������� �� ����� ������������. 

���������: ((type)object).method();
*/

class Car
{
public:
	void Use()
	{
		cout << "� ���!" << endl;
	}
};

class Airplane
{
public:
	void Use()
	{
		cout << "� ����!" << endl;
	}
};

class FlyingCar : public Car, public Airplane
{
	
};

int main()
{
	setlocale(LC_ALL, "ru");

	FlyingCar fc;
	((Car)fc).Use();	//� ���!
	((Airplane)fc).Use();	//� ����!

	return 0;
}