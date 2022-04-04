#include <iostream>

using namespace std;


/*Дружественная функция по отношению к классу называется такая фукнция, которая хоть и не является членом класса
(находится вне области видимости класса), имеет доступ к закрытым полям класса(из private или protected)

Для того, чтобы фукнция стала дружественной, ее нужно объявить в области видимости класса с ключевым словом friend.
Т.е friend прототип-функции

Таким образом, мы можем работать с приватными полями с помощью фукнции ВНЕ класса. 

Указатель this в дружественных функциях не работает, т.к. не является членом класса. Чтобы получить доступ к полям
класса надо обращаться через объект

Объявить дружественную фукнцию можно в любом месте класса(Public, private, protected)

Одна фукнция может быть дружественна сразу к нескольким классам
*/
class Test;


class Point
{
private:
	int x;
	int y;

	friend void ChangeXandY(Point& object, Test& Data, int valueX, int valueY);
public:
	Point()
	{
		x = 0;
		y = 0;
		cout << this << "\tу этого объекта вызывался конструктор класса" << endl;
	}

	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
		cout << this << "\tу этого объекта вызывался конструктор класса" << endl;
	}


	void Print()
	{
		cout << endl << "X = " << this->x << "\t" << "Y = " << this->y << "\t\t";
	}

};


class Test
{
private:
	int dataField = 0;
public:
	void Print()
	{
		cout << "DATA = " << dataField << endl;
	}

	friend void ChangeXandY(Point& object, Test& Data, int valueX, int valueY);
};


void ChangeXandY(Point& object, Test& Data, int valueX, int valueY)
{
	
	object.x = valueX;
	object.y = valueY;
	Data.dataField = 100;			//Имеет доступ к таким полям, которые не получить через объект класса
}


int main()
{
	setlocale(LC_ALL, "ru");
	Point object1(10, 2);
	Test miniobject;

	object1.Print();

	ChangeXandY(object1, miniobject, 11, 228);
	object1.Print();
	miniobject.Print();
	

	return 0;
}