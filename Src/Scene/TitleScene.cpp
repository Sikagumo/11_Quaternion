#include <cmath>
#include <DxLib.h>
#include "../Application.h"
#include "../Utility/AsoUtility.h"
#include "../Manager/InputManager.h"
#include "../Manager/SceneManager.h"
#include "../Manager/Camera.h"
#include "../Object/Grid.h"
#include "../Object/CoinMatrix.h"
#include "../Object/CoinQuaternion.h"
#include "TitleScene.h"

TitleScene::TitleScene(void) : SceneBase()
{
	grid_ = nullptr;
}

TitleScene::~TitleScene(void)
{
}

void TitleScene::Init(void)
{

	// カメラモード変更
	Camera* camera = SceneManager::GetInstance().GetCamera();
	camera->ChangeMode(Camera::MODE::FREE);

	// グリッド初期化
	grid_ = new Grid();
	grid_->Init();

	// コインの行列回転
	coinMatrix_ = new CoinMatrix();
	coinMatrix_->Init();

	// コインの行列回転
	coinQuaternion_ = new CoinQuaternion();
	coinQuaternion_->Init();

}

void TitleScene::Update(void)
{

	// グリッド更新
	grid_->Update();

	// コイン(行列)
	coinMatrix_->Update();

	coinQuaternion_->Update();
}

void TitleScene::Draw(void)
{
	
	// グリッド描画
	grid_->Draw();

	// コイン(行列)
	coinMatrix_->Draw();

	coinQuaternion_->Draw();

	// デバッグ表示
	DrawDebug();

}

void TitleScene::DrawDebug(void)
{

	VECTOR pos = coinMatrix_->GetPos();
	VECTOR rot = coinMatrix_->GetRot();

	DrawFormatString(
		0, 10, 0xff4444,
		"コイン座標　 ：(%.1f, %.1f, %.1f)",
		pos.x, pos.y, pos.z
	);
	DrawFormatString(
		0, 30, 0xff4444,
		"コイン角度　 ：(%.1f, %.1f, %.1f)",
		AsoUtility::Rad2DegF(rot.x),
		AsoUtility::Rad2DegF(rot.y),
		AsoUtility::Rad2DegF(rot.z)
	);

	pos = coinQuaternion_->GetPos();
	rot = coinQuaternion_->GetRot();

	DrawFormatString(
		0, 70, 0xffffff,
		"コイン座標　 ：(%.1f, %.1f, %.1f)",
		pos.x, pos.y, pos.z
	);
	DrawFormatString(
		0, 90, 0xffffff,
		"コイン角度　 ：(%.1f, %.1f, %.1f)",
		AsoUtility::Rad2DegF(rot.x),
		AsoUtility::Rad2DegF(rot.y),
		AsoUtility::Rad2DegF(rot.z)
	);

}

void TitleScene::Release(void)
{

	// グリッド解放
	grid_->Release();
	delete grid_;

	// コイン(行列)解放
	coinMatrix_->Release();
	delete coinMatrix_;

}
