#pragma once
#include "CScene.h"
class INGAMEUI;
class CMainScene :
	public CScene
{
private:
	INGAMEUI* UI;
public:
	CMainScene();
	~CMainScene();
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

