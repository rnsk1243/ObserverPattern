#include "Player.h"
#include<conio.h>


CPlayer::~CPlayer()
{
}

void CPlayer::playAttack()
{
	cout << "�÷��̾��� ��!!! �����̽��� : ����" << endl;
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