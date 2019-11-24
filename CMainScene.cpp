#include "DXUT.h"
#include "CMainScene.h"
#include "CPlayerMovement.h"
#include "CEnemy01Movement.h"
#include "CBackground.h"
#include "CEnemy01.h"
#include"CEnemy02.h"
#include"CGun.h"
#include"INGAMEUI.h"
CMainScene::CMainScene()
{
}


CMainScene::~CMainScene()
{
}

void CMainScene::Init()
{
	float Move = 0.f;
	OBJECT.DeleteCollisionDetect(Tag::BoundBullet, Tag::BoundBullet);
	OBJECT.DeleteCollisionDetect(Tag::BoundBullet, Tag::Player);
	OBJECT.DeleteCollisionDetect(Tag::Enemy, Tag::Player);
	OBJECT.DeleteCollisionDetect(Tag::Enemy, Tag::Enemy);
	//OBJECT.DeleteCollisionDetect(Tag::Player, Tag::Gun);
	OBJECT.DeleteCollisionDetect(Tag::Bullet, Tag::Player);

	OBJECT.DeleteCollisionDetect(Tag::EnemyBullet, Tag::Player);
	OBJECT.DeleteCollisionDetect(Tag::EnemyBullet, Tag::Enemy);


	IMAGE["BACKGROUND_1"]->SetAnchorPoint(Vector2(0.f, 0.f));
	IMAGE["BACKGROUND_2"]->SetAnchorPoint(Vector2(0.f, 0.f));
	IMAGE["BACKGROUND_3"]->SetAnchorPoint(Vector2(0.f, 0.f)); 
	IMAGE["BACKGROUNDOBJECT_1"]->SetAnchorPoint(Vector2(0.f, 1.f));
	IMAGE["BACKGROUNDOBJECT_2"]->SetAnchorPoint(Vector2(0.f, 1.f));
	IMAGE["BACKGROUNDOBJECT_3"]->SetAnchorPoint(Vector2(0.f, 1.f));
	IMAGE["BACKGROUNDOBJECT_4"]->SetAnchorPoint(Vector2(0.f, 1.f));
	IMAGE["BACKGROUNDOBJECT_5"]->SetAnchorPoint(Vector2(0.f, 1.f));
	for (int i = 0; i < 20; i++)
	{
		auto Background_1 = OBJECT.AddObject("BG_1", Tag::Untagged);
		Background_1->AddComponent<CSpriteRenderer>()->SetTexture(IMAGE["BACKGROUND_1"]);
		//Background_1->GetComponent<CSpriteRenderer>()->SetSortingLayer(SortingLayer::Background);
		Background_1->AddComponent<CBackground>();
		Background_1->Transform->SetPosition(Vector3(i * 2824, 0,0));
	}
	for (int i = 0; i < 20; i++)
	{
		auto Background_2 = OBJECT.AddObject("BG_2", Tag::Untagged);
		Background_2->AddComponent<CSpriteRenderer>()->SetTexture(IMAGE["BACKGROUND_2"]);
		//	Background_2->GetComponent<CSpriteRenderer>()->SetSortingLayer(SortingLayer::Background);
		Background_2->AddComponent<CBackground>();
		Background_2->Transform->SetPosition(Vector3(i * 2824, 0, 0));
	}
	for (int i = 0; i < 20; i++)
	{
		auto Background_3 = OBJECT.AddObject("BG_3", Tag::Untagged);
		Background_3->AddComponent<CSpriteRenderer>()->SetTexture(IMAGE["BACKGROUND_3"]);
		//Background_3->GetComponent<CSpriteRenderer>()->SetSortingLayer(SortingLayer::Background);
		Background_3->AddComponent<CBackground>();
		Background_3->Transform->SetPosition(Vector3(i * 2824, 0, 0));
	}

	float x = 0;
	for (int i = 0; i < 20; i++)
	{
		auto BgObject = OBJECT.AddObject("BGOBJ", Tag::Untagged);
		BgObject->AddComponent<CSpriteRenderer>()->SetTexture(IMAGE["BACKGROUNDOBJECT_1"]);
		//Background_3->GetComponent<CSpriteRenderer>()->SetSortingLayer(SortingLayer::Background);
		BgObject->AddComponent<CBackground>();
		BgObject->Transform->SetPosition(Vector3(x, 620, 0));
		x += 1224.f;

		auto BgObject1 = OBJECT.AddObject("BGOBJ", Tag::Untagged);
		BgObject1->AddComponent<CSpriteRenderer>()->SetTexture(IMAGE["BACKGROUNDOBJECT_2"]);
		//Background_3->GetComponent<CSpriteRenderer>()->SetSortingLayer(SortingLayer::Background);
		BgObject1->AddComponent<CBackground>();
		BgObject1->Transform->SetPosition(Vector3(x, 620, 0));
		x += 556.f;

		auto BgObject2 = OBJECT.AddObject("BGOBJ", Tag::Untagged);
		BgObject2->AddComponent<CSpriteRenderer>()->SetTexture(IMAGE["BACKGROUNDOBJECT_3"]);
		//Background_3->GetComponent<CSpriteRenderer>()->SetSortingLayer(SortingLayer::Background);
		BgObject2->AddComponent<CBackground>();
		BgObject2->Transform->SetPosition(Vector3(x, 620, 0));
		x += 432.f;


		auto BgObject3 = OBJECT.AddObject("BGOBJ", Tag::Untagged);
		BgObject3->AddComponent<CSpriteRenderer>()->SetTexture(IMAGE["BACKGROUNDOBJECT_4"]);
		//Background_3->GetComponent<CSpriteRenderer>()->SetSortingLayer(SortingLayer::Background);
		BgObject3->AddComponent<CBackground>();
		BgObject3->Transform->SetPosition(Vector3(x, 620, 0));
		x += 426.f;

		auto BgObject4 = OBJECT.AddObject("BGOBJ", Tag::Untagged);
		BgObject4->AddComponent<CSpriteRenderer>()->SetTexture(IMAGE["BACKGROUNDOBJECT_5"]);
		//Background_3->GetComponent<CSpriteRenderer>()->SetSortingLayer(SortingLayer::Background);
		BgObject4->AddComponent<CBackground>();
		BgObject4->Transform->SetPosition(Vector3(x, 620, 0));
		x += 646.f;
	}




		auto Floor = OBJECT.AddObject("Floor", Tag::Floor);
		Floor->AddComponent<CSpriteRenderer>()->SetTexture(IMAGE["FLOOR"]);
		Floor->Transform->SetScale(Vector3(10, 1, 0));
		Floor->Transform->SetPosition(Vector3( 6280 / 2, 720, 0.f));
		Floor->AddComponent<CBoxCollider2D>()->SetSize(Vector2(62900, 200));



	//for (int i = 1; i < 10; i++)
	//{
	//	auto Enemy = OBJECT.AddObject("Enemy", Tag::Enemy);
	//	Enemy->AddComponent<CEnemy01>();
	//	Enemy->GetComponent<CEnemy01>()->GetComponent<CAnimation2D>()->AddAnimator("MOVE", "ENEMY01_MOVE", 0.1f, true);
	//	Enemy->GetComponent<CEnemy01>()->GetComponent<CAnimation2D>()->AddAnimator("ATTACK", "ENEMY01_ATTACK", 0.1f, true);
	//	Enemy->GetComponent<CEnemy01>()->GetComponent<CAnimation2D>()->SetHandleAnimator("MOVE");
	//	Enemy->GetComponent<CEnemy01>()->m_State = EnemyState::Move;
	//	Enemy->GetComponent<CEnemy01>()->m_fSpeed = 80;
	//	Enemy->GetComponent<CEnemy01>()->m_fRange = 700;
	//	Enemy->GetComponent<CEnemy01>()->m_nAttackFrame = 7;
	//	Enemy->Transform->Translation(1000 * i, 0);
	//	Enemy->GetComponent<CEnemy01>()->GetComponent<CBoxCollider2D>()->SetSize(Vector2(422, 274));
	//}
	auto Enemey2 = OBJECT.AddObject("Enemy2", Tag::Enemy);
	Enemey2->AddComponent<CEnemy02>();
	Enemey2->AddComponent<CEnemy02>()->GetComponent<CAnimation2D>()->AddAnimator("MOVE", "ENEMY02_MOVE", 0.1f, true);
	Enemey2->AddComponent<CEnemy02>()->GetComponent<CAnimation2D>()->AddAnimator("ATTACK", "ENEMY02_ATTACK", 0.1f, true);
	Enemey2->GetComponent<CEnemy02>()->GetComponent<CAnimation2D>()->SetHandleAnimator("MOVE");
	Enemey2->GetComponent<CEnemy02>()->m_State = EnemyState::Move;
	Enemey2->GetComponent<CEnemy02>()->m_fSpeed = 100;
	Enemey2->GetComponent<CEnemy02>()->m_fRange = 700;
	Enemey2->GetComponent<CEnemy02>()->m_nAttackFrame = 10;
	Enemey2->Transform->Translation(800, 0);
	Enemey2->GetComponent<CEnemy02>()->GetComponent<CBoxCollider2D>()->SetSize(Vector2(50 * 2,85 * 2));
	//Enemey5->GetComponent<CEnemy02>()->GetComponent<CAnimation2D>()->AddAnimator("ATTACK", "ENEMY01_ATTACK", 0.1f, true);
	//auto Enemy2 = OBJECT.AddObject("Enemy2", Tag::Enemy);
	//Enemy2->AddComponent<CSpriteRenderer>();
	//Enemy2->AddComponent<CAnimation2D>();
	//Enemy2->GetComponent<CAnimation2D>()->AddAnimator("MOVE", "ENEMY02_MOVE", 0.1f, true);
	//Enemy2->GetComponent<CAnimation2D>()->SetHandleAnimator("MOVE");
	//Enemy2->AddComponent<CRigidBody2D>();
	//Enemy2->AddComponent<CBoxCollider2D>()->SetSize(Vector2(176, 144));
	//Enemy2->Transform->Translation(600, 0);
	//Enemy2->AddComponent<CEnemy01Movement>();
	//Enemy->GetComponent<CSpriteRenderer>()->SetSortingLayer(SortingLayer::Enemy);
	//
	//auto Enemy3 = OBJECT.AddObject("Enemy3", Tag::Enemy);
	//Enemy3->AddComponent<CSpriteRenderer>();
	//Enemy3->AddComponent<CAnimation2D>();
	//Enemy3->GetComponent<CAnimation2D>()->AddAnimator("MOVE", "ENEMY03_MOVE", 0.1f, true);
	//Enemy3->GetComponent<CAnimation2D>()->SetHandleAnimator("MOVE");
	//Enemy3->AddComponent<CRigidBody2D>();
	//Enemy3->AddComponent<CBoxCollider2D>()->SetSize(Vector2(84, 94));
	//Enemy3->Transform->Translation(900, 0);
	//Enemy3->AddComponent<CEnemy01Movement>();
	////Enemy->GetComponent<CSpriteRenderer>()->SetSortingLayer(SortingLayer::Enemy);
	//
	//auto Enemy4 = OBJECT.AddObject("Enemy4", Tag::Enemy);
	//Enemy4->AddComponent<CSpriteRenderer>();
	//Enemy4->AddComponent<CAnimation2D>();
	//Enemy4->GetComponent<CAnimation2D>()->AddAnimator("MOVE", "ENEMY04_MOVE", 0.1f, true);
	//Enemy4->GetComponent<CAnimation2D>()->SetHandleAnimator("MOVE");
	//Enemy4->AddComponent<CRigidBody2D>();
	//Enemy4->AddComponent<CBoxCollider2D>()->SetSize(Vector2(220, 322));
	//Enemy4->Transform->Translation(1200, 0);
	//Enemy4->AddComponent<CEnemy01Movement>();
	//Enemy->GetComponent<CSpriteRenderer>()->SetSortingLayer(SortingLayer::Enemy);

	auto Player = OBJECT.AddObject("Player", Tag::Player);
	Player->Transform->SetPosition(Vector3(100, 0, 0));
	Player->AddComponent<CSpriteRenderer>();
	Player->AddComponent<CAnimation2D>();
	Player->AddComponent<CPlayerMovement>();
	Player->GetComponent<CAnimation2D>()->AddAnimator("IDLE", "PLAYER_IDLE", 0.1f, true);
	Player->GetComponent<CAnimation2D>()->AddAnimator("RUN", "PLAYER_RUN", 0.11f, true);
	Player->GetComponent<CAnimation2D>()->AddAnimator("UP", "PLAYER_UP", 0.15f, FALSE, 1);
	Player->GetComponent<CAnimation2D>()->AddAnimator("DOWN", "PLAYER_DOWN", 0.15f, FALSE, 1);
	Player->GetComponent<CAnimation2D>()->AddAnimator("DASH", "PLAYER_DASH", 0.035f, FALSE, 11);

	

	for (int i = 0; i < 12; i++)
	{
		IMAGE["PLAYER_DASH ("s + to_string(i + 1) + ")"s]->SetAnchorPoint(Vector2(0, 0.58f));
	}
	Player->GetComponent<CAnimation2D>()->SetHandleAnimator("IDLE");
	Player->AddComponent<CBoxCollider2D>()->SetSize(Vector2(125.f, 158.f));
	Player->AddComponent<CRigidBody2D>();
	//Player->GetComponent<CSpriteRenderer>()->SetSortingLayer(SortingLayer::Player);

	//IMAGE["PLAYER_GUN_3_HAND"]->SetAnchorPoint(Vector2(0.35, 0.35));
	auto Gun = OBJECT.AddObject("Gun", Tag::Gun);
	Gun->AddComponent<CSpriteRenderer>()->SetTexture(IMAGE["PLAYER_GUN"]);
	Gun->Transform->SetPosition(Vector3( 400,300,0));
	Gun->Transform->SetScale(Vector3(2, 2, 2));
	Gun->AddComponent<CBoxCollider2D>()->SetSize(Vector2(51 * 2,15 * 2));
	Gun->AddComponent<CRigidBody2D>();
	Gun->AddComponent<CGun>();

	UI = new INGAMEUI();
	 
}
void CMainScene::Update()
{
	
	//UI->Update();
}

void CMainScene::Render()
{
//	UI->Render();
}

void CMainScene::Release()
{
	SAFE_DELETE(UI);

}
