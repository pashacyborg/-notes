#include <iostream>

using namespace std;

/*Ћюбой массив - это указатель(статический или динамический), т.к. им€ массива - указатель на нулевой 
элемент этого массива. 
≈сли присвоить один массив другому: array1 = array2, все что мы сделаем, перезапишем указатель array1 
на нулевой элемент массива array2. —ейчас на массив array2 указывают два указател€: array1 и array2
ѕроизойдет утечка пам€ти, т.к. мы потер€ем доступ к данным, на которые изначально указывал array1.  роме того, 
когда мы будем чистить наши массивы в main командой delete[] array1, delete[] array2 - у нас крашнетс€
программа, поскольку после первого удалени€ у нас все еще не нулевой указатель. 
»тог: запись вида array1 = array2 не копирует массив.

 опирование массивов делаетс€ записью вида: array1[i] = array2[i] с помощью цикла;

*/

void FillArray(int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

void ShowArray(const int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
}

void main()
{
	setlocale(LC_ALL, "ru");
	int* array1;
	int* array2;
	int size = 10;

	array1 = new int[size];
	array2 = new int[size];

	FillArray(array1, size);
	FillArray(array2, size);

	cout << "ѕервый массив =\t";
	ShowArray(array1, size);
	cout << endl << endl;
	cout << "¬торой массив =\t";
	ShowArray(array2, size);

	/////////////////////////////////////////////

	/*array1 = array2;
	cout << endl << endl << endl;
	cout << "ѕервый массив =\t";
	ShowArray(array1, size);			//фигн€, а не копирование
	cout << endl << endl;
	cout << "¬торой массив =\t";
	ShowArray(array2, size);*/

	/////////////////////////////////////////////

	for (int i = 0; i < size; i++)
	{
		array1[i] = array2[i];
	}
										// опирование массива
	cout << endl << endl << endl;
	cout << "ѕервый массив =\t";
	ShowArray(array1, size);		
	cout << endl << endl;
	cout << "¬торой массив =\t";
	ShowArray(array2, size);
	
	delete[] array1;
	delete[] array2;
	
	array1 = NULL;
}