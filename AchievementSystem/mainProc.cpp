#include"Player.h"
#include"Observer.h"
#include"Character.h"
#include"Achievements.h"
#include"PAObserve.h"
#include"Kuma.h"
#include"AchieveEnemy.h"

void main()
{
	// �̺�Ʈ ��ü�� �Ǵ� �÷��̾� ����
	CCharacter& player = CPlayer();
	// �̺�Ʈ ��ü�� �Ǵ� �� ����
	CCharacter& kuma = CKuma();
	// ������
	CObserver* observer01 = new CAchievements();
	// ��(����) ������
	CObserver* kumaObs01 = new CAchieveEnemy();
	// CSubjectŬ������ ��ӹ��� Ŭ���� ��ü ����
	// �� ��ü�� ���� CSubjectŬ������ notify �޼ҵ� ���� ȣ��
	// �� Ĵü�� ���� �����ڸ� ������ (*Ŭ�������� CPAObserve���� �����µ� �÷��̾ �����ϴ� �����ڻӸ��ƴ϶� ���͸� �����ϴ� �����ڵ� ���Եȴ�.)
	CPAObserve* ObserCollection = new CPAObserve();
	// �����ڸ� �־������μ� CSubjectŬ������ m_observer�� ���� �̰��� for������ ���� ��� ������ �����ڸ� ȣ���Ѵ�. 
	ObserCollection->addObserver(observer01);
	// �� ������ �ֱ�
	ObserCollection->addObserver(kumaObs01);

	while (true)
	{
		// �÷��̾� ���� 
		player.playAttack();
		// ���� ȣ�� �޼ҵ� ȣ��( �� �޼ҵ� �ȿ� ȣ�⹮�� ����ִ�.)
		ObserCollection->updatePlayer(player);
		// ���� ����
		kuma.playAttack();
		ObserCollection->updateKuma(kuma);
		/*
		// ����
		�̷��� ���ָ� �ȵȴ�. 
		ObserCollection->updatePlayer(player);
		ObserCollection->updatePlayer(kuma);

		void updatePlayer(CCharacter& character)
		{
		// �̷��� ���ָ� �ȵ�. ->���� player�� GrowlNum�̺�Ʈ�ʹ� ���� ������ ���� ���� ���� �־� ȣ���� �ʿ䵵 ����
		ȣ�� �ϸ� ������ �����. 
		� ���� -> 
		�÷��̾�� ���� �̺�Ʈ(����,���� ���)�� �̸�Ű�� �ٸ� �ʿ���� �̺�Ʈ�̺�Ʈ�� ���� �Ͼ��.
		�� notify�޼ҵ�� ȣ��Ǹ� for������ ���� ��� �������� onNotify�޼ҵ带 ȣ���Ѵ�. 
		�� ���� �̺�Ʈ�� �����ߴٰ� ġ�� ���� isSuccess()�޼ҵ尡 true�� ��ȯ�Ұ��̴�. 
		�̶� �÷��̾ ���� onNotify�� ���� �������� ���� isSuccess()�޼ҵ尡 true�� �־
		���� �÷��̾�� ������ �޼������� ���ߴµ� m_playerAttack_10�� true�� �������� �̺�Ʈ�� ȣ���� ���� �ʰԵȴ�.

		���� �ݵ�� ��ü�� �� ��ü�� ���õ� �̺�Ʈ �ڵ带 ���ؼ��� notify�� ȣ���� ����.

		notify(character, AtteckNum_10);
		notify(character, AtteckNum_20);
		notify(character, GrowlNum);
		notify(character, SniffNum);
		}

		*/
	}

}