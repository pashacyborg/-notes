#include <iostream>
using namespace std;

/*Включение одного класса в другой - это агрегация или композиция. 
Агрегация - позволяет использовать вложенный класс в других местах(с другими классами). 
Композиция - более строгий вариант агрегации, внутренний класс не может существовать без внешнего и нужен
только для его служебных целей. 
Когда у нас есть два одноименных метода, один из которых находится во внешнем классе, а другой во внутреннем, 
затем через объект внутреннего класса в рамках внешнего метода вызывается внутренний метод - такая конструкция называется
делегирование(один из паттернов проектирования). Мы делегируем функцию внешнего класса внутреннему.


*/

class Cap
{
private:
	string color = "красного";
public:
	string GetTheCap()
	{
		return color;
	}
};

class Alien
{
private:
	Cap cap;
public:
	void InspectAlien()
	{
		cout << "Моя кепка " << cap.GetTheCap() << " цвета" << endl;
	}
};

class Human
{
private:
	class Brain
	{
	private:

	public:
		void Think()
		{
			cout << "Я думаю!" << endl;
		}
	};

	Brain brain;
	Cap cap;

public:
	void Think()
	{
		brain.Think();
	}

	void InspectTheCap()
	{
		cout << "Моя кепка " << cap.GetTheCap() << " цвета" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	Human human;
	human.Think();	//пример композиции: мозг не может без человека. Тут же используется делегирование

	human.InspectTheCap();	//Пример агрегации. Кепка не зависит от класса Human и может использоваться в других классах

	Alien alien;
	alien.InspectAlien();	//Пример агрегации 2. Кепка используется с другим классом

	return 0;
}