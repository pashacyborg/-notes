#include <iostream>
#include <string>

using namespace std;

/*������������, ���������: class_name : public/private/protected class_name
������������ - ��������, ��� ������� ���� ������ ����� ����������� �������� ������� �������. ������, �������
�������� �������������� �������� ����� ����� ����������� ��������(������ �����, ����� ����� ������������ ��������).
������� ����� - ���, �� �������� �����������. 
�������� ����� - ��� �����, ������� ����������� �������� �������� ������.

������������ ��������� ���������� ������������ ����, ���������� ������ �� ������ ������ ����.
���������� ������������ ���� � ������� ���������� ���������� ������������, � ����� ������ �����������
������� � ����� ��������� ������� ������ �������. 

������������ ������ ��� ��� ��������
*/

class Human
{
public:
	string name;

	void SetSurname(string surname)
	{
		this->surname = surname;
	}

	string GetSurname()
	{
		return surname;
	}

private:
	string surname;	//���� ���������, ����� ������ �� ���������. ���������� ������� � �������
};

class Student : public Human
{
public:
	string group;

	void Learn()
	{
		cout << "� �����!" << endl;
	}
};

class CorrespondenceStudent : public Student
{
public:
	void Learn()
	{
		cout << "� ����� �� �����, �� ������ �������!" << endl;
	}
};

class Emplloyee : public CorrespondenceStudent	//����� Emplloyee(��������) �������� � ���� ��� ���������� ������ � �� ����
{
public:
	string subject;
};

int main()
{
	setlocale(LC_ALL, "ru");

	Student st;
	st.name = "Petya";	//�������� ������ � ���� ������ Human
	cout << st.name << endl;
	st.Learn();

	CorrespondenceStudent cst;
	cst.Learn();	//���� �� �������������� ����� Learn � ��������, ����� ���������� ����� Learn ������

	Emplloyee emp;
	emp.SetSurname("Ivanovich");
	cout << emp.GetSurname() << endl;



	

	
	return 0;
}