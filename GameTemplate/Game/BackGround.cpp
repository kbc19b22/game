#include "stdafx.h"
#include "Background.h"

Background::Background()
{
	//cmo�t�@�C���̓ǂݍ��݁B
	m_model.Init(L"Assets/modelData/map.cmo");

	m_phyStaticObject.CreateMeshObject(m_model, m_pos, CQuaternion::Identity());
}

Background::~Background() 
{
}

void Background::Update()
{
	//���[���h�s��̍X�V�B
	m_model.UpdateWorldMatrix(m_pos, CQuaternion::Identity(), CVector3::One());
	
}

void Background::Draw()
{
	m_model.Draw(
		g_camera3D.GetViewMatrix(),
		g_camera3D.GetProjectionMatrix()
	);
}