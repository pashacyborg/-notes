#include <iostream>

using namespace std;


/*���������� static ����� ��� ���� ��������. ������� ����� ���������� ����� ���� ������, ��� ��������� � ���
����� ������ ������ �� ������ ��� ���������. 
� ���������� ���� static ����� ���������� �������� ����� �����, � �� ����� ������ + �����.

������ ��� ������������ ����������� ����������, �� ���� ����������������: ���-������-����������__class-name::variable-name = ��������.
���������������� ����������� ���� ����� ��� ������: int Apple::count = 0;

static - ��� �����������

� ������� static ����� ������ ������������� ���������� id ��� ������� ������. 
������� ����� ����� ���������� ����, ���� ����������� �����������. id ��������� ��������� ����� �������
*/

class Apple
{
public:
	static int count;

	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
		count++;
		id = count;
	}

	int GetId()
	{
		return id;
	}

private:
	int weight;
	string color;
	int id;
};

int Apple::count = 0;	//������������� ���������� count ��� ������
//int Apple::number = 0;

int main()
{
	Apple apple(50, "red");
	Apple apple2(100, "green");
	Apple apple3(150, "yellow");

	cout << Apple::count << endl;
	cout << apple2.count << endl;		//��� �� �� �� ���������� � ���� count, �������� ����� ����������(� ������ ������ 3)

	cout << endl << endl;
	cout << apple.GetId() << endl;		//������� 1
	cout << apple2.GetId() << endl;		//2
	cout << apple3.GetId() << endl;		//3

	return 0;
}