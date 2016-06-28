#pragma once
#include"Character.h"

// 이벤트 종류 코드
enum Event
{
	// 10번 공격 시도
	AtteckNum_10,
	// 20번 공격 시도
	AtteckNum_20
};

// 관찰자 클래스
class CObserver
{
public:

	CObserver()
	{
	}

	virtual ~CObserver()
	{
	}
	// 캐릭터 객체와 이벤트 코드를 넣어줌
	// 이때 어떤 캐릭터에 따라 그리고 어떤 이벤트인지 정해주어 각 캐릭터마다 이벤트를 지정해 줄 수 있다.
	virtual void onNotify(CCharacter& character, Event event) = 0;

};

