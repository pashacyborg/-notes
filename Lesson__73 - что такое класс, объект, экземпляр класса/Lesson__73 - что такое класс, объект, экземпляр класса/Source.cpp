#include <iostream>
#include <string>
using namespace std;

/*����� - ���������������� ��� ������. ��� ������, ������� �� ����� �������� ����
���������: class class-name {} . ����� class - ��������

��� �������� ������ ����� �������� ����������� ��������. � ����� ������ �� ������� ������� ������, �� �� ���������� ������� ��������

Grib maslenok - ������ ���������� maslenok ���� Grib. ���� ������(���������) maslenok ������ Grib
int a - ������� ������ � �� ������ ������ int(����� ������), ������� ������ ������������� ��������

����� - ������, ������� ��������� ����������. ��������� ������ ������ - ������
�������� ������ ������� ������ ���� ������. ����������� ����(int, char � ��), ���� ������ ������ ����� �������� ������ ����������

��� ������������� ������ �� ������� ���������� ���������� <string>
����� �������������� �������, ����� ���� ���� ��������� ����������� ������� - public: ��� private:

��������, ������� �������� �����-�� ��������������(����, ���, ����� ��������� � ��) - ���������� ������ ������(int age - ��� ����)

������ ������ ������������ ��� ��� ������, � ��������� � ���� �� ���������(������������� ���� ���������� �� ���� ���������� �������, 
������ ��������� � ������-�� �� ������� ����� ������ ������� mas[0][1])


*/

class Grib
{
public:
	string name;						
	int age;
	int weight;
};

class Coordinate
{
public:
	int x;
	int y;
	int z;
};

int main()
{
	Grib type1;
	type1.name = "maslenok oiler";
	type1.age = 5;
	type1.weight = 500;
	
	cout << type1.name << endl;
	cout << type1.age << endl;
	cout << type1.weight << endl;

	cout << "_________________________________" << endl;

	Grib type2;
	type2.name = "maslenok natural";
	type2.age = 6;
	type2.weight = 300;

	cout << type2.name << endl;
	cout << type2.age << endl;
	cout << type2.weight << endl;

	cout << "_________________________________" << endl;

	Coordinate dot1;
	dot1.x = 4;
	dot1.y = 2;
	dot1.z = 5;

	cout << dot1.x << endl;
	cout << dot1.y << endl;
	cout << dot1.z << endl;

	return 0;
}