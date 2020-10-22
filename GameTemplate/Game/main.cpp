#include "stdafx.h"
#include "system/system.h"
#include "Player.h"
#include "Player2.h"
#include "level/Level.h"
#include "BackGround.h"
#include "GameCamera.h"


//プレイヤー
Player* player = nullptr;
//プレイヤー2
Player2* player2 = nullptr;
//ゲームカメラ
GameCamera* gamecamera = nullptr;
//バックグランド
Background* background = nullptr;

///////////////////////////////////////////////////////////////////
//ゲームの初期化処理
///////////////////////////////////////////////////////////////////
void Game()
{
	//プレイヤーの初期化。
	player = new Player;
	player->SetPosition({ 30.0f,0.0f,0.0f });

	//プレイヤー2の初期化。
	player2 = new Player2;
	player2->SetPosition({ 30.0f,0.0f,0.0f });

	//ゲームカメラの初期化。
	gamecamera = new GameCamera;
	gamecamera->SetPlayer(player);

	//バックグランドの初期化。
	background = new Background;
}

///////////////////////////////////////////////////////////////////
//ゲームの更新処理。
///////////////////////////////////////////////////////////////////
void UpdateGame()
{
	//ゲームパッドの更新。
	for (auto& pad : g_pad) {
		pad.Update();
	}
	//物理エンジンの更新。
	g_physics.Update();
	//プレイヤーの更新。
	player->Update();
	//ゲームカメラの更新。
	gamecamera->Update();
	//プレイヤー2の更新。
	player2->Update();
	//バックグランドの更新。
	background->Update();
}

///////////////////////////////////////////////////////////////////
//ゲームの描画処理。
///////////////////////////////////////////////////////////////////
void RenderGame()
{
	//描画開始。
	g_graphicsEngine->BegineRender();

	//プレイヤーの描画。
	player->Draw();
	//プレイヤー2の描画。
	player2->Draw();
	//バックグランドの描画。
	background->Draw();

	//描画終了。
	g_graphicsEngine->EndRender();
}

///////////////////////////////////////////////////////////////////
//ゲームの終了処理。
///////////////////////////////////////////////////////////////////
void TermnateGame()
{
	//動的に確保したインスタンスを破棄。
	delete player;
	delete player2;
	delete gamecamera;
	delete background;
}
///////////////////////////////////////////////////////////////////
//ウィンドウプログラムのメイン関数。
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//ゲームエンジンの初期化。
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, "Game");
	//ゲームの初期化。
	Game();
	//ゲームループ。
	while (DispatchWindowMessage() == true)
	{
		//ゲームの更新。
		UpdateGame();
		//ゲームの描画処理。
		RenderGame();
	}
	//ゲームの終了処理
	TermnateGame();
}