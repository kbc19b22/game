#include "stdafx.h"
#include "system/system.h"
#include "Player.h"
#include "Player2.h"
#include "level/Level.h"
#include "BackGround.h"
#include "GameCamera.h"


//�v���C���[
Player* player = nullptr;
//�v���C���[2
Player2* player2 = nullptr;
//�Q�[���J����
GameCamera* gamecamera = nullptr;
//�o�b�N�O�����h
Background* background = nullptr;

///////////////////////////////////////////////////////////////////
//�Q�[���̏���������
///////////////////////////////////////////////////////////////////
void Game()
{
	//�v���C���[�̏������B
	player = new Player;
	player->SetPosition({ 30.0f,0.0f,0.0f });

	//�v���C���[2�̏������B
	player2 = new Player2;
	player2->SetPosition({ 30.0f,0.0f,0.0f });

	//�Q�[���J�����̏������B
	gamecamera = new GameCamera;
	gamecamera->SetPlayer(player);

	//�o�b�N�O�����h�̏������B
	background = new Background;
}

///////////////////////////////////////////////////////////////////
//�Q�[���̍X�V�����B
///////////////////////////////////////////////////////////////////
void UpdateGame()
{
	//�Q�[���p�b�h�̍X�V�B
	for (auto& pad : g_pad) {
		pad.Update();
	}
	//�����G���W���̍X�V�B
	g_physics.Update();
	//�v���C���[�̍X�V�B
	player->Update();
	//�Q�[���J�����̍X�V�B
	gamecamera->Update();
	//�v���C���[2�̍X�V�B
	player2->Update();
	//�o�b�N�O�����h�̍X�V�B
	background->Update();
}

///////////////////////////////////////////////////////////////////
//�Q�[���̕`�揈���B
///////////////////////////////////////////////////////////////////
void RenderGame()
{
	//�`��J�n�B
	g_graphicsEngine->BegineRender();

	//�v���C���[�̕`��B
	player->Draw();
	//�v���C���[2�̕`��B
	player2->Draw();
	//�o�b�N�O�����h�̕`��B
	background->Draw();

	//�`��I���B
	g_graphicsEngine->EndRender();
}

///////////////////////////////////////////////////////////////////
//�Q�[���̏I�������B
///////////////////////////////////////////////////////////////////
void TermnateGame()
{
	//���I�Ɋm�ۂ����C���X�^���X��j���B
	delete player;
	delete player2;
	delete gamecamera;
	delete background;
}
///////////////////////////////////////////////////////////////////
//�E�B���h�E�v���O�����̃��C���֐��B
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//�Q�[���G���W���̏������B
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, "Game");
	//�Q�[���̏������B
	Game();
	//�Q�[�����[�v�B
	while (DispatchWindowMessage() == true)
	{
		//�Q�[���̍X�V�B
		UpdateGame();
		//�Q�[���̕`�揈���B
		RenderGame();
	}
	//�Q�[���̏I������
	TermnateGame();
}