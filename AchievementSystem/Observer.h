#pragma once
#include"Character.h"

// �̺�Ʈ ���� �ڵ�
enum Event
{
	// 10�� ���� �õ�
	AtteckNum_10,
	// 20�� ���� �õ�
	AtteckNum_20
};

// ������ Ŭ����
class CObserver
{
public:

	CObserver()
	{
	}

	virtual ~CObserver()
	{
	}
	// ĳ���� ��ü�� �̺�Ʈ �ڵ带 �־���
	// �̶� � ĳ���Ϳ� ���� �׸��� � �̺�Ʈ���� �����־� �� ĳ���͸��� �̺�Ʈ�� ������ �� �� �ִ�.
	virtual void onNotify(CCharacter& character, Event event) = 0;

};

