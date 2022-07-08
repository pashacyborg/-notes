#include <iostream>
#include <string>
using namespace std;

/*������������ ����������� - �������� ��� ����� ������������ ��������� ����, �������� ������ � ��� ���.
��� �������� ������������� �������������, ����� ���������� ������������ ����: �����-�� ���� ���������������� �����, 
�����-�� ���� ���������������� �������� � ��. 

� ������ ������������� ������ ������ �� ����, ��� �������� ������� ������ �� ��� ������������ - ��� ������������. 
������� - ������������ ������������ 
���������: A(param):A2(param) {}  ����������� � ���������� �����-�� ������ ������������ �2
*/

class A
{
public:
	string name;
	string surname;
	int age;

	//A(string name)
	//{
	//	this->name = name;
	//	this->surname = "";
	//	this->age = 0;
	//}

	//A(string name, string surname)
	//{
	//	this->name = name;					//����� ���������� ����������� ���������� ���� �� ������������
	//	this->surname = surname;			//������������ ������������
	//	this->age = 0;
	//}

	//A(string name, string surname, int age)
	//{
	//	this->name = name;
	//	this->surname = surname;
	//	this->age = age;
	//}

	A(string name)
	{
		this->name = name;
		this->surname = "";
		this->age = 0;
	}
														//� ����� ����������� � ��� �� ����������� ��� ����������� ����
	A(string name, string surname) : A(name)			//���� ������ ������ � ������ ������������, � ��������� ��� �������� �������������
	{
		this->surname = surname;
	}

	A(string name, string surname, int age) : A(name, surname)
	{
		this->age = age;
	}

};

int main()
{
	setlocale(LC_ALL, "ru");
	A a("mikhail", "Petrovich");

	cout << a.name << " " << a.surname << " " << a.age << " " << endl;

	A b("ivan", "Ivanov", 50);
	cout << b.name << " " << b.surname << " " << b.age << " " << endl;
	return 0;
}