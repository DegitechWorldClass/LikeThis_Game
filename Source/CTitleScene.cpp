#include "DXUT.h"
#include "CTitleScene.h"
#include"CImageManager.h"
CTitleScene::CTitleScene()
{
}

CTitleScene::~CTitleScene()
{
}

void CTitleScene::Init()
{

}

void CTitleScene::Update()
{
	if (INPUT.KeyDown('A'))
	{
		SCENE.ChangeScene("S_MAIN");
	}
}

void CTitleScene::Render()
{
	D3DXMATRIX mat, matT, matS, matR;
	D3DXMatrixTranslation(&matT, WinSize.x / 2, WinSize.y / 2, 0);
	D3DXMatrixRotationZ(&matR, D3DXToRadian(0));
	D3DXMatrixScaling(&matS, 2, 2, 1);
	mat = matS *  matR* matT;
	CRRect a = 
	{
		0,0,640,360
	};
	IMAGE.Render(IMAGE.FindTexture("Title"),mat, a, D3DCOLOR_XRGB(255,255,255));
}


void CTitleScene::Release()
{
}
