#pragma once
class Player2
{
public:
	Player2();
	~Player2();
	void Update();
	void Draw();
private:
	SkinModel m_model;
	CVector3 m_pos = { 0.0f,0.0f,0.0f };
};

