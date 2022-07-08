#include <iostream>
#include <string>
using namespace std;

/*ƒелегирующий конструктор - удобство дл€ более эффективного написани€ кода, внесени€ правок в наш код.
ѕри создании множественных конструкторов, часто происходит дублирование кода: какие-то пол€ инициализируютс€ нулем, 
какие-то пол€ инициализируютс€ повторно и тд. 

¬ случае необходимости правок одного из пол€, нам придетс€ вносить правки во все конструкторы - это неэффективно. 
–ешение - делегирующие конструкторы 
—интаксис: A(param):A2(param) {}  конструктор ј делегирует какую-то работу конструктору ј2
*/

class A
{
public:
	string name;
	string surname;
	int age;

	//A(string name)
	//{
	//	this->name = name;
	//	this->surname = "";
	//	this->age = 0;
	//}

	//A(string name, string surname)
	//{
	//	this->name = name;					//“ака€ громоздка€ конструкци€ получаетс€ если не использовать
	//	this->surname = surname;			//делегирующие конструкторы
	//	this->age = 0;
	//}

	//A(string name, string surname, int age)
	//{
	//	this->name = name;
	//	this->surname = surname;
	//	this->age = age;
	//}

	A(string name)
	{
		this->name = name;
		this->surname = "";
		this->age = 0;
	}
														//¬ такой конструкции у нас не дублируютс€ уже объ€вленные пол€
	A(string name, string surname) : A(name)			//≈сли внесем правки в первом конструкторе, в остальных они внесутс€ автоматически
	{
		this->surname = surname;
	}

	A(string name, string surname, int age) : A(name, surname)
	{
		this->age = age;
	}

};

int main()
{
	setlocale(LC_ALL, "ru");
	A a("mikhail", "Petrovich");

	cout << a.name << " " << a.surname << " " << a.age << " " << endl;

	A b("ivan", "Ivanov", 50);
	cout << b.name << " " << b.surname << " " << b.age << " " << endl;
	return 0;
}