#include "Kuma.h"
#include<conio.h>
#include<iostream>
using namespace std;

CKuma::CKuma():m_growlNum(0), m_sniffNum(0)
{
}


CKuma::~CKuma()
{
}
// 5�� ůů!
bool CKuma::isSuccess()
{
	if (m_sniffNum >= 5)
	{
		return true;
	}
	else {
		//cout << "���� ��" << endl;
		return false;
	}
}
// 3�� ����!
bool CKuma::isSuccess_20()
{
	if (m_growlNum >= 3)
	{
		return true;
	}
	else {
		return false;
	}
}

void CKuma::playAttack()
{
	cout << "���� ��!!! n : ůů�Ÿ��� // a : �� ��ġ // m : ��ȿ" << endl;
	char ch;
	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
			case 110: // 'n'
				m_sniffNum++;
				cout << "ůů!" << endl;
				return;
			case 97: // 'a'
				cout << "��»�� ����!" << endl;
				return;
			case 109: // 'm'
				m_growlNum++;
				cout << "����!!" << endl;
				return;
			default:
				break;
			}
			if (ch == 'q')
				break;
		}
	}


}
