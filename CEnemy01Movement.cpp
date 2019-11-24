#include "DXUT.h"
#include "CEnemy01Movement.h"


CEnemy01Movement::CEnemy01Movement()
{
}


CEnemy01Movement::~CEnemy01Movement()
{
}

void CEnemy01Movement::Init()
{
	m_fMoveDir = 1.f;
	m_fMove = 0.f;
	
}

void CEnemy01Movement::Update()
{

		m_fMove += FixedDeltaTime * 80;
		this->Transform->Translation(FixedDeltaTime * 80 * m_fMoveDir, 0, 0);
		this->Transform->SetScale(Vector3(m_fMoveDir , 1, 0));
		if (m_fMove > 240)
		{
			m_fMove = 0.f;
			m_fMoveDir = -m_fMoveDir;
		}
}

void CEnemy01Movement::Render()
{
}

void CEnemy01Movement::Release()
{
}

void CEnemy01Movement::OnCollisionEnter(CObject * _pObject)
{
}

void CEnemy01Movement::OnCollisionStay(CObject * _pObject)
{
}

void CEnemy01Movement::OnCollisionExit(CObject * _pObject)
{
}
