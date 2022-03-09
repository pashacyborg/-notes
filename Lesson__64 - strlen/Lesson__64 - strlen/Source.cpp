#include <iostream>

using namespace std;

/*Передава указатель в другую функцию, не нужно указывать амперсанд перед ним. Будь то строка char*, 
обычный массив или указатель, который ссылается на переменную а. Просто указываешь test(pa)*/

void strlen_by_me(int& number, const char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
		number++;
}

void test(int* pa)
{
	*pa = 5;
}

void main()
{
	int size = 0;
	cout << size << endl;
	const char* str = "maslyandia";
	//char str2[] = { 'm','a','s','l','o','\0' };		//Если хотим передать строку посимвольно. 
														//Так же в виде массива можно передать обычную строку в двойных кавычках
	strlen_by_me(size, str);
	cout << size << endl;			//Выведет количество символов в строке

	cout << strlen(str) << endl;	//Оригинальная функция strlen

	int a = 10;
	int* pa = &a;
	test(pa);
	cout << a << endl;
}