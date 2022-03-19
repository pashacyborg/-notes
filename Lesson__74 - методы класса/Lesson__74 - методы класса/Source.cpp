#include <iostream>

using namespace std;

/*������ ������(��� �������) ��������������� ����� ��� ��, ��� � ������������ �������. 
�������(������) ������ ���� ����� ���� ����������, ���� ����� ���� �����������
����� �� ������� print ����� ����������� ������ ������ ������, ������� �� smartPrint. ������� ���������� ���� ������
�� ����, �.�. ��� ��������� ����� ����� � �������� ���������� ����� �������� ������ ����� ������ - �������.
���������� � ���� ������� ��� ��, ��� � � ��������� ������ - ����� ������ ������ � ������ + ��� �������. 

������� smartPrint - ����� ������ Human. ��� ����� �������� ����� �������� ������ ����� ������.
� ������� ���������� ���� ���� ������. ���� ���������� ������� ���� ������� ���������� ����� ������ ��������� - ������ 
�� ���������.
*/

class Human
{
public:
	string name;
	int age;
	int weight;

	void smartPrint()
	{
		cout << "���: " << name << "\n�������: " << age << "\n���: " << weight << endl;
	}
};

void print(Human somePerson)
{
	cout << somePerson.name << endl;
	cout << somePerson.age << endl;
	cout << somePerson.weight << endl;
}

void main()
{
	setlocale(LC_ALL, "ru");
	Human firstHuman;
	firstHuman.name = "Alex";
	firstHuman.age = 25;
	firstHuman.weight = 80;
	//print(firstHuman);
	firstHuman.smartPrint();

	cout << "_______________________" << endl;

	Human secondHuman;
	secondHuman.smartPrint();
}