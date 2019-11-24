#include "DXUT.h"
#include "CEnemy01.h"
#include "CBoundBullet.h"

CEnemy01::CEnemy01()
{
}


CEnemy01::~CEnemy01()
{
}

void CEnemy01::Update()
{
	switch (m_State)
	{
	case EnemyState::Idle:
		break;
	case EnemyState::Move:

		if (InRangeEnter())
		{
			this->SetAnimationStatus(EnemyState::Attack);
		}
		m_fMove += FixedDeltaTime * m_fSpeed;
		this->Transform->Translation(FixedDeltaTime * m_fSpeed * m_fMoveDir, 0, 0);
		this->Transform->SetScale(Vector3(m_fMoveDir, 1, 0));
		if (m_fMove > 300)
		{
			m_fMove = 0.f;
			m_fMoveDir = -m_fMoveDir;
		}

		break;
	case EnemyState::Attack:
		if (!InRangeEnter())
		{
			this->SetAnimationStatus(EnemyState::Move);
		}
		if (this->GetComponent<CAnimation2D>()->GetHandleAnimator()->GetCurFrame() == (BYTE)m_nAttackFrame)
		{
			if (m_IsFired == false)
			{
				m_IsFired = true;
				auto Bullet = OBJECT.AddObject("Enemy01_Bullet", Tag::BoundBullet);
				Bullet->Transform->Translation(this->Transform->GetPosition().x + 250 * m_fMoveDir, this->Transform->GetPosition().y);
				Bullet->AddComponent<CSpriteRenderer>()->SetTexture(IMAGE["ENEMY01_BULLET"]);
				Bullet->AddComponent<CBoxCollider2D>()->SetSize(Vector2(32.f, 32.f));
				Bullet->AddComponent<CRigidBody2D>();
				Bullet->GetComponent<CRigidBody2D>()->AddForce(1000 * m_fMoveDir, -10);
				Bullet->AddComponent<CBoundBullet>();
			}
		}
		else m_IsFired = false;
		break;
	case EnemyState::Death:
		break;
	}
}

void CEnemy01::Render()
{
}

void CEnemy01::Release()
{
}

void CEnemy01::OnCollisionEnter(CObject* _pObject)
{
}

void CEnemy01::OnCollisionStay(CObject* _pObject)
{
}

void CEnemy01::OnCollisionExit(CObject* _pObject)
{
}
