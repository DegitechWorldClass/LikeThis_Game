#pragma once
class cBullet : public CComponent
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
	cBullet();
	~cBullet();
public:
	Vector3 m_FirstDistance;
	Vector3 m_NowDistance;
	Vector2 m_fBulletDir;
	int m_fRot;
	float m_fBulletSpeed;
	int i = 0;
	float time = 0;
};

