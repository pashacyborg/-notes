#include <iostream>
#include <string>

using namespace std;

/*��� �������� ������� �, �� ������� ���������� ����������� �� ��������� ������ �. ���� �� ����� �������
������ ����������� ������ �, �� ������ ���� ������� � ������������ ������ � ����������� ������ �. 
���������: B():A(some_param). 

*/

class A
{
public:
	A()
	{
		msg = "������";
	}

	A(string msg)
	{
		this->msg = msg;
	}

	void PrintMessage()
	{
		cout << "��������� " << msg << " ���������" << endl;
	}

private:
	string msg;
	
};

class B : public A
{
public:
	/*B():A()
	{
		
	}*/		//��� ����� �������� ��������� ����������� �� ��������(������ ���������)

	B():A("�����������")
	{
			//��� ����� �������� ��������� ������ ����������� � ��������� ����������� ���������
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	B b;
	b.PrintMessage();

	return 0;
}