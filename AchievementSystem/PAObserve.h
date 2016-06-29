#pragma once
#include "Subject.h"

class CPAObserve :
	public CSubject
{
public:
	// 관찰자 갯수 최대를 3으로 했음. 뭐 갯수는 맘데로
	CPAObserve():CSubject(3)
	{
	}

	~CPAObserve()
	{
	}
	// CSubject 클래스를 상속받았으므로 notify메소드를 호출 할 수 있다.
	void updatePlayer(CCharacter& character)
	{
		// 이벤트 주체가 되는 객체와 어떤 이벤트를 기다리는지 종류를 넣어 호출한다.
		notify(character, AtteckNum_10);
		notify(character, AtteckNum_20);
		
	}
	void updateKuma(CCharacter& character)
	{
		notify(character, GrowlNum);
		notify(character, SniffNum);
	}

};

