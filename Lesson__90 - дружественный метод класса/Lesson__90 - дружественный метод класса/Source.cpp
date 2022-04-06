#include <iostream>
#include <string>

using namespace std;


/*ћетод одного класса может быть дружественным к методу другого класса
ѕор€док расположени€ классов имеет значени€, пока не пон€л какое. 

ѕочему-то компил€тор не видит пол€ weight и color класса apple. ≈сли вынести метод TakeApple вне класса, проблема решитс€.

ƒл€ того, чтобы указать второму классу, что метод первого класса €вл€етс€ дружественным, помимо ключ. слова friend 
и прототипа функции надо указать к какому классу принадлежит данный метод: 
возвращаемое-значение class-name::method-name(параметры) {}

≈ще раз, большие и длинные методы прин€то выносить вне класса, оставл€€ в классе лишь прототип
*/

class Apple;		// ласс Human не знает о классе Apple. ƒл€ того, чтобы метод TakeApple работал, надо прототипировать класс


class Human
{
public:
	void TakeApple(const Apple& apple);		//ƒл€ того, чтобы вынести метод из класса, его нужно прототипировать в самом классе

private:
};

class Apple
{
public:
	friend void Human::TakeApple(const Apple& apple);		// ласс Apple не знает о существовании класса Human
															//т.к класс Apple определен раньше. ƒл€ этого прототипируем два класса
	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
	}

private:
	int weight;
	string color;
};



int main()
{
	setlocale(LC_ALL, "ru");

	Apple grannySmith(228, "green");
	Human bogdan;
	bogdan.TakeApple(grannySmith);
	
	
	return 0;
}

void Human::TakeApple(const Apple& apple)
{
	cout << "ћетод TakeApple:\t" << "weight: " << apple.weight << ", color: " << apple.color << endl;
}