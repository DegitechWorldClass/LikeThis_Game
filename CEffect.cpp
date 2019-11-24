#include "DXUT.h"
#include "CEffect.h"


CEffect::CEffect()
{
}


CEffect::~CEffect()
{
}

void CEffect::SetAnimation(string _ResKey)
{
	GetComponent<CAnimation2D>()->AddAnimator(_ResKey, _ResKey, 0.1f, false);
	GetComponent<CAnimation2D>()->SetHandleAnimator(_ResKey);
}

void CEffect::Init()
{
	AddComponent<CSpriteRenderer>();
	AddComponent<CAnimation2D>();
}

void CEffect::Update()
{
	if (GetComponent<CAnimation2D>()->GetHandleAnimator()->GetEnable() == false)
	{
		this->m_pObject->Destroy();
	}
}

void CEffect::Render()
{
}

void CEffect::Release()
{
}

void CEffect::OnCollisionEnter(CObject * _pObject)
{
}

void CEffect::OnCollisionStay(CObject * _pObject)
{
}

void CEffect::OnCollisionExit(CObject * _pObject)
{
}
