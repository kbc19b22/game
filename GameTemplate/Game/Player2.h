#pragma once
#include "character/CharacterController.h"


class Player2 
{
public:
	Player2();
	~Player2();
	void Update();
	void Draw();
	void SetPosition(CVector3 pos)
	{
		m_pos = pos;
	}
	CVector3 GetPosition()
	{
		return m_pos;
	}
private:
	SkinModel m_model;									//スキンモデル。
	Animation m_animation;                              //アニメーション。
	AnimationClip m_animationClips[2];                  //アニメーションクリップ。
	CVector3 m_pos = { 0.0f,0.0f,0.0f };
	CVector3 m_scale = { 0.0f,0.0f,0.0f };
	CVector3 m_moveSpeed = { 0.0f,0.0f,0.0f };
	CQuaternion m_rotation = CQuaternion::Identity();
	CharacterController m_charaCon;
};

