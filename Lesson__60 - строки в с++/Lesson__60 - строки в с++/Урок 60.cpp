#include <iostream>

using namespace std;

/*Строка, где что либо записано - массив символов char. В конце каждой строки есть "нуль терминатор" - 
символ конца строки \0 . Строка пишется в двойных кавычках, символ в одинарных. Если символ типа char 
обернуть в двойные кавычки, то компилятор подумает, что перед нами строка - символ + нуль терминатор.
*/

void main()
{
	setlocale(LC_ALL, "ru");

	char string[] = "Hello world!";
	cout << string << endl;

	char string2[] = { 'H','e','l','l','o',' ','w','o','r','l','d','!',':',')','\0' };		//Другой способ инициализации
	cout << string2 << endl;

	cout << strlen(string) << endl;
	cout << strlen(string2) << endl;
}