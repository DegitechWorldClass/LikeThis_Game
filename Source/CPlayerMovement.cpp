#include "DXUT.h"
#include "CPlayerMovement.h"
#include "cBullet.h"
#include "cGun.h"

CPlayerMovement::CPlayerMovement()
{
	
}


CPlayerMovement::~CPlayerMovement()
{
}

void CPlayerMovement::SetAnimationStatus(PlayerAnimationStatus _Status)
{
	if (m_PlayerAnimationStatus == _Status) return;

	m_PlayerAnimationStatus = _Status;

	switch (_Status)
	{
	case PlayerAnimationStatus::PAS_Idle:
		this->GetComponent<CAnimation2D>()->SetHandleAnimator("IDLE");
		break;
	case PlayerAnimationStatus::PAS_Run:
		this->GetComponent<CAnimation2D>()->SetHandleAnimator("RUN");
		break;
	case PlayerAnimationStatus::PAS_JumpUp:
		this->GetComponent<CAnimation2D>()->SetHandleAnimator("UP");
		break;
	case PlayerAnimationStatus::PAS_JumpDown:
		this->GetComponent<CAnimation2D>()->SetHandleAnimator("DOWN");
		break;
	case PlayerAnimationStatus::PAS_Attack:
		this->GetComponent<CAnimation2D>()->SetHandleAnimator("ATTACK");
		break;
	case PlayerAnimationStatus::PAS_Dash:
		this->GetComponent<CAnimation2D>()->SetHandleAnimator("DASH");
		break;
	}
}

void CPlayerMovement::AnimationUpdate()
{
}


void CPlayerMovement::Init()
{
	m_fMoveSpeed = 50.f;
	this->Transform->SetScale(Vector3(1.f, 1.f, 1.f));
	SetAnimationStatus(PlayerAnimationStatus::PAS_Idle);
	CAMERA.FollowObject(this->m_pObject);
}

void CPlayerMovement::Update()
{
	
	bool bInputMoveKey = false; // ����Ű�� �������� Ȯ�����ִ� ����
	bool bInputJumpKey = false; // ����Ű�� �������� Ȯ�����ִ� ����

	//====================== ����Ʈ �ý��� ======================//

	//����Ű�� ������������ ȣ��Ǵ� ���� �Լ�
	auto OnMoveKeyPress = LAMBDA
	(
		if (m_PlayerAnimationStatus != PlayerAnimationStatus::PAS_Dash)
		{
			this->Transform->SetScale(Vector3(fNormalizedMoveDir, 1, 0));
			this->Transform->Translation(fNormalizedMoveDir * m_fMoveSpeed * FixedDeltaTime * 10, 0);
			if (m_PlayerAnimationStatus != PlayerAnimationStatus::PAS_JumpUp &&
				m_PlayerAnimationStatus != PlayerAnimationStatus::PAS_JumpDown &&
				m_PlayerAnimationStatus != PlayerAnimationStatus::PAS_Dash)
				SetAnimationStatus(PlayerAnimationStatus::PAS_Run);
		}
	);
	//����Ű�� �������� ȣ��Ǵ� ���� �Լ�
	auto OnJumpKeyDown = LAMBDA
	(
		this->GetComponent<CRigidBody2D>()->SetVelocitiy(Vector2(0, -1400));
		SetAnimationStatus(PlayerAnimationStatus::PAS_JumpUp);

	);

	auto OnDashKeyDown  = LAMBDA
	(
		SetAnimationStatus(PlayerAnimationStatus::PAS_Dash);
	);

	//========================================================//



	//====================== Ű�Է� ó�� ==========================//

	if (INPUT.KeyDown(VK_SHIFT) && m_PlayerAnimationStatus != PlayerAnimationStatus::PAS_Dash 
		&&m_PlayerAnimationStatus != PlayerAnimationStatus::PAS_JumpUp
		&& m_PlayerAnimationStatus != PlayerAnimationStatus::PAS_JumpDown)
	{
		OnDashKeyDown();
		
	}
	if (INPUT.KeyPress('A') && m_PlayerAnimationStatus != PlayerAnimationStatus::PAS_Dash)
	{
		isRight = false;
		fNormalizedMoveDir = -1.f;
		bInputMoveKey = true;
	}
	else if (INPUT.KeyPress('D') && m_PlayerAnimationStatus != PlayerAnimationStatus::PAS_Dash)
	{
		isRight = true;
		fNormalizedMoveDir = 1.f;
		bInputMoveKey = true;
	}
	else
	{

		bInputMoveKey = false;
	}
	if (INPUT.KeyDown(VK_SPACE) && m_PlayerAnimationStatus != PlayerAnimationStatus::PAS_Dash)//����, Z
	{
		bInputJumpKey = true;

	}
	if(INPUT.KeyDown(VK_LBUTTON))//�߻�, X
	{
		auto p_Bullet = OBJECT.AddObject("Bullet", Tag::Bullet);
		//p_Bullet->AddComponent<cBullet>()->m_fBulletDir = OBJECT.FindObjectWithTag(Tag::Gun)->GetComponent<cGun>()->Dir;
	}

	if (bInputMoveKey == true)
	{
		OnMoveKeyPress();
	}
	else
	{
		if(m_PlayerAnimationStatus != PlayerAnimationStatus::PAS_JumpUp &&
			m_PlayerAnimationStatus != PlayerAnimationStatus::PAS_JumpDown && 
			m_PlayerAnimationStatus != PlayerAnimationStatus::PAS_Dash)
			SetAnimationStatus(PlayerAnimationStatus::PAS_Idle);

	}
	if (bInputJumpKey == true)
	{
		OnJumpKeyDown();
	}
	//========================================================//

	//====================== ��Ÿ ���� ó�� ==========================//
	if (m_PlayerAnimationStatus == PlayerAnimationStatus::PAS_JumpUp)
	{
		if (this->GetComponent<CRigidBody2D>()->GetVelocity().y > 0)
		{
			SetAnimationStatus(PlayerAnimationStatus::PAS_JumpDown);
		}
	}

	if (m_PlayerAnimationStatus == PlayerAnimationStatus::PAS_Dash)
	{
		if (this->GetComponent<CAnimation2D>()->GetHandleAnimator()->GetEnable() == false)
		{
			this->Transform->Translation(973 * this->Transform->GetScale().x, 0);
			SetAnimationStatus(PlayerAnimationStatus::PAS_Idle);
			
		}
	}
	//========================ī�޶� ó��================================//


	CAMERA.SetPAS(m_PlayerAnimationStatus);
	CAMERA.SetfDirection(fNormalizedMoveDir);

	//==========================================================//
}


void CPlayerMovement::Render()
{

}

void CPlayerMovement::Release()
{
}

void CPlayerMovement::OnCollisionEnter(CObject * _pObject)
{
	if (_pObject->GetObjectTag() == Tag::Floor)
	{
		if (this->m_PlayerAnimationStatus == PlayerAnimationStatus::PAS_JumpDown)
			SetAnimationStatus(PlayerAnimationStatus::PAS_Idle);
	}
	if (_pObject->GetObjectTag() == Tag::Gun)
	{
		this->Transform->SetPosition(Vector3(0, 0,0));
	}

}

void CPlayerMovement::OnCollisionStay(CObject * _pObject)
{

}

void CPlayerMovement::OnCollisionExit(CObject * _pObject)
{
}
