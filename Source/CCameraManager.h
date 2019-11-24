#pragma once
#include "CSingleton.h"
#include"CPlayerMovement.h"
class CCameraManager :
	public CSingleton< CCameraManager>
{
public:
	CCameraManager();
	~CCameraManager();

public:

	void Update();
	void SetTransform();

	Matrix m_matView;
	Matrix m_matProj;
private:
	Vector3 m_vPos;
	PlayerAnimationStatus m_PAS;

	float HZT;

	CObject * m_pFollowObject = nullptr;
public:
	void FollowObject(CObject * _pObject) { m_pFollowObject = _pObject; }

	Vector3 GetPos() { return m_vPos; }
	void SetPos(Vector3 _vPos) { m_vPos = _vPos; }

	void SetPAS(PlayerAnimationStatus m_PlayerAnimationStatus) { m_PAS = m_PlayerAnimationStatus; };

	void SetfDirection(float Direction) { HZT = Direction; }
};

#define CAMERA (*CCameraManager::GetInstance())

