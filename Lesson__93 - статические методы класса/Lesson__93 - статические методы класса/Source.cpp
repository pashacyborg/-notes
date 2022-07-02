#include <iostream>
#include <string>

using namespace std;

/*Геттеры и сеттеры нужны для того, чтобы наш класс не поломали, не изменили критически важные переменные, 
но в то же время чтобы люди имели возможность получить значения этих полей, выстраивая логику программы.

По дефолту в статическом методе нельзя работать со статическими полями, но это можно изменить, если через 
параметр передать ссылку на конкретный объект. По дефолту статические методы работают только со статическими
полями. 
*/

class Apple
{
private: 
	//Чтобы иметь возможность получить значение этого поля по имени класса(а не через объект),
	//нам нужен статический метод, возвращающий эту переменную.
	static int Count;	
	int id;
					
public:
	int weight;
	string color;

	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
		++Count;
		id = Count;
	}

	static void ChangeColor(Apple& apple, string color)
	{
		apple.color = color;
	}

	static int GetCount()
	{
		return Count;
	}

	void PrintInfo()
	{
		cout << "Яблоко №" << id << ", вес: " << weight << ", цвет: " << color << endl;
	}

	void ChangeColorStandard(string color)
	{
		this->color = color;
	}


};

int Apple::Count = 0;

int main()
{
	setlocale(LC_ALL, "ru");
	Apple apple1(100, "yellow");
	Apple apple2(200, "green");
	apple1.PrintInfo();
	apple2.PrintInfo();

	apple2.ChangeColor(apple2, "red");	//Вызваем статический метод для конкретного объекта класса, меняя
	apple2.PrintInfo();					//нестатическую переменнную в нем.

	Apple::ChangeColor(apple2, "purple");		//Сработает точно также
	apple2.PrintInfo();		

	apple2.ChangeColorStandard("darkblue"); //Используем обычный метод для смены цвета. Ссылку на объект передавать не надо.
	apple2.PrintInfo();
	

	return 0;

}