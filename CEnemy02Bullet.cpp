#include "DXUT.h"
#include "CEnemy02Bullet.h"
CEnemy02Bullet::CEnemy02Bullet()
{
}

CEnemy02Bullet::~CEnemy02Bullet()
{
}


void CEnemy02Bullet::Init()
{
}
 
void CEnemy02Bullet::Update()
{
	this->Transform->SetScale(Vector3(m_Dir,1,1));
	this->m_pObject->Transform->SetPosition(this->Transform->GetPosition() + Vector3(m_Dir * m_Speed * FixedDeltaTime, 0, 0));

 	if (this->Transform->GetPosition().x >= m_Pos.x + m_Range 
		|| this->Transform->GetPosition().x <= m_Pos.x - m_Range)
	{
		this->m_pObject->Destroy();
	}
	//else if(m_Pos.x >= 500)
}

void CEnemy02Bullet::Render()
{
}

void CEnemy02Bullet::Release()
{
}

void CEnemy02Bullet::OnCollisionEnter(CObject* _pObject)
{
}

void CEnemy02Bullet::OnCollisionStay(CObject* _pObject)
{
}

void CEnemy02Bullet::OnCollisionExit(CObject* _pObject)
{
}

