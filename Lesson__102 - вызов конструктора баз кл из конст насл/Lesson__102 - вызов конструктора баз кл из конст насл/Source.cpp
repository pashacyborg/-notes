#include <iostream>
#include <string>

using namespace std;

/*При создании объекта Б, по дефолту вызывается конструктор ПО УМОЛЧАНИЮ класса А. Если мы хотим вызвать
другой конструктор класса А, мы должны явно указать в конструкторе класса Б конструктор класса А. 
Синтаксис: B():A(some_param). 

*/

class A
{
public:
	A()
	{
		msg = "пустое";
	}

	A(string msg)
	{
		this->msg = msg;
	}

	void PrintMessage()
	{
		cout << "Вызвалось " << msg << " сообщение" << endl;
	}

private:
	string msg;
	
};

class B : public A
{
public:
	/*B():A()
	{
		
	}*/		//При таком варианте вызовется конструктор по умочанию(пустое сообщение)

	B():A("заполненное")
	{
			//При таком варианте сработает второй конструктор и вызовется заполненное сообщение
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	B b;
	b.PrintMessage();

	return 0;
}