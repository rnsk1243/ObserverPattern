#pragma once
#include "Observer.h"
#include"Character.h"
#include<iostream>
using namespace std;

// �� ���� ���� �ڵ�
enum EnemyAchieve
{
	// ůů
	SniffCode,
	// ����
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
			cout << "�����ؿ� 5�� ůů �ϼ̾��!" << endl;
			break; 
		case GrowlCode:
			cout << "���޵���! 3�� ���� �߾��!" << endl;
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

	// �̺�Ʈ�� �Ͼ�� ���ÿ� �̺�Ʈ�Լ����� ȣ�����ִ� �޼ҵ�
	virtual void onNotify(/*�̺�Ʈ ���ϴ� ��ü*/CCharacter& character, /*�̺�Ʈ ����*/Event event)
	{
				//cout << "��" << m_isSniff << endl;
		//�̺�Ʈ ���������� ����ġ��
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
			//cout << "�������� ���� �̺�Ʈ�� ȣ��Ǿ���" << endl;
			break;
		}
	}

};

