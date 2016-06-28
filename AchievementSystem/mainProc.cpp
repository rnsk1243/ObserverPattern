#include"Player.h"
#include"Observer.h"
#include"Character.h"
#include"Achievements.h"
#include"PAObserve.h"

void main()
{
	// 이벤트 주체가 되는 플레이어 만듬
	CCharacter& player = CPlayer();
	// 관찰자
	CObserver* observer01 = new CAchievements();
	// CSubject클래스를 상속받은 클래스 객체 만듬
	// 이 객체를 통해 CSubject클래스의 notify 메소드 간접 호출
	CPAObserve* playerAttak = new CPAObserve();
	// 관찰자를 넣어줌으로서 CSubject클래스의 m_observer에 담기고 이것을 for문으로 돌려 모든 종류의 관찰자를 호출한다. 
	playerAttak->addObserver(observer01);
	

	while (true)
	{
		// 플레이어 공격 
		player.playAttack();
		// 간접 호출 메소드 호출( 이 메소드 안에 호출문이 들어있다.)
		playerAttak->updatePlayer(player);
	}

}