#include <iostream>

using namespace std;

/*������, ��� ��� ���� �������� - ������ �������� char. � ����� ������ ������ ���� "���� ����������" - 
������ ����� ������ \0 . ������ ������� � ������� ��������, ������ � ���������. ���� ������ ���� char 
�������� � ������� �������, �� ���������� ��������, ��� ����� ���� ������ - ������ + ���� ����������.
*/

void main()
{
	setlocale(LC_ALL, "ru");

	char string[] = "Hello world!";
	cout << string << endl;

	char string2[] = { 'H','e','l','l','o',' ','w','o','r','l','d','!',':',')','\0' };		//������ ������ �������������
	cout << string2 << endl;

	cout << strlen(string) << endl;
	cout << strlen(string2) << endl;
}