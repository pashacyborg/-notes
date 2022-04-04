#include <iostream>

using namespace std;


/*Перегрузка оператора индексирования используется в таком контейнере для данных, как вектор в библиотеке STL.
Ссылка создает связь между функциями. Если тип возвращаемого значения ссылка на объект, то мы можем из внешней
функции изменить поля класса по ссылке
*/

class TestClass
{
public:
	int& operator [] (int index)
	{
		return mas[index];
	}

private:
	int mas[10]{ 228,1488,42,4,21,8,7,23,88,9 };
};

int main()
{
	TestClass object1;
	cout << object1[1] << endl;
	cout << object1.operator[](4) << endl;		//Выведет 21

	object1[4] = 1337;
	cout << object1[4] << endl;					//Выведет 1337

	return 0;
}