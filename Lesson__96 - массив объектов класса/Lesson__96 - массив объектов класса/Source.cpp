#include <iostream>
#include <string>
using namespace std;

/*����� - ���������������� ��� ������. 
���� �� �������� ����������� �� ���������, � �������� ������ ����������� � �����������, �� �� ������ ������� "������" ������
����������� ������� �������� � ���, ��� ����������� � ������-�� �������� ������ �������(�������), �� �����
�������� ������ � ����� � ������� ����� �������.
������� ������������� ������� �� ������������ � ���, ��� �� ����� �������� ���������� ����� ������ ��� ������ � �������� ������

*/

class Pixel
{
private:
	int r;
	int g;
	int b;
public:
	Pixel()
	{
		r = g = b = 0;
	}

	Pixel(int r, int g, int b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	}


	string GetInfo()
	{
		return "Pixel: r = " + to_string(r) + ", g = " + to_string(g) + ", b = " + to_string(b);
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	const int SIZE = 5;
	//����������� ������ v1
	Pixel arr[SIZE];//������ � �������� ���������� ����� �������
	arr[0] = Pixel(10, 20, 30);	//������ ����������� �������� ����� ������� ����� ����������� � ����������
	cout << arr[0].GetInfo() << endl;
	cout << arr[1].GetInfo() << endl;	//r = 0, g = 0, b = 0;
	cout << endl << endl;
	//����������� ������ v2
	Pixel arr2[SIZE]
	{
		Pixel(12, 13, 200),
		Pixel(15, 30, 15),
		Pixel(21, 13, 255),
		Pixel(12, 144, 15),
		Pixel(155, 13, 111),
	};
	cout << arr2[0].GetInfo() << endl;
	cout << endl << endl;

	//������������ ������
	Pixel* arr3 = new Pixel[SIZE];
	arr3[0] = Pixel(228, 228, 228);
	cout << arr3[0].GetInfo() << endl;
	cout << arr3[1].GetInfo() << endl;
	return 0;
}