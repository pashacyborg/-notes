#include <iostream>

using namespace std;

/*Методы класса(его функции) реализовываются точно так же, как и обыкновенная функция. 
Функции(методы) класса тоже могут быть шаблонными, тоже могут быть перегружены
Такую же функцию print можно реализовать внутри самого класса, назовем ее smartPrint. Никаких параметров есть писать
не надо, т.к. она автоматом может брать в качестве параметров любые свойства внутри этого класса - заебись.
Обращаться к этой функции так же, как и к свойствам класса - через объект класса с точкой + имя функции. 

Функция smartPrint - часть класса Human. Она может выводить любые свойства внутри этого класса.
У каждого экземпляра свои поля класса. Если попытаться вывести поля первого экземпляра через второй экземпляр - ничего 
не получится.
*/

class Human
{
public:
	string name;
	int age;
	int weight;

	void smartPrint()
	{
		cout << "Имя: " << name << "\nВозраст: " << age << "\nВес: " << weight << endl;
	}
};

void print(Human somePerson)
{
	cout << somePerson.name << endl;
	cout << somePerson.age << endl;
	cout << somePerson.weight << endl;
}

void main()
{
	setlocale(LC_ALL, "ru");
	Human firstHuman;
	firstHuman.name = "Alex";
	firstHuman.age = 25;
	firstHuman.weight = 80;
	//print(firstHuman);
	firstHuman.smartPrint();

	cout << "_______________________" << endl;

	Human secondHuman;
	secondHuman.smartPrint();
}