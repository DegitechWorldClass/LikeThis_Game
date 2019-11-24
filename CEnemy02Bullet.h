#pragma once

class CEnemy02Bullet : public CComponent
{
	friend class CObjectManager;
	friend class CObject;

private:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void OnCollisionEnter(CObject* _pObject)	override;
	virtual void OnCollisionStay(CObject* _pObject)	override;
	virtual void OnCollisionExit(CObject* _pObject)	override;

public:
	CEnemy02Bullet();
	~CEnemy02Bullet();

public:
	float m_Dir;
	float m_Speed;
	Vector2 m_Pos;
	float m_Range;
};
