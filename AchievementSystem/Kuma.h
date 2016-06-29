#pragma once
#include "Character.h"
class CKuma :
	public CCharacter
{
	// 킁킁 횟수
	int m_sniffNum;
	// 어흥 횟수
	int m_growlNum;
public:
	CKuma();
	virtual ~CKuma();

	// 상속받은 객체가 어떤것인지 ObjectCode중에 하나 리턴
	virtual int characterCode()
	{
		return enemy;
	}
	// 5번 킁킁 냄새 맡기 성공인가?
	virtual bool isSuccess();
	// 3번 어흥! 성공인가?
	virtual bool isSuccess_20();
	// 공격 방법 정의 (몬스터일경우 몬스터만의 공격방법 정의한다)
	virtual void playAttack();
};

