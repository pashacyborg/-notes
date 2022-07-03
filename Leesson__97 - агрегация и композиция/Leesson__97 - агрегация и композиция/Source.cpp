#include <iostream>
using namespace std;

/*��������� ������ ������ � ������ - ��� ��������� ��� ����������. 
��������� - ��������� ������������ ��������� ����� � ������ ������(� ������� ��������). 
���������� - ����� ������� ������� ���������, ���������� ����� �� ����� ������������ ��� �������� � �����
������ ��� ��� ��������� �����. 
����� � ��� ���� ��� ����������� ������, ���� �� ������� ��������� �� ������� ������, � ������ �� ����������, 
����� ����� ������ ����������� ������ � ������ �������� ������ ���������� ���������� ����� - ����� ����������� ����������
�������������(���� �� ��������� ��������������). �� ���������� ������� �������� ������ �����������.


*/

class Cap
{
private:
	string color = "��������";
public:
	string GetTheCap()
	{
		return color;
	}
};

class Alien
{
private:
	Cap cap;
public:
	void InspectAlien()
	{
		cout << "��� ����� " << cap.GetTheCap() << " �����" << endl;
	}
};

class Human
{
private:
	class Brain
	{
	private:

	public:
		void Think()
		{
			cout << "� �����!" << endl;
		}
	};

	Brain brain;
	Cap cap;

public:
	void Think()
	{
		brain.Think();
	}

	void InspectTheCap()
	{
		cout << "��� ����� " << cap.GetTheCap() << " �����" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	Human human;
	human.Think();	//������ ����������: ���� �� ����� ��� ��������. ��� �� ������������ �������������

	human.InspectTheCap();	//������ ���������. ����� �� ������� �� ������ Human � ����� �������������� � ������ �������

	Alien alien;
	alien.InspectAlien();	//������ ��������� 2. ����� ������������ � ������ �������

	return 0;
}