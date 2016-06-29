#pragma once
#include "Observer.h"
#include"Character.h"
#include<iostream>
using namespace std;

// 적 업적 종류 코드
enum EnemyAchieve
{
	// 킁킁
	SniffCode,
	// 어흥
	GrowlCode
};

class CAchieveEnemy :
	public CObserver
{
	void unlock(EnemyAchieve achieve)
	{
		switch (achieve)
		{
		case SniffCode:
			cout << "축하해요 5번 킁킁 하셨어요!" << endl;
			break; 
		case GrowlCode:
			cout << "오메데또! 3번 어흥 했어요!" << endl;
			break;
		default:
			break;
		}
	}

	bool m_isSniff;
	bool m_isGrowl;
public:

	CAchieveEnemy():m_isSniff(false), m_isGrowl(false)
	{
	}

	~CAchieveEnemy()
	{
	}

	// 이벤트가 일어남과 동시에 이벤트함수까지 호출해주는 메소드
	virtual void onNotify(/*이벤트 당하는 객체*/CCharacter& character, /*이벤트 종류*/Event event)
	{
				//cout << "곰" << m_isSniff << endl;
		//이벤트 종류에따른 스위치문
		switch (event)
		{
		case SniffNum:
			if (!m_isSniff)
			{
				m_isSniff = character.isSuccess();
				
				if (character.characterCode() == enemy && m_isSniff)
				{

					unlock(SniffCode);
				}
			}
			break;
		case GrowlNum:
			if (!m_isGrowl)
			{
				m_isGrowl = character.isSuccess_20();
				if (character.characterCode() == enemy && m_isGrowl)
				{
					unlock(GrowlCode);
				}
			}
			break;
		default:
			//cout << "설정되지 않은 이벤트가 호출되었음" << endl;
			break;
		}
	}

};

