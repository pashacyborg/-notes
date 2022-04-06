#include <iostream>
#include <string>

using namespace std;


/*����� ������ ������ ����� ���� ������������� � ������ ������� ������
������� ������������ ������� ����� ��������, ���� �� ����� �����. 

������-�� ���������� �� ����� ���� weight � color ������ apple. ���� ������� ����� TakeApple ��� ������, �������� �������.

��� ����, ����� ������� ������� ������, ��� ����� ������� ������ �������� �������������, ������ ����. ����� friend 
� ��������� ������� ���� ������� � ������ ������ ����������� ������ �����: 
������������-�������� class-name::method-name(���������) {}

��� ���, ������� � ������� ������ ������� �������� ��� ������, �������� � ������ ���� ��������
*/

class Apple;		//����� Human �� ����� � ������ Apple. ��� ����, ����� ����� TakeApple �������, ���� ��������������� �����


class Human
{
public:
	void TakeApple(const Apple& apple);		//��� ����, ����� ������� ����� �� ������, ��� ����� ��������������� � ����� ������

private:
};

class Apple
{
public:
	friend void Human::TakeApple(const Apple& apple);		//����� Apple �� ����� � ������������� ������ Human
															//�.� ����� Apple ��������� ������. ��� ����� ������������� ��� ������
	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
	}

private:
	int weight;
	string color;
};



int main()
{
	setlocale(LC_ALL, "ru");

	Apple grannySmith(228, "green");
	Human bogdan;
	bogdan.TakeApple(grannySmith);
	
	
	return 0;
}

void Human::TakeApple(const Apple& apple)
{
	cout << "����� TakeApple:\t" << "weight: " << apple.weight << ", color: " << apple.color << endl;
}