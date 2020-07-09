#pragma once
#include "character/CharacterController.h"

class Player
{
public:
	Player();
	~Player();
	void Update();
	void Draw();
private:
	SkinModel m_model;									//�X�L�����f���B
	CVector3 m_pos = { 0.0f,0.0f,0.0f };
};

