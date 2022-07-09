#include <iostream>
#include <string>

using namespace std;

/*Интерфейс - договоренность о том, как можно с чем-то взаимодействовать. Чтобы взаимодействовать с любым
* типом велосипеда, нам нужно крутить педали, крутить руль, либо ехать. 
* Интерфейс - публичные методы, через которые мы можем взаимодействовать с объектом. 
* Один интерфейс для разных ситуаций очень удобен, экономит кучу сил и времени на написание кода

* В языке с++ ключ. слова Interface нет, будем реализовывать самостоятельно
* Интерфейс - абстрактный класс, в котором ВСЕ методы чисто виртуальные(не может быть реализации). 
* Мы не знаем у чего можно будет покрутить руль или педали и на чем можно ехать(что это будет конкретно).
* 
* Когда мы наследуемся от интерфейса, принято говорить не "наследуем интерфейс", а "реализовываем" интерфейс
* Если табуретка реализовывает интерфейс IBicycle, мы сможем на ней покататься.
* 
* В с++ один объект может наследовать несколько интерфейсов(множественное наследование чисто виртуальных методов)
* 
* Важно: в метод BikeKontrol у человека мы можем принимать в качестве параметра ссылку на объект базового класса. Этот объект уже вшит в объекты-наследники,
* разобраться как это работает детальнее.
* Такая конструкция позволяет нам создавать 100500 велосипедов и передавать их нашему человеку без именения принимаемых параметров,
* ЕСЛИ наш велосипед реализует интерфейс IBicykle
*/

class IBicykle
{
public:
	virtual void TurnTheWheel() = 0;
	virtual void StartMoving() = 0;
};

class SimpleBicykle : public IBicykle
{
public:
	void StartMoving() override
	{
		cout << "Вызван метод StartMoving() у SimpleBicykle" << endl;
	}

	void TurnTheWheel() override
	{
		cout << "Вызван метод TurnTheWheel() у SimpleBicykle" << endl;
	}
};

class SportBicykle : public IBicykle
{
public:
	void StartMoving() override
	{
		cout << "Вызван метод StartMoving() у SportBicykle" << endl;
	}

	void TurnTheWheel() override
	{
		cout << "Вызван метод TurnTheWheel() у SportBicykle" << endl;
	}
};

class Human
{
public:
	void BikeControl(IBicykle& bike)
	{
		cout << "Начинаем ехать" << endl;
		bike.StartMoving();
		cout << "Начинаем рулить" << endl;
		bike.TurnTheWheel();
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	SimpleBicykle bike1;
	SportBicykle bike2;
	Human human;
	human.BikeControl(bike1);	//Вызовет методы управления у SimpleBicykle
	human.BikeControl(bike2);	//Вызовет методы управления у SportBicykle

	return 0;
}