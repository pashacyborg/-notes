#include <iostream>

using namespace std;

/*Чисто виртуальная функция - пустая функция, без реализации.
Синтаксис: virtual возвращаемое_значение имя_метода(параметры) = 0; 
Абстрактный класс - класс, в котором есть хоть одна чисто виртуальная функция. У абстрактного класса нельзя 
создать объект. 

При создании базового класса с виртуальным методом возникает вопрос: а какова должна быть реализация этого виртуального метода? 
Можно создать абстрактный класс с чисто виртуальным методом - с объявлением метода, но без его реализации. 
Этот метод нужен только для того, чтобы мы могли его переопределять. Нужно название 

В абстрактном классе могут быть нормальные методы с реализацией.

Наследники абстрактного класса обязательно
*/

class Weapon
{
public:
	virtual void Shoot() = 0;
};


class Knife : Weapon
{
public:
	void Shoot() override
	{
		cout << "VJUH" << endl;
	}
};

class Gun : public Weapon
{
public:
	void Shoot() override
	{
		cout << "BUM" << endl;
	}
};


class MachineGun : public Gun
{
public:
	void Shoot() override
	{
		cout << "BUM BUM BUM" << endl;
	}
};


class Bazooka : public Weapon
{
public:
	void Shoot() override
	{
		cout << "BADABUM" << endl;
	}
};

class Player
{
public:
	void Shoot(Weapon* weapon)
	{
		weapon->Shoot();
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	Bazooka bazooka;
	Player player;
	player.Shoot(&bazooka);
	

	return 0;
}