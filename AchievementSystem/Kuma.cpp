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
// 5¹ø Å¯Å¯!
bool CKuma::isSuccess()
{
	if (m_sniffNum >= 5)
	{
		return true;
	}
	else {
		//cout << "°ÅÁþ °õ" << endl;
		return false;
	}
}
// 3¹ø ¾îÈï!
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
	cout << "Äí¸¶ÀÇ ÅÏ!!! n : Å¯Å¯°Å¸®±â // a : Äí¸¶ ÆÝÄ¡ // m : Æ÷È¿" << endl;
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
				cout << "Å¯Å¯!" << endl;
				return;
			case 97: // 'a'
				cout << "Äí¸¶Â»ÀÇ °ø°Ý!" << endl;
				return;
			case 109: // 'm'
				m_growlNum++;
				cout << "¾îÈï!!" << endl;
				return;
			default:
				break;
			}
			if (ch == 'q')
				break;
		}
	}


}
