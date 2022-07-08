#include <iostream>
#include <string>

using namespace std;

/*У класса-наследника может быть несколько предков, которые указываются через запятую
Синтаксис: class-child : modifier-name class-parent1, modifier2-name class parent2 
*/

class Car
{
public:
	string cspeed = "500 km/h";

	void Drive()
	{
		cout << "Я еду!" << endl;
	}
};

class Airplane
{
public:
	string fspeed = "150 km/h";

	void Flying()
	{
		cout << "Я лечу!" << endl;
	}
};

class FlyingCar : public Car, public Airplane
{
public:

};

int main()
{
	setlocale(LC_ALL, "ru");

	FlyingCar fc;
	fc.Drive();	//Оба метода вызовутся, т.к. оба они принадлежат родителям класса FlyingCar
	fc.Flying();

	Car* ptrc = &fc;	//Обе конструкции корректны, т.к. и тот и тот класс является базовым для FlyingCar
	Airplane* ptra = &fc;
	return 0;
}