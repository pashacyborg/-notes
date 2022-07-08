#include <iostream>
#include <string>

using namespace std;

/*ѕри наследовании у класса-предка могут быть доступны несколько методов с одинаковым названием. 
¬ таком случае, компил€тор не сможет самосто€тельно разобратьс€ какой метод надо вызвать. 

–ешение: приведение типов. Ќеобходимо привести объект класса-наследника к такому типу класса родител€, метод
которого мы хотим использовать. 

—интаксис: ((type)object).method();
*/

class Car
{
public:
	void Use()
	{
		cout << "я еду!" << endl;
	}
};

class Airplane
{
public:
	void Use()
	{
		cout << "я лечу!" << endl;
	}
};

class FlyingCar : public Car, public Airplane
{
	
};

int main()
{
	setlocale(LC_ALL, "ru");

	FlyingCar fc;
	((Car)fc).Use();	//я еду!
	((Airplane)fc).Use();	//я лечу!

	return 0;
}