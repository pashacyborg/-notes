#include <iostream>
#include <string>

using namespace std;


void main()
{
	/*char str1[255] = "Hello";
	char str2[255] = " world!";*/

	/*strcat_s(str1, str2);
	cout << str1 << endl;	*/		//� ������� ������� ������������� ������. ��� �������� ������� �� ����� �


	//char result[255]{};				//�������������� ������ ������
	//strcat_s(result, str1);
	//strcat_s(result, str2);
	//cout << result << endl;			//������ 2: ��������� ����������� ������� �����������, ���������� ��������� � ������ ������


	string str1 = "Hello";
	string str2 = "world";
	string str3 = "!";
	string result;

	result = str1 + " " + str2 + str3;	//������ 3: ����� ����� string. 
	cout << result << endl;				//��� ���������� ������ ���� ���������� ���������� string(� �� string.h)
}