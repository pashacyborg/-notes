#include <iostream>
//#include <string>

using namespace std;
/*��� ���������� ���������� � ���� ������������ ���� � ����������� .h
����� - ��� ��� �������� �������(����������). � cpp ���� - ��� ���������� ����� �������
#pragma once - ������� � ���, ��� ���, ��� �������� � ������ ����� ����� �������� � ���� ��������� ���� ���. 

���� ����� ����� - ������� � ��������� ����.

� ������ ���������� �������� ����� ���� ���� �� ����, ��� ����� ���� �������/����������. ��� �������� ������ � ������
*/

class MyString
{
public:
	MyString()
	{
		str = nullptr;
	}

	MyString(const char* str)
	{
		int length = strlen(str);
		this->str = new char[length + 1];	//��������� ������ ��� ������������� ����, �.�. strlen ��� �� ���������

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];			//���� �������� ��������� �������� ������, ���������� ����������
		}
		this->str[length] = '\0';
	}

	MyString(const MyString& other)
	{
		int length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
	}

	~MyString()
	{
		delete[] str;
	}

	MyString& operator = (const MyString& other)
	{
		if (this->str != nullptr)
		{
			delete[] this->str;
		}

		int length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';

		return *this;
	}

	MyString operator + (const MyString& other)
	{
		MyString newStr;

		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);
		newStr.str = new char[thisLength + otherLength + 1];	//��� ������ ������ ������� ������� ��� ���� str ����� ���. ������

		int i = 0;
		for (; i < thisLength; i++)
		{
			newStr.str[i] = this->str[i];
		}

		for (int j = 0; j < otherLength; j++,i++)
		{
			newStr.str[i] = other.str[j];
		}

		newStr.str[thisLength + otherLength] = '\0';

		return newStr;	//�� ���������� ����� ������. ������� � ������������ �������� ������� � ��� Mystring. 
	}					//�����: �� ����� return � ��� ���������� ����������� �����������
						//���� �� ����������� ����������� �����������, ��������� �������� �� �����
						//��� �� �� ����� return � ��� ��������� ����������, ������� ������� ������������ ������ ������������ ������ newStr(� ��� �����
	void Print()		//������� ���������� � ������� main. 
	{
		cout << str << endl;
	}

private:
	char* str;

};


int main()
{
	MyString str("TEST");
	MyString str2("zhopa");

	MyString result = str + str2;

	return 0;
}