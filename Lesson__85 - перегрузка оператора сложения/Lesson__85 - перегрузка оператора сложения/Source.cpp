#include <iostream>
using namespace std;

/*Поскольку при перегрузке оператора + наш перегруженный оператор должен сложить два объекта и по сути
вернуть новый объект, в типе возвращаемого значения функции надо писать Point, а не Point& и тд 

В этом классе не реализован конструктор копирования или конструктор перемещения. Если бы мы работали с динамической
памятью в классе Point, у нас бы возникла ошибка на этапе Point a = b + c;(а именно в моменте присваивания)

*/

class Point
{
private:
	int x;
	int y;

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

	bool operator == (const Point& other)	
	{
		return (this->x == other.x && this->y && other.y);	//Выражение содержит только логические операции. Вернет true/false
	}

	bool operator != (const Point& other)
	{
		return !(this->x == other.x && this->y && other.y);
	}

	Point operator + (const Point& other)
	{
		Point temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;

		return temp;
	}

	void Setx(int x)
	{
		this->x = x;
	}

	void Sety(int y)
	{
		this->y = y;
	}

	int Getx()
	{
		return x;
	}

	int Gety()
	{
		return y;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	Point a(10, 2);
	Point b(4, 3);

	//Point c = a + b;		//Более сокращенная запись
	Point c = a.operator+(b);
	

	return 0;
}
