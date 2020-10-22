#include "stdafx.h"
#include "Background.h"

Background::Background()
{
	//cmoファイルの読み込み。
	m_model.Init(L"Assets/modelData/map.cmo");

	m_phyStaticObject.CreateMeshObject(m_model, m_pos, CQuaternion::Identity());
}

Background::~Background() 
{
}

void Background::Update()
{
	//ワールド行列の更新。
	m_model.UpdateWorldMatrix(m_pos, CQuaternion::Identity(), CVector3::One());
	
}

void Background::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);
}