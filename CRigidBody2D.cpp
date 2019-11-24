#include "DXUT.h"
#include "CRigidBody2D.h"

#define GRAVITY 9.8f
void CRigidBody2D::Init()
{
	this->m_vVelocity = Vector2(0.f, 0.f);
	this->m_bIsKinematic = false;
	this->m_fGravityScale = 1.f;
	this->m_fMass = 1.f;
	this->m_bIsColision = false;
}

void CRigidBody2D::Update()
{
	if (m_bMove == true)
	{
		if (m_bIsKinematic == FALSE && m_bIsColision == false)
		{
			m_vVelocity.y += 4200 * m_fMass * m_fGravityScale * FixedDeltaTime;
			
			m_vVelocity.y *= 0.98f;
			m_vVelocity.x *= 0.97f;
		}
		m_vLast = this->Transform->GetPosition();
		this->Transform->Translation(m_vVelocity * FixedDeltaTime);
	}
}

void CRigidBody2D::Render()
{
}

void CRigidBody2D::Release()
{
}

void CRigidBody2D::OnCollisionEnter(CObject * _pObject)
{
	m_bIsColision = true;
	//Lerp(&pos, pos, m_vLast, FixedDeltaTime * 3);
	//Lerp(&pos, pos, m_vLast, FixedDeltaTime * 3);
	//Lerp(&pos, pos, m_vLast, FixedDeltaTime * 3);
	//Lerp(&pos, pos, m_vLast, FixedDeltaTime * 3);
	//Lerp(&pos, pos, m_vLast, FixedDeltaTime * 3);
	//this->Transform->Translation(-m_vVelocity * FixedDeltaTime);
	if (this->m_pObject->GetObjectTag() == Tag::BoundBullet)
	{
		m_vVelocity.y = -m_vVelocity.y * 0.9f;

	}
	else
	{
		Vector3 vMyPos = this->Transform->GetPosition();
		 
		Vector3 vTargetPos = _pObject->Transform->GetPosition();
		if (m_vVelocity.y > 0)
		{
			vMyPos.y =
				vTargetPos.y -
				_pObject->GetComponent<CBoxCollider2D>()->GetSize().y / 2.f +
				_pObject->GetComponent<CBoxCollider2D>()->GetOffSet().y -
				this->GetComponent<CBoxCollider2D>()->GetSize().y / 2.f +
				this->GetComponent<CBoxCollider2D>()->GetOffSet().y;
		}
		this->Transform->SetPosition(vMyPos);
		m_vVelocity = Vector2(0, 0);

	}
}

void CRigidBody2D::OnCollisionStay(CObject * _pObject)
{
}

void CRigidBody2D::OnCollisionExit(CObject * _pObject)
{
	m_bIsColision = false;
}

CRigidBody2D::CRigidBody2D()

{
}


CRigidBody2D::~CRigidBody2D()
{
}
