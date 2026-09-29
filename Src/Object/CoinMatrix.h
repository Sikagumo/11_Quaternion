#pragma once
#include "CoinBase.h"

class CoinMatrix : public CoinBase
{

public:

	// コンストラクタ
	CoinMatrix(void);

	// デストラクタ
	~CoinMatrix(void) override;

	// 更新
	void Update(void) override;

	void Draw(void) override;


protected:

	// ワールド回転
	MATRIX matRot_;

	// ローカル回転
	//(内部的に調整するための回転)
	MATRIX matLocalRot_;

	// パラメータ設定
	void InitTransform(void) override;

	// モデルを行列制御
	void SetMatrixModel(void);

};
