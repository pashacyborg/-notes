#include <iostream>

using namespace std;


/*ƒружественный класс - на случай, если одного дружественного метода недостаточно и нужно сделать все методы
одного класса дружественными по отношению к другому классу. Ёто в свою очередь нарушает инкапсул€цию класса, 
к приватным пол€м которого мы получаем доступ. “.е. кто-то другой из программистов с помощью метода сможет 
легко переопределить приватные пол€ с помощью дружественного класса - это опасно. Ѕез надобности таким заниматьс€ не надо

ѕреимущества ссылок и указателей. „ерез них можно передавать данные без копировани€, т.е. без занимани€ излишней пам€ти. 
ѕередавать объект класса по значению очень затратно. 

ƒл€ того, чтобы получить доступ к приватным пол€м класса Human »« класса Apple, нужно в классе Human указать friend Apple. 
“.е. дружественность работает так: если класс €блока есть в друзь€х у Human, тогда через класс €блока можно
получить доступ к пол€м Human. 
*/


class Apple;		

class Human
{
public:
	void TakeApple(const Apple& apple);	

	void EatApple(const Apple& apple)
	{
		//“еперь и отсюда мы можем получить доступ к пол€м Apple, 
		//а не только из одного метода
	}
private:
	int maslo;
};

class Apple
{
public:
	friend Human;
									
	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
	}

	void Maslo(const Human& human)
	{
		
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

