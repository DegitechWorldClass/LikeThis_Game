#pragma once
#include "CComponent.h"
class CEnemy01Movement : public CComponent
{
	friend class CObjectManager;
	friend class CObject;

private:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollisionEnter(CObject * _pObject)	override;
	virtual void OnCollisionStay(CObject * _pObject)	override;
	virtual void OnCollisionExit(CObject * _pObject)	override;
	
public:
	CEnemy01Movement();
	~CEnemy01Movement();

	float m_fMove;
	float m_fMoveDir;
};

