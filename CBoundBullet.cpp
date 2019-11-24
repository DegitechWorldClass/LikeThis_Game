#include "DXUT.h"
#include "CBoundBullet.h"
#include "CEffect.h"

CBoundBullet::CBoundBullet()
{
}


CBoundBullet::~CBoundBullet()
{
}

void CBoundBullet::Init()
{

}

void CBoundBullet::Update()
{
}

void CBoundBullet::Render()
{
}

void CBoundBullet::Release()
{
}

void CBoundBullet::OnCollisionEnter(CObject * _pObject)
{
	if (_pObject->GetObjectTag() == Tag::Floor)
	{
		i++;
		if (i == 3)
		{
			auto Effect = OBJECT.AddObject();

			Effect->Transform->SetPosition(this->Transform->GetPosition() - Vector3(50,75,0));
			Effect->AddComponent<CEffect>()->SetAnimation("ENEMY01_EFFECT");
			this->m_pObject->Destroy();
		}
	}
}

void CBoundBullet::OnCollisionStay(CObject * _pObject)
{
}

void CBoundBullet::OnCollisionExit(CObject * _pObject)
{
}
