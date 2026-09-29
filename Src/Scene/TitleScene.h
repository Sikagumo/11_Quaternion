#pragma once
#include "SceneBase.h"
class Grid;
class CoinMatrix;
class CoinQuaternion;

class TitleScene : public SceneBase
{

public:

	// コンストラクタ
	TitleScene(void);

	// デストラクタ
	~TitleScene(void) override;

	void Init(void) override;
	void Update(void) override;
	void Draw(void) override;
	void DrawDebug(void);
	void Release(void) override;

private:

	// グリッド線
	Grid* grid_;

	// コインの行列回転
	CoinMatrix* coinMatrix_;
	CoinQuaternion* coinQuaternion_;

	// 角度
	float vecRad_;

};
