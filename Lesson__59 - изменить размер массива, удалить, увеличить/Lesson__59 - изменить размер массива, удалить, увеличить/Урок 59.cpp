#include <iostream>

using namespace std;

/*Для того, чтобы добавить/убрать элемент в массиве, нам нужно создать новый массив с нужным количеством элементов,\
вручную скопировать данные с первого массива, а затем удалить первый массив и переадресовать указатель
на второй массив
Конструкция вида int*& arr - ссылка на указатель, необходима для того, чтобы внутри функции мы могли
поменять адрес памяти, на который ссылается указатель и вернуть этот адрес в изначальный массив(указатель)
из функции main
Если же мы передаем в функцию просто указатель на массив - int* arr, то мы можем взаимодействовать только
с данными массива, но не с его адресом(т.к. вместо изначального указателя в параметрах функции создается
ноавя переменная-указатель, которая указывает на тот же массив.

Если мы используем ссылку на указатель, мы передаем в функцию адрес изначального указателя, который 
указывает на динамический массив.
Записи вида arr[++i] и arr[i + 1] координально отличаются и разница здесь не только в префиксном
инкременте. Главное то, что первая запись будет увеличивать счетчик i внутри цикла, а вторая будет
лишь добавлять к индексу единицу*/


void FillMass(int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

void ShowMass(const int* const arr, const int size)
{
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}

	cout << endl;
}

void push_back(int*& arr, int& size, const int value)		//Добавляет нужный элемент в конец нашего массива
{
	int* arr2 = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		arr2[i] = arr[i];
	}

	delete[] arr;

	arr2[size] = value;			//добавь 6-му элементу значение value
	size++;			//В массиве теперь 6 элементов(0,1,2,3,4,5)

	arr = arr2;			//меняем адрес изначального указателя на 1 элемент нового массива
}

void pop_back(int*& arr, int& size, const int value)			//Удаляет последний элемент из нашего массива
{
	int* arr3 = new int[--size];		//В новом массиве будет на одну ячейку меньше
	
	for (int i = 0; i < size; i++)
	{
		arr3[i] = arr[i];
	}

	delete[] arr;

	arr = arr3;
}

void push_front(int*& arr, int& size, const int value)		//Добавляет нужый элемент в начало нашего массива
{
	int* arr4 = new int[++size];		//В новом массиве будет на одну ячейку больше

	for (int i = 0; i < size; i++)
	{
		arr4[i + 1] = arr[i];		//arr4[++i] не сработает, т.к. меняет i внутри цикла. Такая запись - нет
	}
	
	delete[] arr;

	arr4[0] = value;
	arr = arr4;
}

void pop_front(int*& arr, int& size, const int value)		//удаляет первый элемент из нашего массива
{
	int* arr5 = new int[--size];		

	for (int i = 0; i < size; i++)
	{
		arr5[i] = arr[i + 1];	
	}

	delete[] arr;

	arr = arr5;
}


void main()
{
	int size = 5;
	int* arr = new int[size];

	FillMass(arr, size);
	ShowMass(arr, size);

	int value = 228;
	push_back(arr, size, value);
	ShowMass(arr, size);

	pop_back(arr, size, value);
	ShowMass(arr, size);

	push_front(arr, size, value);
	ShowMass(arr, size);

	pop_front(arr, size, value);
	ShowMass(arr, size);
}