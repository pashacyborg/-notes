#include <iostream>

using namespace std;

/*�������� ��������� � ������ �������, �� ����� ��������� ��������� ����� ���. ���� �� ������ char*, 
������� ������ ��� ���������, ������� ��������� �� ���������� �. ������ ���������� test(pa)*/

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
	//char str2[] = { 'm','a','s','l','o','\0' };		//���� ����� �������� ������ �����������. 
														//��� �� � ���� ������� ����� �������� ������� ������ � ������� ��������
	strlen_by_me(size, str);
	cout << size << endl;			//������� ���������� �������� � ������

	cout << strlen(str) << endl;	//������������ ������� strlen

	int a = 10;
	int* pa = &a;
	test(pa);
	cout << a << endl;
}