#include <iostream>
#include <string>

using namespace std;

/*��������� - �������������� � ���, ��� ����� � ���-�� �����������������. ����� ����������������� � �����
* ����� ����������, ��� ����� ������� ������, ������� ����, ���� �����. 
* ��������� - ��������� ������, ����� ������� �� ����� ����������������� � ��������. 
* ���� ��������� ��� ������ �������� ����� ������, �������� ���� ��� � ������� �� ��������� ����

* � ����� �++ ����. ����� Interface ���, ����� ������������� ��������������
* ��������� - ����������� �����, � ������� ��� ������ ����� �����������(�� ����� ���� ����������). 
* �� �� ����� � ���� ����� ����� ��������� ���� ��� ������ � �� ��� ����� �����(��� ��� ����� ���������).
* 
* ����� �� ����������� �� ����������, ������� �������� �� "��������� ���������", � "�������������" ���������
* ���� ��������� ������������� ��������� IBicycle, �� ������ �� ��� ����������.
* 
* � �++ ���� ������ ����� ����������� ��������� �����������(������������� ������������ ����� ����������� �������)
* 
* �����: � ����� BikeKontrol � �������� �� ����� ��������� � �������� ��������� ������ �� ������ �������� ������. ���� ������ ��� ���� � �������-����������,
* ����������� ��� ��� �������� ���������.
* ����� ����������� ��������� ��� ��������� 100500 ����������� � ���������� �� ������ �������� ��� �������� ����������� ����������,
* ���� ��� ��������� ��������� ��������� IBicykle
*/

class IBicykle
{
public:
	virtual void TurnTheWheel() = 0;
	virtual void StartMoving() = 0;
};

class SimpleBicykle : public IBicykle
{
public:
	void StartMoving() override
	{
		cout << "������ ����� StartMoving() � SimpleBicykle" << endl;
	}

	void TurnTheWheel() override
	{
		cout << "������ ����� TurnTheWheel() � SimpleBicykle" << endl;
	}
};

class SportBicykle : public IBicykle
{
public:
	void StartMoving() override
	{
		cout << "������ ����� StartMoving() � SportBicykle" << endl;
	}

	void TurnTheWheel() override
	{
		cout << "������ ����� TurnTheWheel() � SportBicykle" << endl;
	}
};

class Human
{
public:
	void BikeControl(IBicykle& bike)
	{
		cout << "�������� �����" << endl;
		bike.StartMoving();
		cout << "�������� ������" << endl;
		bike.TurnTheWheel();
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	SimpleBicykle bike1;
	SportBicykle bike2;
	Human human;
	human.BikeControl(bike1);	//������� ������ ���������� � SimpleBicykle
	human.BikeControl(bike2);	//������� ������ ���������� � SportBicykle

	return 0;
}