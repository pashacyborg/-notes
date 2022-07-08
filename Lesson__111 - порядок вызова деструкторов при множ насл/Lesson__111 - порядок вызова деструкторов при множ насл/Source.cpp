#include <iostream>
#include <string>

using namespace std;

/*Деструкторы будут вызваны в противоположном порядке вызова конструкторов класса. 
*/


class Car
{
public:
	Car()
	{
		cout << "Вызван конструктор класса Car" << endl;
	}

	~Car()
	{
		cout << "Вызван деструктор класса Car" << endl;
	}
};

class Airplane
{
public:
	Airplane()
	{
		cout << "Вызван конструктор класса Airplane" << endl;
	}

	~Airplane()
	{
		cout << "Вызван деструктор класса Airplane" << endl;
	}
};

class FlyingCar : public Airplane, public Car
{
public:
	FlyingCar()
	{
		cout << "Вызван конструктор класса FlyingCar" << endl;
	}

	~FlyingCar()
	{
		cout << "Вызван деструктор класса FlyingCar" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	FlyingCar fc;			//1.Деструктор класса Flying car 2. Деструктор класса Car 3. Деструктор класса Airplane

	return 0;
}