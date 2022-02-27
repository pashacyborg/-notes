#include <iostream>

using namespace std;

/*��������� � const � �������� ����� ����� ������� ��������. ��������, ��������� ���������
�� ������������ ������ � ������� � ���������� int* const array - �� ����� �����, ��� � ����� ���������� ������ �� 
��������(�� ��������� ����� ������ � ��). �� �� ����� � ���������� - �� �� ������ �������������� �����������
����������, ������������ ����� ��������.
�����: int* array = new int[10]; �� �� �����, ��� � int* array; array = new int[10]
������� ���� ����� array ��������� const - ������ �������� �� ���������. ���� �� ��������� const ����� int*
(� ���� ������ ���� ������� ��������� ����������� ���������), �� ������� �������� ��������� � ������ ����� ����������
(�� �������� � ���������� size).*/

void FillArray(int* const array, const int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 10;
	}
}

void ShowArray(const int* const array, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << "\t";
	}
}

void main()
{

}