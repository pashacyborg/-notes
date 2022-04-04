#include <iostream>

using namespace std;


/*���������� ��������� �������������� ������������ � ����� ���������� ��� ������, ��� ������ � ���������� STL.
������ ������� ����� ����� ���������. ���� ��� ������������� �������� ������ �� ������, �� �� ����� �� �������
������� �������� ���� ������ �� ������
*/

class TestClass
{
public:
	int& operator [] (int index)
	{
		return mas[index];
	}

private:
	int mas[10]{ 228,1488,42,4,21,8,7,23,88,9 };
};

int main()
{
	TestClass object1;
	cout << object1[1] << endl;
	cout << object1.operator[](4) << endl;		//������� 21

	object1[4] = 1337;
	cout << object1[4] << endl;					//������� 1337

	return 0;
}