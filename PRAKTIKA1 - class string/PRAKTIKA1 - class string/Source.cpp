#include <iostream>
//#include <string>

using namespace std;
/*��� ���������� ���������� � ���� ������������ ���� � ����������� .h
����� - ��� ��� �������� �������(����������). � cpp ���� - ��� ���������� ����� �������
#pragma once - ������� � ���, ��� ���, ��� �������� � ������ ����� ����� �������� � ���� ��������� ���� ���. 

���� ����� ����� - ������� � ��������� ����.

� ������ ���������� �������� ����� ���� ���� �� ����, ��� ����� ���� �������/����������. ��� �������� ������ � ������

����������� ������ �� ��� ������ (const MyString& other) - ��������, ��� �� �� �������� ������, � ������ ����������� �� ������-��
������, ������� �� ��������� ����� ������-�� �������, �������� ��� ������ �� �����(�.�. ����������� ������)
����������� �� 38 ������

��� ��������� ���������� ����������: ��� ��� ����� ����������� �������� [] ��� ������. ��� �� ����������? �������� - ������ char. 
��� �� ��������� � ���������� ������ �������� �������? ������ - �������� ���� int. ��� �������� � ����� ��������� ��� 
��������. ��� ���� �������� ����������? �����-�� ������� �� ������� this. 
��� ����, ����� ����� ����������� �������������� �������� � ����� ������, � �� ������ �� ��������, ����� ��������������
��� ��������: ���������� char& ������ �� ������. 

����������� ����������� ����� ��� ����������� ����, ��������� ���������. � ����� ���������(�� ���������� ������������ 
��������) �� ����� ������������ ��������� ����� ������. ��� return, ���� ������ �������� � ����������� �����������, ����������, 
����� ���� ���������. � ������������ ��� ����� - ���������� � ��������� �������.

��� �������� ����������� ��������: �� ���� �������, ��� ���� ������ this ��������� �� ������ other. ��� ������ � �����
������ this ����� �� ��� � other. � ����� �� ���� ����������� nullptr ������� other(����� �� ���� ������, �� �������
��������� ������ this). ���. �� �� �������� ����� ������������ ������, �� �������������� � ������������ ������������. �� ������
������ ����� ��������� �� ��� ������������ ������, � ������ ��������� ������ � nullptr. 
*/

class MyString
{
public:
	MyString()
	{
		str = nullptr;
		length = 0;
	}

	MyString(const char* str)
	{
		length = strlen(str);
		this->str = new char[length + 1];	//��������� ������ ��� ������������� ����, �.�. strlen ��� �� ���������

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];			//���� �������� ��������� �������� ������, ���������� ����������
		}
		this->str[length] = '\0';
	}

	MyString(const MyString& other)
	{
		length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
	}

	MyString(MyString&& other)
	{
		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
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

		length = strlen(other.str);
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
		newStr.length = thisLength + otherLength;

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
						//������� ���������� � ������� main. 
	
	bool operator == (const MyString& other)
	{
		if (this->length == other.length)
		{
			for (int i = 0; i < length; i++)
			{
				if (this->str[i] != other.str[i])
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator != (const MyString& other)
	{
		return !(this->operator==(other));
	}

	char& operator [] (int index)
	{
		return this->str[index];
	}

	void Print()		
	{
		cout << str << endl;
	}

	int Length()
	{
		return length;
	}

private:
	char* str;
	int length;
};


int main()
{
	MyString str("zhopa");
	MyString str2("zhopa");
	MyString result = str + str2;

	cout << str.Length() << endl;
	cout << str2.Length() << endl;
	cout << result.Length() << endl;
	cout << "\n\n\n";

	bool equal = str == str2;
	//bool equal = str.operator==(str2);	//�� �� �����. str - this, str2 - other

	cout << (str == str2) << endl;
	cout << (str != str2) << endl;

	str.Print();
	str[1] = 'Q';
	str.Print();

	cout << str[0] << endl;

	return 0;
}