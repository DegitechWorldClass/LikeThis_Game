#include "DXUT.h"
#include "cBullet.h"

cBullet::cBullet()
{
	m_fBulletSpeed = 3000;
}


cBullet::~cBullet()
{
}

void cBullet::Init()
{
	Vector3 a = OBJECT.FindObjectWithName("Player")->Transform->GetPosition();
	this->Transform->SetPosition(Vector3(a.x,a.y,0));

	this->AddComponent<CSpriteRenderer>()->SetTexture(IMAGE["BULLET1"]);
	this->AddComponent<CBoxCollider2D>();
	this->GetComponent<CBoxCollider2D>()->SetSize(Vector2(64, 64));
}	


void cBullet::Update()
{
	if (i == 0)
	{
		Vector2 Pos = Vector2(0,0);
		Matrix matT, matR;
		D3DXMatrixTranslation(&matT, -IMAGE["PLAYER_GUN_3_HAND"]->GetSize().x * 0.15F, IMAGE["PLAYER_GUN_3_HAND"]->GetSize().y * 0.15F, 0);
		D3DXMatrixRotationZ(&matR, (atan2f(m_fBulletDir.y, m_fBulletDir.x)));
		
		D3DXVec2TransformCoord(&Pos, &Pos,&(matR * matT));
		this->m_pObject->Transform->SetPosition(this->Transform->GetPosition() + Vector3(Pos.x,Pos.y,0));

	}
	i++;
	this->Transform->SetRotation(Vector3(0, 0, D3DXToDegree(atan2f(m_fBulletDir.y, m_fBulletDir.x))));

	this->m_pObject->Transform->Translation(Vector3(m_fBulletDir.x,m_fBulletDir.y,0.f) * FixedDeltaTime * m_fBulletSpeed);
	this->Transform->SetScale(Vector3(m_fBulletDir.x <= 0 ? -1 : 1, 1, 0));
}

void cBullet::Render()
{
}

void cBullet::Release()
{
}

void cBullet::OnCollisionEnter(CObject * _pObject)
{
	if (_pObject->GetObjectTag() == Tag::Enemy)
	{
		_pObject->Destroy();
		this->m_pObject->Destroy();
	}
}

void cBullet::OnCollisionStay(CObject * _pObject)
{
}

void cBullet::OnCollisionExit(CObject * _pObject)
{
}
