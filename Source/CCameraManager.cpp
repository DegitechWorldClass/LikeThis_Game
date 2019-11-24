#include "DXUT.h"
#include "CCameraManager.h"


CCameraManager::CCameraManager()
{
	m_vPos = Vector3(WinSize.x / 2.f, WinSize.y / 2.f, -0);

	m_matView = Matrix(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 0, 1,
		-m_vPos.x, -m_vPos.y, 0, 1);
	D3DXMatrixOrthoLH(&m_matProj, WinSize.x, -WinSize.y, 0.f, 1.f);
}


CCameraManager::~CCameraManager()
{
}
void CCameraManager::Update()
{

	if (m_pFollowObject != nullptr)
	{
		if (m_PAS == PlayerAnimationStatus::PAS_Dash)
		{
			if (HZT > 0.1f)
				if (m_pFollowObject->Transform->GetPosition().x + 976 >= m_vPos.x)
					m_vPos.x += 40;
			if (HZT < 0.1f)
				if (m_pFollowObject->Transform->GetPosition().x - 976 <= m_vPos.x)
					m_vPos.x -= 40;
		}
		else
		{

			Lerp(&m_vPos.x, m_vPos.x, m_pFollowObject->Transform->GetPosition().x, DeltaTime * 7.5f);
		}
	}

	if (m_vPos.x + WinSize.x / 2.f >= 10000) m_vPos.x = 10000 - WinSize.x / 2.f;
	if (m_vPos.x - WinSize.x / 2.f <= 0) m_vPos.x = WinSize.x / 2.f;

	m_matView = Matrix(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 0, 1,
		-m_vPos.x, -m_vPos.y, 0, 1);
}

void CCameraManager::SetTransform()
{
	g_Device->SetTransform(D3DTS_PROJECTION, &m_matProj);
	g_Device->SetTransform(D3DTS_VIEW, &m_matView);
}
