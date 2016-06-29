#pragma once
#include"Observer.h"
#include"Character.h"

class CSubject
{
private:
	// �������� ����
	int m_observerNum;
	// �����ڵ��� �ּҸ� ��´�.
	CObserver** m_observer;
protected:
	// �� �޼ҵ�� CSubject�� ��ӹ޴� Ŭ�������� ȣ���Ŵ���� �ٸ� �ܺο��� ȣ���� �� ������ �Ѵ�.
	void notify(CCharacter& character, Event event)
	{
		// ������ ���� ������ŭ
		for (int i = 0; i < m_observerNum; i++)
		{
			// ���� ������ �����ڸ� ���� m_observer�� 
			//������ �����ڸ��� �ٸ��� ���ǵ� onNotify(CCharacter& character, Event event) �� ȣ���Ͽ� ���� �̺�Ʈ �޼ҵ带 ȣ����.
			// ����� CAchievements Ŭ���� �����ڸ� �����ϴµ�
			// CObserver�� ��ӹ����� addObserver(CObserver* observer) �޼ҵ带 �̿��Ͽ� m_observer�� ���� �� �����Ƿ�
			// �󸶵��� ���������� �����ڸ� ���� �� �ִ�. ������ ���� ���δٸ� onNotify(CCharacter& character, Event event)�� �����Ͽ� 
			// �������� ����� ���ô�!
			m_observer[i]->onNotify(character, event);
		}
	}
public:

	CSubject(int MaxObserverNum):m_observerNum(0)
	{
		// ������ �ʱ�ȭ (�̷� ������ �ʱ�ȭ�� �淮���Ͽ� �� ���� �ִ�.)
		m_observer = new CObserver*[MaxObserverNum];
	}

	~CSubject()
	{
	}
	// �����ڰ�ü�� ����
	void addObserver(CObserver* observer)
	{
		// �������� �ּҸ� ����
		m_observer[m_observerNum] = observer;
		// �������� ���� ����
		m_observerNum++;
	}
	// ������ ����
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

