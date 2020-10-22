#include "stdafx.h"
#include "Player2.h"
#include "HID/Pad.h"

Player2::Player2()
{
	//cmoファイルの読み込み。
	m_model.Init(L"Assets/modelData/unityChan.cmo");

	m_pos.y -= 60.0f;
	m_charaCon.Init(10.0f, 50.0f, m_pos);
}


Player2::~Player2()
{
}

void Player2::Update()
{

	//パッドのAボタンで上方向にジャンプする。
	if (g_pad[1].IsTrigger(enButtonA) == true
		&& m_charaCon.IsOnGround() == true
		) {
		m_moveSpeed.y += 500.0f;
	}
	//m_moveSpeedはプレイヤークラスのメンバ関数。
	//XZ平面の移動速度はパッド入力から引っ張ってくる。
	m_moveSpeed.x = g_pad[1].GetLStickXF() * -300.0f;
	m_moveSpeed.z = g_pad[1].GetLStickYF() * -300.0f;
	m_moveSpeed.y -= 980.0f * (1.0f / 60.0f); //重力（加速度）
	m_pos = m_charaCon.Execute(1.0f / 60.0f, m_moveSpeed);
	//プレイヤーを進行方向に向かせる。
	if (fabsf(m_moveSpeed.x) > 0.01f
		|| fabsf(m_moveSpeed.z) > 0.01f)
	{
		float angle = atan2(m_moveSpeed.x, m_moveSpeed.z);
		m_rotation.SetRotation(CVector3::AxisY(), angle);
	}
	//ワールド行列の更新。
	m_model.UpdateWorldMatrix(m_pos, m_rotation, CVector3::One());
}
void Player2::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);
}