#pragma once
#include "physics/PhysicsStaticObject.h"
class Background
{
public:
	Background();
	~Background();
	void Update();
	void Draw();

private:
	SkinModel m_model;									//スキンモデル。
	CVector3 m_pos = CVector3::Zero();
	PhysicsStaticObject m_phyStaticObject;
};
