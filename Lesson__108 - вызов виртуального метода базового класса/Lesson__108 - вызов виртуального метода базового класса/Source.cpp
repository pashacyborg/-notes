#include <iostream>
#include <string>

using namespace std;

/*����� � ������ ������ ���������� ������� ���������������� ����� �� ������ ����������, ����� ���� ������� ��������������
������ ������ � ����������� ������, ����� ��������� ����������� ����� �� �������� ������.

���������: ::class_name::method_name(param);

*/

class Msg
{
private:
	string msg;

public:
	Msg(string msg)
	{
		this->msg = msg;
	}

	virtual string GetMsg()
	{
		return msg;
	}
};

class BracesMsg : public Msg
{
public:
	BracesMsg(string msg) : Msg(msg)	//���������� ������������ �� �������� ������ ��� ������
	{
	}

	string GetMsg() override
	{
		return "[" + ::Msg::GetMsg() + "]";		//���� ���������, ��� ���� ����� �� �������� ������ Msg
	}
};

class Printer
{
public:
	void Print(Msg* msg)
	{
		cout << msg->GetMsg() << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	BracesMsg bmsg("Hello");
	Msg* pmsg = &bmsg;

	Printer print;
	print.Print(pmsg);

	return 0;
}