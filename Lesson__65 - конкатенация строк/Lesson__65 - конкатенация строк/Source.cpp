#include <iostream>
#include <string>

using namespace std;


void main()
{
	/*char str1[255] = "Hello";
	char str2[255] = " world!";*/

	/*strcat_s(str1, str2);
	cout << str1 << endl;	*/		//К первому массиву приклеивается второй. Так работает функция из языка С


	//char result[255]{};				//Инициализируем массив нулями
	//strcat_s(result, str1);
	//strcat_s(result, str2);
	//cout << result << endl;			//Способ 2: сохраняем изначальные массивы нетронутыми, записываем результат в третий массив


	string str1 = "Hello";
	string str2 = "world";
	string str3 = "!";
	string result;

	result = str1 + " " + str2 + str3;	//Способ 3: через класс string. 
	cout << result << endl;				//Для корректной работы надо подключить библиотеку string(а не string.h)
}