#include"Player.h"
#include"Observer.h"
#include"Character.h"
#include"Achievements.h"
#include"PAObserve.h"
#include"Kuma.h"
#include"AchieveEnemy.h"

void main()
{
	// 이벤트 주체가 되는 플레이어 만듬
	CCharacter& player = CPlayer();
	// 이벤트 주체가 되는 쿠마 만듬
	CCharacter& kuma = CKuma();
	// 관찰자
	CObserver* observer01 = new CAchievements();
	// 쿠마(몬스터) 관찰자
	CObserver* kumaObs01 = new CAchieveEnemy();
	// CSubject클래스를 상속받은 클래스 객체 만듬
	// 이 객체를 통해 CSubject클래스의 notify 메소드 간접 호출
	// 이 캑체에 여러 관찰자를 보관함 (*클래스명을 CPAObserve으로 지었는데 플레이어를 관찰하는 관찰자뿐만아니라 몬스터를 관찰하는 관찰자도 포함된다.)
	CPAObserve* ObserCollection = new CPAObserve();
	// 관찰자를 넣어줌으로서 CSubject클래스의 m_observer에 담기고 이것을 for문으로 돌려 모든 종류의 관찰자를 호출한다. 
	ObserCollection->addObserver(observer01);
	// 쿠마 관찰자 넣기
	ObserCollection->addObserver(kumaObs01);

	while (true)
	{
		// 플레이어 공격 
		player.playAttack();
		// 간접 호출 메소드 호출( 이 메소드 안에 호출문이 들어있다.)
		ObserCollection->updatePlayer(player);
		// 쿠마의 공격
		kuma.playAttack();
		ObserCollection->updateKuma(kuma);
		/*
		// 주의
		이렇게 해주면 안된다. 
		ObserCollection->updatePlayer(player);
		ObserCollection->updatePlayer(kuma);

		void updatePlayer(CCharacter& character)
		{
		// 이렇게 해주면 안됨. ->이유 player와 GrowlNum이벤트와는 전혀 관련이 없다 굳이 같이 넣어 호출할 필요도 없도
		호출 하면 문제가 생긴다. 
		어떤 문제 -> 
		플레이어든 쿠마든 이벤트(공격,냄새 등등)를 이르키면 다른 필요없는 이벤트이벤트도 같이 일어난다.
		이 notify메소드는 호출되면 for문으로 인해 모든 관찰자의 onNotify메소드를 호출한다. 
		쿠마 업적 이벤트가 성공했다고 치자 쿠마의 isSuccess()메소드가 true를 반환할것이다. 
		이때 플레이어가 들어가는 onNotify에 쿠마가 들어가버리고 쿠마의 isSuccess()메소드가 true를 주어서
		아직 플레이어는 업적을 달성하지도 못했는데 m_playerAttack_10에 true가 들어가버려서 이벤트가 호출이 되지 않게된다.

		따라서 반드시 객체와 이 객체와 관련된 이벤트 코드를 통해서만 notify를 호출해 주자.

		notify(character, AtteckNum_10);
		notify(character, AtteckNum_20);
		notify(character, GrowlNum);
		notify(character, SniffNum);
		}

		*/
	}

}