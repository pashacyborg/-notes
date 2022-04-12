#include <iostream>

using namespace std;


/*������������� ����� - �� ������, ���� ������ �������������� ������ ������������ � ����� ������� ��� ������
������ ������ �������������� �� ��������� � ������� ������. ��� � ���� ������� �������� ������������ ������, 
� ��������� ����� �������� �� �������� ������. �.�. ���-�� ������ �� ������������� � ������� ������ ������ 
����� �������������� ��������� ���� � ������� �������������� ������ - ��� ������. ��� ���������� ����� ���������� �� ����

������������ ������ � ����������. ����� ��� ����� ���������� ������ ��� �����������, �.�. ��� ��������� �������� ������. 
���������� ������ ������ �� �������� ����� ��������. 

��� ����, ����� �������� ������ � ��������� ����� ������ Human �� ������ Apple, ����� � ������ Human ������� friend Apple. 
�.�. ��������������� �������� ���: ���� ����� ������ ���� � ������� � Human, ����� ����� ����� ������ �����
�������� ������ � ����� Human. 
*/


class Apple;		

class Human
{
public:
	void TakeApple(const Apple& apple);	

	void EatApple(const Apple& apple)
	{
		//������ � ������ �� ����� �������� ������ � ����� Apple, 
		//� �� ������ �� ������ ������
	}
private:
	int maslo;
};

class Apple
{
public:
	friend Human;
									
	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
	}

	void Maslo(const Human& human)
	{
		
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

