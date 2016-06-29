#pragma once
#include"Character.h"
#include<iostream>
using namespace std;

class CPlayer: public CCharacter
{
	// 공격 횟수
	int m_atteckNum;
public:
	CPlayer() :m_atteckNum(0){}
	virtual ~CPlayer();
	// 플레이어 공격법
	virtual void playAttack();
	// 자신을 플레이어라고 리턴
	virtual int characterCode()
	{
		return player;
	}
	// 10번 공격 성공인가?
	virtual bool isSuccess()
	{
		if (m_atteckNum == 10)
		{
			//cout << "트루" << endl;
			return true;
		}else {
			//cout << "거짓" << endl;
			return false;
		}
	}
	// 20번 공격 성공인가?
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

