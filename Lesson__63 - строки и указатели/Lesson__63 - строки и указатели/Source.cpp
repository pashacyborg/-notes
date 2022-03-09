#include <iostream>

using namespace std;

/*������ � ����������� ���� - ������������ ������. ������ ���� char, ������� ������������� \0
����� ����� ����������� � �������� ����� ��, ��� ����� ����� ����������� � ������������� ��������� ������ ������� ���� ������.
�.�. ������ ��� ������(��� �������� ��������� �� ������ ������ � ������), �� �������� ������, �� �����
�������� �� ������, � ��������� ���� char � � ����� ��������� ����������� ������ ��� ������. ��� �����
����� ������ ��������� �� ������� ������ ���� ��������� const: const char* pointer = "maslo";

�.�. ������ ��� ������, �� ��� � ��� ������ � ������������� ���������, �� ����� �������� ����� ��� �������
� ������������ ������

���� ���� ������ ��������� ��������� ������� � ������ - ����� ��� ����� ������ ����������, ��� ������ ���������
����� ��������� �� ������ ������� ����� ������: const char* strArr[] = {"stroka1", "stroka2", "stroka3"};
���� �� ����� ���� ������ ����� ���������(�� �����: ���� ��� ���������), ����� char ���� ������� const

�� ��� �� ����� ���������� ������ � ������ �������. ��� ������������� ��������� ����������� ��������� ������,
�.�. � ����� ������ ������ ���� ������������ - ������������� ���� \0.

*/

void GiveMeStroke(char* str);

void main()
{
	char symbol = 'H';			//������

	char str[] = "Hello";		//������ ��������


	const char* string = "Maslo";			//��������� �� ������ ��������(�� �� �����, �.�. str ���� ��������� �� ������ ������� ����� ������)
											//��������� ������ � ���� ����� ������� �������� ����������� ������(������ ��� ������ = ������)
	cout << string << endl;				//� ��� ������� - ����� ��� ������� ��������.


	cout << endl << endl << endl;
	

	char* string2 = str;			//��������� string2 ������ � ���� ����� ������� �������� ������ str
	cout << string2 << endl;


	cout << endl << endl << endl;
	

	const char* strArr[] = { "stroka1", "stroka2", "stroka3" };
	strArr[0] = str;			//�� ��������� �������� �������� ������� ���������� ����� �� ������ str
								//������ ������� ��������� ��������� �� �� ������ ������� ������ "stroka1"
	for (int i = 0; i < 3; i++) //� �� ������ ������� ������ "Hello". ��� �������
	{
		cout << strArr[i] << endl;
	}


	cout << endl << endl << endl;


	GiveMeStroke(str);
}

void GiveMeStroke(char* str)
{
	cout << strlen(str) << endl;		//� ������ Hello - 5 �������� + ������ ����� ������.
}

