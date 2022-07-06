#include <iostream>

using namespace std;

/*Конструкторы классов вызываются изнутри: от более базового, к менее базовуму. Для класса C класс B является базовым.
Для класса B класс A является базовым.
*/

class A
{
public:
	A()
	{
		cout << "Вызвался конструктор класса A" << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "Вызвался конструктор класса B" << endl;
	}
};

class C : public B
{
public:
	C()
	{
		cout << "Вызвался конструктор класса C" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	C c;

	return 0;
}