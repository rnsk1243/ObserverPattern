#pragma once
#include "Subject.h"

class CPAObserve :
	public CSubject
{
public:
	// ������ ���� �ִ븦 3���� ����. �� ������ ������
	CPAObserve():CSubject(3)
	{
	}

	~CPAObserve()
	{
	}
	// CSubject Ŭ������ ��ӹ޾����Ƿ� notify�޼ҵ带 ȣ�� �� �� �ִ�.
	void updatePlayer(CCharacter& character)
	{
		// �̺�Ʈ ��ü�� �Ǵ� ��ü�� � �̺�Ʈ�� ��ٸ����� ������ �־� ȣ���Ѵ�.
		notify(character, AtteckNum_10);
		notify(character, AtteckNum_20);
		
	}
	void updateKuma(CCharacter& character)
	{
		notify(character, GrowlNum);
		notify(character, SniffNum);
	}

};

