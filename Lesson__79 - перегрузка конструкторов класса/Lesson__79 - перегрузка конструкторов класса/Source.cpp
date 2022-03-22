#include <iostream>

using namespace std;

/*Перегрузка конструкторов класса похожа на полиморфизм в ООП. 
Полиморфизм - разное поведение, в зависимости от разных ситуаций

Компилятор не будет создавать конструктор класса, если мы сделали это сами(явно)
Мы можем создавать несколько перегрузок для конструктора класса(т.е. разные вариации конструктора класса, с одинаковым
именем, но с разными входными параметрами и/или реализацией)

Еще раз, мы можем для нашего класса написать сколко угодно таких конструкторов
*/

class Coordinate
{
private:
	int x;
	int y;

public:
	Coordinate()
	{
		x = 0;
		y = 0;
	}

	Coordinate(int valueX, int valueY)
	{
		x = valueX;
		y = valueY;
	}

	Coordinate(int valueX, char c)
	{
		if (c == 'x')
		{
			x = valueX;
			y = 228;
		}
		else if (c == 'y')
		{
			x = valueX;
			y = 1337;
		} 
		else
		{
			x = valueX;
			y = 1488;
		}
	}

	int GetX()
	{
		return x;
	}

	void SetX(int valueX)
	{
		x = valueX;
	}

	int GetY()
	{
		return y;
	}

	void SetY(int valueY)
	{
		y = valueY;
	}

	void Print()
	{
		cout << "x = " << x << "\ny = " << y << endl << endl;
	}
};

int main()
{
	Coordinate pointOne;
	pointOne.Print();

	Coordinate pointTwo(15, 228);
	pointTwo.Print();

	Coordinate pointThree(10, 'z');		//Можно сделать конструктор с bool, с char, с чем угодно
	pointThree.Print();

	return 0;
}