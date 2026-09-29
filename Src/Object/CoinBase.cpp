#include "../Application.h"
#include "CoinBase.h"

CoinBase::CoinBase(void)
{
}

CoinBase::~CoinBase(void)
{
}

void CoinBase::Init(void)
{

	// モデルの読込
	modelId_ = MV1LoadModel((Application::PATH_MODEL + "Coin.mv1").c_str());

	// パラメータ設定
	InitTransform();

}

void CoinBase::Draw(void)
{

	// モデルの描画
	MV1DrawModel(modelId_);

}

void CoinBase::Release(void)
{

	// モデルのメモリ解放
	MV1DeleteModel(modelId_);

}

const VECTOR& CoinBase::GetScl(void) const
{
	return scl_;
}

const VECTOR& CoinBase::GetRot(void) const
{
	return rot_;
}

const VECTOR& CoinBase::GetPos(void) const
{
	return pos_;
}
