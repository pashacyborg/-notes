#include <iostream>
#include <string>

using namespace std;
/*��� ������������� ������������ ����� ���� ��� ��������: ����� ������������� ���� ����� � ����� ��� �����������. 
* � ������, ���� ��� �����������, ���������� ���������� � "������������" ������������ - ��������, ��� �������
* ������-�������� ����� ���� ����� ����� ��������. ����� �������, ����� �� ���������� ������� ��������� ����������
* ����������� �����, �� ����� ������ ������ "�������", ���, ��������, �������� � HP(�� ����� ���� ��� ������� HP � ������ ���������)
* 
* �����: � ����������� ������ GraphicCard �� �������� ����������, �� ������� ������� ���� ���������� - �������� ������ � GPU.
* ����� ������������� ������������� �� ������� �� ������ 
* 
* 
*/


//���� �������� ������, ����� � GPU � Memory �� ������ ���������� ������ Component. �.�. � ������� ��������� ������������ �� ����� ������
//class Component
//{
//public:
//	Component(string nameOfComponent)
//	{
//		cout << "�������� ����������� ������ Component" << endl;
//		this->nameOfComponent = nameOfComponent;
//	}
//
//	string nameOfComponent;
//};
//
//
//class GPU : public Component
//{
//public:
//	GPU(string GpuName) :Component(GpuName)
//	{
//		cout << "�������� ����������� ������ GPU" << endl;
//		cout << nameOfComponent << endl;
//	}
//};
//
//
//class Memory : public Component
//{
//public:
//	Memory(string MemoryName) :Component(MemoryName)
//	{
//		cout << "�������� ����������� ������ Memory" << endl;
//		cout << nameOfComponent << endl;
//	}
//};
//
//
//class GraphicCard : public GPU, public Memory
//{
//public:
//	GraphicCard(string GpuName, string MemoryName) :GPU(GpuName), Memory(MemoryName)
//	{
//		cout << "�������� ����������� ������ GraphicCard" << endl;
//	}
//};



/////////////////////////////////////////////////////////////////////////////////////////
//���������� ������, ����� ��� ������� �������� ����������� �� ������ ��������. � ���� �������� ������������ 
//���������� �������� ����� virtual ����� ������ public/private/protected


class Character
{
public:
	int HP = 100;	//� ������ ��������� �� ����� ���� ��� ������� �����

	Character()
	{
		cout << "�������� ����������� ������ Character" << endl;
	}
};

class Ork : virtual public Character		//virtual ��� ������������ ��������� ������� ����������� ���������
{
public:
	Ork()
	{
		cout << "�������� ����������� ������ Ork" << endl;
	}
};

class Warrior : virtual public Character
{
public:
	Warrior()
	{
		cout << "�������� ����������� ������ Warrior" << endl;
	}
};

class OrkWarrior : public Ork, public Warrior
{
public:
	OrkWarrior()
	{
		cout << "�������� ����������� ������ OrkWarrior" << endl;
	}

};

int main()
{
	setlocale(LC_ALL, "ru");

	//GraphicCard gc("msi", "hyperx");	//case 1
	
	OrkWarrior ow;


	return 0;
}