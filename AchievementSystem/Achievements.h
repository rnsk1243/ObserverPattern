#pragma once
#include "Observer.h"
#include"Character.h"
#include<iostream>
using namespace std;

// ���� ���� �ڵ�
enum CAchievement
{
	// 10ȸ ���� �õ�
	playerAttackNum_10,
	playerAttackNum_20
};

class CAchievements :
	public CObserver
{
	// ���� ���� �ڵ忡���� ������ �޼�(��� ����)
	void unlock(CAchievement achievement)
	{
		// ���� ��� ����...
		switch (achievement)
		{
		case playerAttackNum_10:
			cout << "¦¦¦ 10�� ���� �ϼ̽��ϴ�!!" << endl;
			break;
		case playerAttackNum_20:
			cout << "¦¦¦ 20�� ���� �ϼ̽��ϴ�!!" << endl;
			break;
		default:
			break;
		}
	}
	// 10ȸ ���ݽõ� ���� �޼� �ߴ�?
	bool m_playerAttack_10;
	bool m_playerAttack_20;
public:

	CAchievements():m_playerAttack_10(false), m_playerAttack_20(false)
	{
	}

	~CAchievements()
	{
	}
	// �̺�Ʈ�� �Ͼ�� ���ÿ� �̺�Ʈ�Լ����� ȣ�����ִ� �޼ҵ�
	virtual void onNotify(/*�̺�Ʈ ���ϴ� ��ü*/CCharacter& character, /*�̺�Ʈ ����*/Event event)
	{
		//�̺�Ʈ ���������� ����ġ��
		switch (event)
		{
		case AtteckNum_10:
			//���� 10ȸ ���� ������ �޼����� �ʾҴٸ�.
			if (!m_playerAttack_10)
			{
				// �̺�Ʈ ���ϴ� ��ü(character)�� 10ȸ ���� ���� �޼��߳� ���߳� ����� ����.
				m_playerAttack_10 = character.isSuccess();
				// ĳ���� �ڵ尡 �÷��̾�(���ʹ� �ش� �ȵ�)�̰� 10ȸ ���� �޼� ������ 
				if (character.characterCode() == player && m_playerAttack_10)
				{
					// �Ķ���;��� ������ �޼�(��� ����)��Ŵ
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
			cout << "�����ȣ ����" << endl;
			break;
		}
	}

	
};

