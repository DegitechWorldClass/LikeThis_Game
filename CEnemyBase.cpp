#include "DXUT.h"
#include "CEnemyBase.h"


CEnemyBase::CEnemyBase()
{

}


CEnemyBase::~CEnemyBase()
{
}

void CEnemyBase::SetAnimationStatus(EnemyState _State)
{
	if (m_State == _State) return;

	m_State = _State;

	switch (_State)
	{
	case EnemyState::Idle:
		this->GetComponent<CAnimation2D>()->SetHandleAnimator("IDLE");
		break;
	case EnemyState::Move:
		this->GetComponent<CAnimation2D>()->SetHandleAnimator("MOVE");
		break;
	case EnemyState::Attack:
		this->GetComponent<CAnimation2D>()->SetHandleAnimator("ATTACK");
		break;
	case EnemyState::Death:
		this->GetComponent<CAnimation2D>()->SetHandleAnimator("DEATH");
		break;
	}
}

void CEnemyBase::Init()
{
	m_fMoveDir = 1.f;
	m_fMove = 0.f;
	this->AddComponent<CSpriteRenderer>();
	this->AddComponent<CAnimation2D>();
	this->AddComponent<CRigidBody2D>();
	this->AddComponent<CBoxCollider2D>();
}

void CEnemyBase::Update()
{
}

void CEnemyBase::Render()
{
}

void CEnemyBase::Release()
{
}

void CEnemyBase::OnCollisionEnter(CObject* _pObject)
{
}

void CEnemyBase::OnCollisionStay(CObject* _pObject)
{
}

void CEnemyBase::OnCollisionExit(CObject* _pObject)
{
}

bool CEnemyBase::InRangeEnter()
{
	if (m_fMoveDir == -1.f)
	{
		return (this->Transform->GetPosition().x + m_fRange * m_fMoveDir <= OBJECT.FindObjectWithName("Player")->Transform->GetPosition().x
			&& this->Transform->GetPosition().x >= OBJECT.FindObjectWithName("Player")->Transform->GetPosition().x
			&& this->Transform->GetPosition().y + 300 >= OBJECT.FindObjectWithName("Player")->Transform->GetPosition().y
			&& this->Transform->GetPosition().y - 300 <= OBJECT.FindObjectWithName("Player")->Transform->GetPosition().y);
	}

	else if (m_fMoveDir == 1.f)
	{
		return (this->Transform->GetPosition().x + m_fRange * m_fMoveDir >= OBJECT.FindObjectWithName("Player")->Transform->GetPosition().x
			&& this->Transform->GetPosition().x <= OBJECT.FindObjectWithName("Player")->Transform->GetPosition().x
			&& this->Transform->GetPosition().y + 300 >= OBJECT.FindObjectWithName("Player")->Transform->GetPosition().y
			&& this->Transform->GetPosition().y - 300 <= OBJECT.FindObjectWithName("Player")->Transform->GetPosition().y);
	}
}
