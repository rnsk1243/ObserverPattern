#include "Player.h"
#include<iostream>
#include<conio.h>
using namespace std;

CPlayer::~CPlayer()
{
}

void CPlayer::playAttack()
{
	char ch;
	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
			case ' ':
				m_atteckNum++;
				cout << m_atteckNum << endl;
				return;
			default:
				break;
			}
			if (ch == 'q')
				break;
		}
	}
}