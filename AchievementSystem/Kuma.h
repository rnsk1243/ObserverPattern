#pragma once
#include "Character.h"
class CKuma :
	public CCharacter
{
	// ůů Ƚ��
	int m_sniffNum;
	// ���� Ƚ��
	int m_growlNum;
public:
	CKuma();
	virtual ~CKuma();

	// ��ӹ��� ��ü�� ������� ObjectCode�߿� �ϳ� ����
	virtual int characterCode()
	{
		return enemy;
	}
	// 5�� ůů ���� �ñ� �����ΰ�?
	virtual bool isSuccess();
	// 3�� ����! �����ΰ�?
	virtual bool isSuccess_20();
	// ���� ��� ���� (�����ϰ�� ���͸��� ���ݹ�� �����Ѵ�)
	virtual void playAttack();
};

