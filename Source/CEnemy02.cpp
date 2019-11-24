#include "DXUT.h"
#include "CEnemy02.h"
#include"CEnemy02Bullet.h"
void CEnemy02::Update()
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
		this->Transform->SetScale(Vector3(m_fMoveDir * -2, 1 * 2, 0));
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
		if (this->GetComponent<CAnimation2D>()->GetHandleAnimator()->GetCurFrame() == (BYTE)m_nAttackFrame - 1)
		{
			if (m_IsFired == false)
			{
				m_IsFired = true;
				auto Bullet = OBJECT.AddObject("Bullet", Tag::EnemyBullet);
				Bullet->Transform->Translation(this->Transform->GetPosition().x + 1* m_fMoveDir, this->Transform->GetPosition().y - 15);
				Bullet->AddComponent<CSpriteRenderer>()->SetTexture(IMAGE["BULLET1"]);
				Bullet->AddComponent<CEnemy02Bullet>()->m_Dir = m_fMoveDir;
				Bullet->AddComponent<CEnemy02Bullet>()->m_Speed = 400;
				Bullet->AddComponent<CEnemy02Bullet>()->m_Pos = (Vector2)this->Transform->GetPosition();
				Bullet->AddComponent<CEnemy02Bullet>()->m_Range = m_fRange;
				Bullet->AddComponent<CBoxCollider2D>()->SetSize(Vector2(32.f, 32.f));
			}
		}
		else
		{
		 m_IsFired = false;
		}
			break;
	case EnemyState::Death:
		break;
	}
}

void CEnemy02::Render()
{
}

void CEnemy02::Release()
{
}

void CEnemy02::OnCollisionEnter(CObject* _pObject)
{
}

void CEnemy02::OnCollisionStay(CObject* _pObject)
{
}

void CEnemy02::OnCollisionExit(CObject* _pObject)
{
}

CEnemy02::CEnemy02()
{
}

CEnemy02::~CEnemy02()
{
}
