#pragma once

// CCharacter을 상속받은 물체가 어떤 물체인지 characterCode()메소드가 알맞은 것을 리턴함.
// 다른 물체도 알림을 받을지도 모르므로 이렇게 합니다.
enum ObjectCode
{
	// 플레이어일 경우
	player,
	// 적일 경우(몬스터)
	enemy
};

class CCharacter
{
public:
	CCharacter() {

	}

	virtual ~CCharacter()
	{
	}
	// 상속받은 객체가 어떤것인지 ObjectCode중에 하나 리턴
	virtual int characterCode() = 0;
	// 10번 공격 성공인가?
	virtual bool isSuccess() = 0;
	// 20번 공격 성공인가?
	virtual bool isSuccess_20() = 0;
	// 공격 방법 정의 (몬스터일경우 몬스터만의 공격방법 정의한다)
	virtual void playAttack() = 0;
};

