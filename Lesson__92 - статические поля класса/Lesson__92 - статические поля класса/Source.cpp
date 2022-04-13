#include <iostream>

using namespace std;


/*Переменная static общая для всех объектов. Изменив такую переменную через один объект, при обращении к ней
через другой объект мы увидим эти изменения. 
К переменной типа static можно обращаться напрямую через класс, а не через объект + точка.

Прежде чем использовать статическую переменную, ее надо инициализировать: тип-данных-переменной__class-name::variable-name = значение.
Инициализировать статическое поле нужно ВНЕ класса: int Apple::count = 0;

static - это модификатор

С помощью static можно просто сгенерировать уникальный id для объекта класса. 
Объекты могут иметь одинаковые поля, быть практически идентичными. id позволяет различать такие объекты
*/

class Apple
{
public:
	static int count;

	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
		count++;
		id = count;
	}

	int GetId()
	{
		return id;
	}

private:
	int weight;
	string color;
	int id;
};

int Apple::count = 0;	//Инициализация переменной count вне класса
//int Apple::number = 0;

int main()
{
	Apple apple(50, "red");
	Apple apple2(100, "green");
	Apple apple3(150, "yellow");

	cout << Apple::count << endl;
	cout << apple2.count << endl;		//Как бы мы не обращались к полю count, значение будет одинаковым(в данном случае 3)

	cout << endl << endl;
	cout << apple.GetId() << endl;		//Выведет 1
	cout << apple2.GetId() << endl;		//2
	cout << apple3.GetId() << endl;		//3

	return 0;
}