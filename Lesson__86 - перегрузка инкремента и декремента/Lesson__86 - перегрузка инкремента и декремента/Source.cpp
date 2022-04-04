#include <iostream>

using namespace std;

/*Перегрузка нужна для того, чтобы совершать операции над пользовательскими типами данных, которые изначально
для этого не предназначены(например, инкремент есть для примитивных типов данных, а для класса его нужно создавать индивидуально под задачу)

Реализация префиксного инкремента и постфиксного отличается тем, что в постфиксной перегруженный оператор принимает параметр
А так же тем, что мы возвращаем не текущий объект, а чистую неизмененную копию текущего объекта(без инкремента).
Таким образом, поля текущего объекта были увеличены, но возвращается копия, в которой поля не увеличины. Поэтому 
в нашей операции присваивания поля объекта d не увеличатся, а поля объекта с увеличатся, но уже после операции присваивания
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

	Point& operator ++ ()
	{
		this->x++;
		this->y++;

		return *this;
	}

	Point& operator ++ (int value)
	{
		Point temp(*this);
		this->x++;
		this->y++;

		return temp;
	}

	Point& operator -- ()
	{
		this->x--;
		this->y--;

		return *this;
	}

	Point& operator -- (int value)
	{
		Point temp(*this);
		this->x--;
		this->y--;

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
				
	Point c = a.operator++();
	Point d = c.operator++(5);		//Это костыль, но мы должны передавать какой-то рандомный int параметр для того, 
									//чтобы компилятор смог отличить префиксный инкремент от постфиксного
	/*Point c = ++a;
	Point d = c++;*/

	Point e = --d;
	Point f = e--;


	return 0;
}