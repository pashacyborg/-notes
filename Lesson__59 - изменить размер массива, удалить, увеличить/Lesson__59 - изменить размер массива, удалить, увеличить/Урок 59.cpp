#include <iostream>

using namespace std;

/*��� ����, ����� ��������/������ ������� � �������, ��� ����� ������� ����� ������ � ������ ����������� ���������,\
������� ����������� ������ � ������� �������, � ����� ������� ������ ������ � �������������� ���������
�� ������ ������
����������� ���� int*& arr - ������ �� ���������, ���������� ��� ����, ����� ������ ������� �� �����
�������� ����� ������, �� ������� ��������� ��������� � ������� ���� ����� � ����������� ������(���������)
�� ������� main
���� �� �� �������� � ������� ������ ��������� �� ������ - int* arr, �� �� ����� ����������������� ������
� ������� �������, �� �� � ��� �������(�.�. ������ ������������ ��������� � ���������� ������� ���������
����� ����������-���������, ������� ��������� �� ��� �� ������.

���� �� ���������� ������ �� ���������, �� �������� � ������� ����� ������������ ���������, ������� 
��������� �� ������������ ������.
������ ���� arr[++i] � arr[i + 1] ������������ ���������� � ������� ����� �� ������ � ����������
����������. ������� ��, ��� ������ ������ ����� ����������� ������� i ������ �����, � ������ �����
���� ��������� � ������� �������*/


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

void push_back(int*& arr, int& size, const int value)		//��������� ������ ������� � ����� ������ �������
{
	int* arr2 = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		arr2[i] = arr[i];
	}

	delete[] arr;

	arr2[size] = value;			//������ 6-�� �������� �������� value
	size++;			//� ������� ������ 6 ���������(0,1,2,3,4,5)

	arr = arr2;			//������ ����� ������������ ��������� �� 1 ������� ������ �������
}

void pop_back(int*& arr, int& size, const int value)			//������� ��������� ������� �� ������ �������
{
	int* arr3 = new int[--size];		//� ����� ������� ����� �� ���� ������ ������
	
	for (int i = 0; i < size; i++)
	{
		arr3[i] = arr[i];
	}

	delete[] arr;

	arr = arr3;
}

void push_front(int*& arr, int& size, const int value)		//��������� ����� ������� � ������ ������ �������
{
	int* arr4 = new int[++size];		//� ����� ������� ����� �� ���� ������ ������

	for (int i = 0; i < size; i++)
	{
		arr4[i + 1] = arr[i];		//arr4[++i] �� ���������, �.�. ������ i ������ �����. ����� ������ - ���
	}
	
	delete[] arr;

	arr4[0] = value;
	arr = arr4;
}

void pop_front(int*& arr, int& size, const int value)		//������� ������ ������� �� ������ �������
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