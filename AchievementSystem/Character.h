#pragma once

// CCharacter�� ��ӹ��� ��ü�� � ��ü���� characterCode()�޼ҵ尡 �˸��� ���� ������.
// �ٸ� ��ü�� �˸��� �������� �𸣹Ƿ� �̷��� �մϴ�.
enum ObjectCode
{
	// �÷��̾��� ���
	player,
	// ���� ���(����)
	enemy
};

class CCharacter
{
public:
	CCharacter() {

	}

	virtual ~CCharacter()
	{
	}
	// ��ӹ��� ��ü�� ������� ObjectCode�߿� �ϳ� ����
	virtual int characterCode() = 0;
	// 10�� ���� �����ΰ�?
	virtual bool isSuccess() = 0;
	// 20�� ���� �����ΰ�?
	virtual bool isSuccess_20() = 0;
	// ���� ��� ���� (�����ϰ�� ���͸��� ���ݹ�� �����Ѵ�)
	virtual void playAttack() = 0;
};

