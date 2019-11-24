#pragma once

const enum class EnemyState { Idle, Move, Attack, Death };
class CEnemyBase : public CComponent
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
protected:
	void Init() override;
	bool InRangeEnter();
public:
	CEnemyBase();
	~CEnemyBase();

	EnemyState m_State;

	void SetAnimationStatus(EnemyState _State);

	bool m_IsFired = false;
	float m_fRange;
	float m_fSpeed;
	float m_fMove;
	float m_fMoveDir;
	int m_nAttackFrame;
};

