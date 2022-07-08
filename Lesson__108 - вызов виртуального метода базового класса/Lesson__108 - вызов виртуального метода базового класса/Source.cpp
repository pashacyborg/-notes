#include <iostream>
#include <string>

using namespace std;

/*Чтобы в рамках класса наследника вызвать переопределенный метод из класса наследника, нужно явно указать принадлежность
такого метода к конкретному классу, иначе вызовется одноименный метод из текущего класса.

Синтаксис: ::class_name::method_name(param);

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
	BracesMsg(string msg) : Msg(msg)	//Делегируем конструктору из базового класса всю работу
	{
	}

	string GetMsg() override
	{
		return "[" + ::Msg::GetMsg() + "]";		//Явно указываем, что этот метод из базового класса Msg
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