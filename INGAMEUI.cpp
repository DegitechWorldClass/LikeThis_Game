#include "DXUT.h"
#include "INGAMEUI.h"

void INGAMEUI::Init()
{
	//i = 0;
}

void INGAMEUI::Update()
{

}

void INGAMEUI::Render()
{
	IMAGE.ReBegin(TRUE);
	D3DXMATRIX mat, matT, matS, matR;
	D3DXMatrixTranslation(&matT, WinSize.x / 2, WinSize.y / 2, 0);
	D3DXMatrixRotationZ(&matR, D3DXToRadian(0));
	D3DXMatrixScaling(&matS, 1, 1, 1);
	mat = matS * matR * matT;
	CRRect a =
	{
		0,0,640,360
	};
	IMAGE.Render(IMAGE.FindTexture("Title"), mat, a, D3DCOLOR_XRGB(255, 255, 255));
	
	
}

void INGAMEUI::Release()
{

}

void INGAMEUI::OnCollisionEnter(CObject* _pObject)
{
}

void INGAMEUI::OnCollisionStay(CObject* _pObject)
{
}

void INGAMEUI::OnCollisionExit(CObject* _pObject)
{
}


INGAMEUI::INGAMEUI()
{
	Init();
}

INGAMEUI::~INGAMEUI()
{
	Release();
}
