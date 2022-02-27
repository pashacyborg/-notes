#include <iostream>

using namespace std;

/*����� ������ - ��� ���������(����������� ��� ������������), �.�. ��� ������� - ��������� �� ������� 
������� ����� �������. 
���� ��������� ���� ������ �������: array1 = array2, ��� ��� �� �������, ����������� ��������� array1 
�� ������� ������� ������� array2. ������ �� ������ array2 ��������� ��� ���������: array1 � array2
���������� ������ ������, �.�. �� �������� ������ � ������, �� ������� ���������� �������� array1. ����� ����, 
����� �� ����� ������� ���� ������� � main �������� delete[] array1, delete[] array2 - � ��� ���������
���������, ��������� ����� ������� �������� � ��� ��� ��� �� ������� ���������. 
����: ������ ���� array1 = array2 �� �������� ������.

����������� �������� �������� ������� ����: array1[i] = array2[i] � ������� �����;

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

	cout << "������ ������ =\t";
	ShowArray(array1, size);
	cout << endl << endl;
	cout << "������ ������ =\t";
	ShowArray(array2, size);

	/////////////////////////////////////////////

	/*array1 = array2;
	cout << endl << endl << endl;
	cout << "������ ������ =\t";
	ShowArray(array1, size);			//�����, � �� �����������
	cout << endl << endl;
	cout << "������ ������ =\t";
	ShowArray(array2, size);*/

	/////////////////////////////////////////////

	for (int i = 0; i < size; i++)
	{
		array1[i] = array2[i];
	}
										//����������� �������
	cout << endl << endl << endl;
	cout << "������ ������ =\t";
	ShowArray(array1, size);		
	cout << endl << endl;
	cout << "������ ������ =\t";
	ShowArray(array2, size);
	
	delete[] array1;
	delete[] array2;
	
	array1 = NULL;
}