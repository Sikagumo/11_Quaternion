#pragma once
#include "CoinBase.h"
#include "../Common/Quaternion.h"

class CoinQuaternion : public CoinBase
{

public:

	// コンストラクタ
	CoinQuaternion(void);

	// デストラクタ
	~CoinQuaternion(void) override = default;

	// 更新
	void Update(void) override;

	// 描画
	void Draw(void) override;


protected:

	// ワールド回転
	Quaternion quaRot_;

	// ローカル回転
	//(内部的に調整するための回転)
	Quaternion quaLocalRot_;

	float rotX_;
	float rotY_;
	// パラメータ設定
	void InitTransform(void) override;

	// モデルを行列制御
	void SetMatrixModel(void);
};
