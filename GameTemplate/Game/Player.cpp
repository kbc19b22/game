#include "stdafx.h"
#include "Player.h"
#include "HID/Pad.h"

Player::Player()
{
	//cmo�t�@�C���̓ǂݍ��݁B
	m_model.Init(L"Assets/modelData/unityChan.cmo");

	m_pos.y -= 50.0f;
	m_charaCon.Init(17.5f, 60.0f, m_pos);
}


Player::~Player()
{
}

void Player::Update()
{
	//m_moveSpeed�̓v���C���[�N���X�̃����o�֐��B
	//XZ���ʂ̈ړ����x�̓p�b�h���͂�����������Ă���B
	m_moveSpeed.x = g_pad[0].GetLStickXF() * -300.0f;
	m_moveSpeed.z = g_pad[0].GetLStickYF() * -300.0f;
	m_moveSpeed.y -= 980.0f * (1.0f / 60.0f); //�d�́i�����x�j

	//�v���C���[��i�s�����Ɍ�������B
	if (fabsf(m_moveSpeed.x) > 0.01f
		|| fabsf(m_moveSpeed.z) > 0.01f)
	{
		float angle = atan2(m_moveSpeed.x, m_moveSpeed.z);
		m_rotation.SetRotation(CVector3::AxisY(), angle);
	}
	//�p�b�h��A�{�^���ŏ�����ɃW�����v����B
	if (g_pad[0].IsTrigger(enButtonA) == true
		&& m_charaCon.IsOnGround() == true
		) {
		m_moveSpeed.y += 300.0f;
	}
	//�p�b�h��B�{�^���Ń_�b�V������B
	if (g_pad[0].IsPress(enButtonB) == true
		&& m_charaCon.IsOnGround() == true
		) {
		CVector3 a = m_moveSpeed;
		m_moveSpeed = m_moveSpeed * 2.0f;
		m_moveSpeed.y = a.y;
	}

	/*if (g_pad[0].IsPress(enButtonX) == true
		&& m_charaCon.IsOnGround() == true
		) {
		Draw();
	}*/

	m_pos = m_charaCon.Execute(1.0f / 60.0f, m_moveSpeed);

	//���[���h�s��̍X�V�B
	m_model.UpdateWorldMatrix(m_pos, m_rotation, CVector3::One());
	
}
void Player::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(), 
		g_camera3D.GetProjectionMatrix()
	);
}