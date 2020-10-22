#pragma once
#include "character/CharacterController.h"

class Player 
{
public:
	Player();
	~Player();
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
	CVector3 m_pos = { 0.0f,0.0f,0.0f };                //座標
	CVector3 m_scale = { 0.0f,0.0f,0.0f };              //拡大率
	CVector3 m_moveSpeed = { 0.0f,0.0f,0.0f };          //移動速度
	CQuaternion m_rotation = CQuaternion::Identity();   //回転
	CharacterController m_charaCon;

	int a = 0;
};

