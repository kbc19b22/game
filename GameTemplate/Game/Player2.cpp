#include "stdafx.h"
#include "Player2.h"

Player2::Player2() 
{
	//cmo�t�@�C���̓ǂݍ��݁B
	m_model.Init(L"Assets/modelData/unityChan.cmo");
}
Player2::~Player2()
{
}
void Player2::Update()
{
	if (g_pad[0].IsPress(enButtonUp)) {
		m_pos.y += 1.0f;
	}

	if (g_pad[0].IsPress(enButtonDown)) {
		m_pos.y -= 1.0f;
	}
	//���[���h�s��̍X�V�B
	m_model.UpdateWorldMatrix(m_pos, CQuaternion::Identity(), CVector3::One());
}
void Player2::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);
}