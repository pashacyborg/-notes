#include <iostream>
#include <string>

using namespace std;

/*НАследование, синтаксис: class_name : public/private/protected class_name
Наследование - механизм, при котором один объект может наследовать свойства другого объекта. Объект, который
получает унаследованные свойства может иметь собственные свойства(должен иметь, иначе смысл наследования теряется).
Базовый класс - тот, от которого наследуются. 
Дочерний класс - тот класс, который унаследовал свойства базового класса.

Наследование сокращает количество дублируемого кода, количество ошибок на правку такого кода.
Постоянное дублирование кода у классов затрудняет реализацию полиморфизма, а также делает невозможным
хранить в одной коллекции объекты разных классов. 

Наследование решает все эти проблемы
*/

class Human
{
public:
	string name;

	void SetSurname(string surname)
	{
		this->surname = surname;
	}

	string GetSurname()
	{
		return surname;
	}

private:
	string surname;	//Поле приватное, через объект не добраться. Используем геттеры и сеттеры
};

class Student : public Human
{
public:
	string group;

	void Learn()
	{
		cout << "Я учусь!" << endl;
	}
};

class CorrespondenceStudent : public Student
{
public:
	void Learn()
	{
		cout << "Я нихуя не учусь, но оценки получаю!" << endl;
	}
};

class Emplloyee : public CorrespondenceStudent	//Класс Emplloyee(работник) включает в себя все прерыдущие класса и их поля
{
public:
	string subject;
};

int main()
{
	setlocale(LC_ALL, "ru");

	Student st;
	st.name = "Petya";	//Получили доступ к полю класса Human
	cout << st.name << endl;
	st.Learn();

	CorrespondenceStudent cst;
	cst.Learn();	//Если не переопределить метод Learn у заочника, будет вызываться метод Learn очника

	Emplloyee emp;
	emp.SetSurname("Ivanovich");
	cout << emp.GetSurname() << endl;



	

	
	return 0;
}