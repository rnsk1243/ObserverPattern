#pragma once
#include"Character.h"

class CPlayer: public CCharacter
{
	// ���� Ƚ��
	int m_atteckNum;
public:
	CPlayer() :m_atteckNum(0){}
	virtual ~CPlayer();
	// �÷��̾� ���ݹ�
	virtual void playAttack();
	// �ڽ��� �÷��̾��� ����
	virtual int characterCode()
	{
		return player;
	}
	// 10�� ���� �����ΰ�?
	virtual bool isSuccess()
	{
		if (m_atteckNum == 10)
		{
			return true;
		}else {
			return false;
		}
	}
	// 20�� ���� �����ΰ�?
	virtual bool isSuccess_20()
	{
		if (m_atteckNum == 20)
		{
			return true;
		}
		else {
			return false;
		}
	}
};
