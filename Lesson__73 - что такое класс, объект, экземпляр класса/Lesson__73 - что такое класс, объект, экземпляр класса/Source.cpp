#include <iostream>
#include <string>
using namespace std;

/*Класс - пользовательский тип данных. Тип данных, который мы можем написать сами
Синтаксис: class class-name {} . Слово class - ключевое

Для названия класса нужно выбирать осмысленное значение. В конце класса не пишутся круглые скобки, он не возвращает никакое значение

Grib maslenok - создал переменную maslenok типа Grib. Либо объект(экземпляр) maslenok класса Grib
int a - создали объект а на основе класса int(грубо говоря), который хранит целочисленные значения

Класс - шаблон, который описывает переменную. Экземпляр такого класса - объект
Свойства класса пишутся внутри тела класса. Примитивные типы(int, char и тд), либо другие классы могут являться такими свойствами

При использовании строки не забывай подключить библиотеку <string>
Перед использованием свойств, перед ними надо поставить модификатор доступа - public: или private:

Свойства, которые содержат какую-то характеристику(рост, вес, объем двигателя и тд) - называются полями класса(int age - это поле)

Классы удобно использовать для баз данных, в сравнении с теми же массивами(читабельность кода улучшается за счет именования свойств, 
нежели обращение к какому-то из свойств через индекс массива mas[0][1])


*/

class Grib
{
public:
	string name;						
	int age;
	int weight;
};

class Coordinate
{
public:
	int x;
	int y;
	int z;
};

int main()
{
	Grib type1;
	type1.name = "maslenok oiler";
	type1.age = 5;
	type1.weight = 500;
	
	cout << type1.name << endl;
	cout << type1.age << endl;
	cout << type1.weight << endl;

	cout << "_________________________________" << endl;

	Grib type2;
	type2.name = "maslenok natural";
	type2.age = 6;
	type2.weight = 300;

	cout << type2.name << endl;
	cout << type2.age << endl;
	cout << type2.weight << endl;

	cout << "_________________________________" << endl;

	Coordinate dot1;
	dot1.x = 4;
	dot1.y = 2;
	dot1.z = 5;

	cout << dot1.x << endl;
	cout << dot1.y << endl;
	cout << dot1.z << endl;

	return 0;
}