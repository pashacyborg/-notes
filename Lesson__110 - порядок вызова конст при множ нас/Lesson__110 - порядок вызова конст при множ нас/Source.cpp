#include <iostream>
#include <string>

using namespace std;

/*Порядок вызова конструкторов класса при создании объекта класса наследника будет такой, в каком порядке 
класс-наслденик унаследовал свойства классов-родителей. 
*/

class Car
{	
public:
	Car()
	{
		cout << "Вызван конструктор класса Car" << endl;
	}
};

class Airplane
{
public:
	Airplane()
	{
		cout << "Вызван конструктор класса Airplane" << endl;
	}
};

class FlyingCar : public Airplane, public Car
{
public:
	FlyingCar()
	{
		cout << "Вызван конструктор класса FlyingCar" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	FlyingCar fc;		//1. Конструктор Airplane 2. Конструктор Car 3. Конструктор FlyingCar

	return 0;
}