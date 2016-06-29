#pragma once
#include"Observer.h"
#include"Character.h"

class CSubject
{
private:
	// 관찰자의 개수
	int m_observerNum;
	// 관찰자들의 주소를 담는다.
	CObserver** m_observer;
protected:
	// 이 메소드는 CSubject을 상속받는 클래스에서 호출시킴으로 다른 외부에서 호출할 수 없도록 한다.
	void notify(CCharacter& character, Event event)
	{
		// 관찰자 종류 개수만큼
		for (int i = 0; i < m_observerNum; i++)
		{
			// 여러 종류의 관찰자를 넣은 m_observer의 
			//각각의 관찰자마다 다르게 정의된 onNotify(CCharacter& character, Event event) 를 호출하여 여러 이벤트 메소드를 호출함.
			// 현재는 CAchievements 클래스 관찰자만 존재하는데
			// CObserver만 상속받으면 addObserver(CObserver* observer) 메소드를 이용하여 m_observer에 넣을 수 있으므로
			// 얼마든지 여러종류의 관찰자를 만들 수 있다. 관찰자 마다 서로다른 onNotify(CCharacter& character, Event event)를 정의하여 
			// 여러가지 만들어 봅시다!
			m_observer[i]->onNotify(character, event);
		}
	}
public:

	CSubject(int MaxObserverNum):m_observerNum(0)
	{
		// 관찰자 초기화 (이런 포인터 초기화는 경량패턴에 잘 나와 있다.)
		m_observer = new CObserver*[MaxObserverNum];
	}

	~CSubject()
	{
	}
	// 관찰자객체를 더함
	void addObserver(CObserver* observer)
	{
		// 관찰자의 주소를 대입
		m_observer[m_observerNum] = observer;
		// 관찰자의 개수 증가
		m_observerNum++;
	}
	// 관찰자 삭제
	void removeObserver(CObserver* observer)
	{
		for (int i = 0; i < m_observerNum; i++)
		{
			if (m_observer[i] == observer)
			{
				for (int j = i + 1; j < m_observerNum; j++)
				{
					m_observer[i] = m_observer[j];
				}
				m_observerNum--;
				return;
			}
		}
	}

};

