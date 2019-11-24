#pragma once
#include "CEnemyBase.h"
class CEnemy01 : public CEnemyBase
{
	friend class CObjectManager;
	friend class CObject;

private:
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollisionEnter(CObject* _pObject)	override;
	virtual void OnCollisionStay(CObject* _pObject)	override;
	virtual void OnCollisionExit(CObject* _pObject)	override;
public:
	CEnemy01();
	~CEnemy01();
};

