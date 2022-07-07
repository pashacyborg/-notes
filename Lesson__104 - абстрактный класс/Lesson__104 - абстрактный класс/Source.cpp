#include <iostream>

using namespace std;

/*����� ����������� ������� - ������ �������, ��� ����������.
���������: virtual ������������_�������� ���_������(���������) = 0; 
����������� ����� - �����, � ������� ���� ���� ���� ����� ����������� �������. � ������������ ������ ������ 
������� ������. 

��� �������� �������� ������ � ����������� ������� ��������� ������: � ������ ������ ���� ���������� ����� ������������ ������? 
����� ������� ����������� ����� � ����� ����������� ������� - � ����������� ������, �� ��� ��� ����������. 
���� ����� ����� ������ ��� ����, ����� �� ����� ��� ��������������. ����� �������� 

� ����������� ������ ����� ���� ���������� ������ � �����������.

���������� ������������ ������ �����������
*/

class Weapon
{
public:
	virtual void Shoot() = 0;
};


class Knife : Weapon
{
public:
	void Shoot() override
	{
		cout << "VJUH" << endl;
	}
};

class Gun : public Weapon
{
public:
	void Shoot() override
	{
		cout << "BUM" << endl;
	}
};


class MachineGun : public Gun
{
public:
	void Shoot() override
	{
		cout << "BUM BUM BUM" << endl;
	}
};


class Bazooka : public Weapon
{
public:
	void Shoot() override
	{
		cout << "BADABUM" << endl;
	}
};

class Player
{
public:
	void Shoot(Weapon* weapon)
	{
		weapon->Shoot();
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	Bazooka bazooka;
	Player player;
	player.Shoot(&bazooka);
	

	return 0;
}