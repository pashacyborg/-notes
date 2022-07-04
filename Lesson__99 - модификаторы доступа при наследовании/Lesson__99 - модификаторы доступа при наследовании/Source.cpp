#include <iostream>
#include <string>

using namespace std;

/*public ���� �������� ���� � �����
private ���� �������� ������ ������, ������ �������� ��� �������(����� ������ ������� ��� �� ���) � ���������� ����������
protected ���� ��������� �������� � ��� ������ ���������� ������, �� ����� ������ ������� ��� �� ���.
*/

class A
{
public: 
	string msg1 = "��������� 1";

private:
	string msg2 = "��������� 2";

protected:
	string msg3 = "��������� 3";
};

class B : public A	//��� ������������ public ����� �� ������ �� ���� �������� ����
{
public:
	void PrintMsg()
	{
		cout << "����� B: " << endl;
		cout << msg1 << endl;
		//msg2 ���������� �����������. ������ ������ ������ A
		cout << msg3 << endl;
	}
};

class C : private A	//��� ������������ private ��� ����� ������������ �������������� ���� ��� private(���). 
{					//�.�. � ����� msg1 � msg3 ����� C ����� ��������, ������ ��� ��� ��� private ����. msg2 ��� �� ��� private ����
public:				//���� �� ������ C ����� ����������� ��� ����� � ������������� public, �� �� �� ������� ������� �� � ������ ����
	void PrintMsg()
	{
		cout << "����� C: " << endl;
		cout << msg1 << endl;
		
		cout << msg3 << endl;
	}
};

class D : protected A	//��� ������������ protected ��������� ������ public ����
{
public:
	void PrintMsg()
	{
		cout << "����� D: " << endl;
		cout << msg1 << endl;

		cout << msg3 << endl;
	}
};

class E : public C
{
public:
	void PrintMsg()
	{
		cout << /*msg1*/" " << endl;	//������ �� ���������, �.�. ���� msg1 - private 
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	B b;
	b.PrintMsg();
	

	C c;	//��� private ������������ �� ��������� ��������� �� Public ����
	c.PrintMsg();

	D d;
	d.PrintMsg();

	E e;
	e.PrintMsg();
	
	

	return 0;
}