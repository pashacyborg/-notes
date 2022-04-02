#include <iostream>

using namespace std;

/*При реализации перегрузки операторов рассуждать: вот мне нужно сравнить две точки. В каких случаях эти точки будут равными?
Если их поля с координатами х y равы между собой. 
Результат равенства - либо true, либо false. 

Оператора == по умолчанию нет
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
	{/*
		if (this->x == other.x && this->y && other.y)
		{
			return true;
		}
		else
		{
			return false;
		}*/

		return (this->x == other.x && this->y && other.y);	//Выражение содержит только логические операции. Вернет true/false
	}

	bool operator != (const Point& other)
	{
		return !(this->x == other.x && this->y && other.y);
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
	Point a(1, 2);
	Point b(1, 2);
	
	bool result1 = a == b;	//Вернется true/false
	bool result2 = a != b;

	return 0;
}