#include"Player.h"
#include"Observer.h"
#include"Character.h"
#include"Achievements.h"
#include"PAObserve.h"

void main()
{
	// �̺�Ʈ ��ü�� �Ǵ� �÷��̾� ����
	CCharacter& player = CPlayer();
	// ������
	CObserver* observer01 = new CAchievements();
	// CSubjectŬ������ ��ӹ��� Ŭ���� ��ü ����
	// �� ��ü�� ���� CSubjectŬ������ notify �޼ҵ� ���� ȣ��
	CPAObserve* playerAttak = new CPAObserve();
	// �����ڸ� �־������μ� CSubjectŬ������ m_observer�� ���� �̰��� for������ ���� ��� ������ �����ڸ� ȣ���Ѵ�. 
	playerAttak->addObserver(observer01);
	

	while (true)
	{
		// �÷��̾� ���� 
		player.playAttack();
		// ���� ȣ�� �޼ҵ� ȣ��( �� �޼ҵ� �ȿ� ȣ�⹮�� ����ִ�.)
		playerAttak->updatePlayer(player);
	}

}