#include <iostream>
#include <string>

using namespace std;

/*public поле доступно всем и везде
private поле доступно только классу, внутри которого оно создано(через объект доступа так же нет) и недоступно наследнику
protected поле позвол€ет работать с ним внутри наследника класса, но через объект доступа так же нет.
*/

class A
{
public: 
	string msg1 = "—ообщение 1";

private:
	string msg2 = "—ообщение 2";

protected:
	string msg3 = "—ообщение 3";
};

class B : public A	//ѕри наследовании public никак не вли€ет на наши исходные пол€
{
public:
	void PrintMsg()
	{
		cout << " ласс B: " << endl;
		cout << msg1 << endl;
		//msg2 недоступен наследникам. “олько внутри класса A
		cout << msg3 << endl;
	}
};

class C : private A	//ѕри наследовании private наш класс воспринимает унаследованные пол€ как private(все). 
{					//“.е. с полем msg1 и msg3 класс C может работать, потому что это его private пол€. msg2 уже не его private поле
public:				//≈сли от класса C будет унаследован еще класс с модификатором public, то он не получит доступа ни к одному полю
	void PrintMsg()
	{
		cout << " ласс C: " << endl;
		cout << msg1 << endl;
		
		cout << msg3 << endl;
	}
};

class D : protected A	//ѕри наследовании protected изменитс€ только public поле
{
public:
	void PrintMsg()
	{
		cout << " ласс D: " << endl;
		cout << msg1 << endl;

		cout << msg3 << endl;
	}
};

class E : public C
{
public:
	void PrintMsg()
	{
		cout << /*msg1*/" " << endl;	//Ќичего не выведетс€, т.к. поле msg1 - private 
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	B b;
	b.PrintMsg();
	

	C c;	//ѕри private наследовании не получитс€ добратьс€ до Public пол€
	c.PrintMsg();

	D d;
	d.PrintMsg();

	E e;
	e.PrintMsg();
	
	

	return 0;
}