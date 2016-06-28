#pragma once
#include "Observer.h"
#include"Character.h"
#include<iostream>
using namespace std;

// 업적 종류 코드
enum CAchievement
{
	// 10회 공격 시도
	playerAttackNum_10,
	playerAttackNum_20
};

class CAchievements :
	public CObserver
{
	// 업적 종류 코드에따라서 업적을 달성(잠금 해제)
	void unlock(CAchievement achievement)
	{
		// 업적 잠금 해제...
		switch (achievement)
		{
		case playerAttackNum_10:
			cout << "짝짝짝 10번 공격 하셨습니다!!" << endl;
			break;
		case playerAttackNum_20:
			cout << "짝짝짝 20번 공격 하셨습니다!!" << endl;
			break;
		default:
			break;
		}
	}
	// 10회 공격시도 업적 달성 했니?
	bool m_playerAttack_10;
	bool m_playerAttack_20;
public:

	CAchievements():m_playerAttack_10(false), m_playerAttack_20(false)
	{
	}

	~CAchievements()
	{
	}
	// 이벤트가 일어남과 동시에 이벤트함수까지 호출해주는 메소드
	virtual void onNotify(/*이벤트 당하는 객체*/CCharacter& character, /*이벤트 종류*/Event event)
	{
		//이벤트 종류에따른 스위치문
		switch (event)
		{
		case AtteckNum_10:
			//아직 10회 공격 업적을 달성하지 않았다면.
			if (!m_playerAttack_10)
			{
				// 이벤트 당하는 객체(character)가 10회 공격 업적 달성했나 안했나 결과를 대입.
				m_playerAttack_10 = character.isSuccess();
				// 캐릭터 코드가 플레이어(몬스터는 해당 안됨)이고 10회 공격 달성 했으면 
				if (character.characterCode() == player && m_playerAttack_10)
				{
					// 파라미터안의 업적을 달성(잠금 해제)시킴
					unlock(playerAttackNum_10);
				}
			}
			break;
		case AtteckNum_20:
			if (!m_playerAttack_20)
			{
				m_playerAttack_20 = character.isSuccess_20();
				if (character.characterCode() == player && m_playerAttack_20)
				{
					unlock(playerAttackNum_20);
				}
			}
			break;
		default:
			cout << "응답신호 없음" << endl;
			break;
		}
	}

	
};

