#pragma once
const enum class PlayerAnimationStatus{ PAS_Idle, PAS_Run, PAS_JumpUp, PAS_JumpDown, PAS_Attack,PAS_Dash };

class CPlayerMovement : public CComponent
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
	CPlayerMovement();
	~CPlayerMovement();

private:
	float m_fMoveSpeed;
	bool isRight = false;
	float fNormalizedMoveDir = 0.f;
public:
	void SetAnimationStatus(PlayerAnimationStatus _Status);
	PlayerAnimationStatus m_PlayerAnimationStatus;


	void AnimationUpdate();

};

