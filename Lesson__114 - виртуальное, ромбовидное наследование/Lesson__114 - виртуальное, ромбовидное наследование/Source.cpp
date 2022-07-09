#include <iostream>
#include <string>

using namespace std;
/*При множественном наследовании может быть две ситуации: когда дублирующиеся поля нужны и когда они недопустимы. 
* В случае, если она недопустимы, необходимо прибегнуть к "ромбовидному" наследованию - ситуация, при которой
* классы-родители имеют один общий класс родитель. Таким образом, когда от нескольких классов родителей получается
* производный класс, он имеет только одного "дедушку", как, например, ситуация с HP(не может быть две полоски HP у одного персонажа)
* 
* Важно: В конструктор класса GraphicCard мы передаем компоненты, из которых состоит наша видеокарта - название памяти и GPU.
* Через делегирование конструкторов мы получим на выходе 
* 
* 
*/


//Ниже приведен случай, когда у GPU и Memory по одному экземпляру класса Component. Т.е. у каждого отдельное наследование от этого класса
//class Component
//{
//public:
//	Component(string nameOfComponent)
//	{
//		cout << "Вызвался конструктор класса Component" << endl;
//		this->nameOfComponent = nameOfComponent;
//	}
//
//	string nameOfComponent;
//};
//
//
//class GPU : public Component
//{
//public:
//	GPU(string GpuName) :Component(GpuName)
//	{
//		cout << "Вызвался конструктор класса GPU" << endl;
//		cout << nameOfComponent << endl;
//	}
//};
//
//
//class Memory : public Component
//{
//public:
//	Memory(string MemoryName) :Component(MemoryName)
//	{
//		cout << "Вызвался конструктор класса Memory" << endl;
//		cout << nameOfComponent << endl;
//	}
//};
//
//
//class GraphicCard : public GPU, public Memory
//{
//public:
//	GraphicCard(string GpuName, string MemoryName) :GPU(GpuName), Memory(MemoryName)
//	{
//		cout << "Вызвался конструктор класса GraphicCard" << endl;
//	}
//};



/////////////////////////////////////////////////////////////////////////////////////////
//Рассмотрим случай, когда два будущих родителя наследуются от одного родителя. В этом варианте наследования 
//необходимо добавить слово virtual перед словом public/private/protected


class Character
{
public:
	int HP = 100;	//У одного персонажа не может быть две полоски жизни

	Character()
	{
		cout << "Вызвался конструктор класса Character" << endl;
	}
};

class Ork : virtual public Character		//virtual при наследовании позволяет создать ромбовидную структуру
{
public:
	Ork()
	{
		cout << "Вызвался конструктор класса Ork" << endl;
	}
};

class Warrior : virtual public Character
{
public:
	Warrior()
	{
		cout << "Вызвался конструктор класса Warrior" << endl;
	}
};

class OrkWarrior : public Ork, public Warrior
{
public:
	OrkWarrior()
	{
		cout << "Вызвался конструктор класса OrkWarrior" << endl;
	}

};

int main()
{
	setlocale(LC_ALL, "ru");

	//GraphicCard gc("msi", "hyperx");	//case 1
	
	OrkWarrior ow;


	return 0;
}