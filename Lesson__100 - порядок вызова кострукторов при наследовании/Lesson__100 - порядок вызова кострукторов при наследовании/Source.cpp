#include <iostream>

using namespace std;

/*������������ ������� ���������� �������: �� ����� ��������, � ����� ��������. ��� ������ C ����� B �������� �������.
��� ������ B ����� A �������� �������.
*/

class A
{
public:
	A()
	{
		cout << "�������� ����������� ������ A" << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "�������� ����������� ������ B" << endl;
	}
};

class C : public B
{
public:
	C()
	{
		cout << "�������� ����������� ������ C" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	C c;

	return 0;
}