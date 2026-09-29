#pragma once
#include <DxLib.h>
#include "../Common/Quaternion.h"

class CoinBase
{

public:

	// 大きさ
	static constexpr float SCALE = 50.0f;

	// コンストラクタ
	CoinBase(void);

	// デストラクタ
	virtual ~CoinBase(void);

	virtual void Init(void);
	virtual void Update(void) = 0;
	virtual void Draw(void);
	virtual void Release(void);

	const VECTOR& GetScl(void) const;
	const VECTOR& GetRot(void) const;
	const VECTOR& GetPos(void) const;

protected:

	// コインのモデルID
	int modelId_;

	// 大きさ
	VECTOR scl_;

	// 回転
	VECTOR rot_;
	VECTOR localRot_;

	// 座標
	VECTOR pos_;

	// Transform初期化
	virtual void InitTransform(void) = 0;

};

