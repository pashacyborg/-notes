#include <iostream>
#include <string>

using namespace std;

/*������� � ������� ����� ��� ����, ����� ��� ����� �� ��������, �� �������� ���������� ������ ����������, 
�� � �� �� ����� ����� ���� ����� ����������� �������� �������� ���� �����, ���������� ������ ���������.

�� ������� � ����������� ������ ������ �������� �� ������������ ������, �� ��� ����� ��������, ���� ����� 
�������� �������� ������ �� ���������� ������. �� ������� ����������� ������ �������� ������ �� ������������
������. 
*/

class Apple
{
private: 
	//����� ����� ����������� �������� �������� ����� ���� �� ����� ������(� �� ����� ������),
	//��� ����� ����������� �����, ������������ ��� ����������.
	static int Count;	
	int id;
					
public:
	int weight;
	string color;

	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
		++Count;
		id = Count;
	}

	static void ChangeColor(Apple& apple, string color)
	{
		apple.color = color;
	}

	static int GetCount()
	{
		return Count;
	}

	void PrintInfo()
	{
		cout << "������ �" << id << ", ���: " << weight << ", ����: " << color << endl;
	}

	void ChangeColorStandard(string color)
	{
		this->color = color;
	}


};

int Apple::Count = 0;

int main()
{
	setlocale(LC_ALL, "ru");
	Apple apple1(100, "yellow");
	Apple apple2(200, "green");
	apple1.PrintInfo();
	apple2.PrintInfo();

	apple2.ChangeColor(apple2, "red");	//������� ����������� ����� ��� ����������� ������� ������, �����
	apple2.PrintInfo();					//������������� ����������� � ���.

	Apple::ChangeColor(apple2, "purple");		//��������� ����� �����
	apple2.PrintInfo();		

	apple2.ChangeColorStandard("darkblue"); //���������� ������� ����� ��� ����� �����. ������ �� ������ ���������� �� ����.
	apple2.PrintInfo();
	

	return 0;

}