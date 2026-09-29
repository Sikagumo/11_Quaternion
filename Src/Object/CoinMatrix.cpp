#include "../Utility/AsoUtility.h"
#include "../Utility/MatrixUtility.h"
#include "CoinMatrix.h"

CoinMatrix::CoinMatrix(void)
{
}

CoinMatrix::~CoinMatrix(void)
{
}

void CoinMatrix::Update(void)
{
    rot_.x += AsoUtility::Deg2RadF(2.0f);
    rot_.y = AsoUtility::Deg2RadF(45.0f);
    rot_.z += AsoUtility::Deg2RadF(2.0f);

    // モデルを行列制御
    SetMatrixModel();
}

void CoinMatrix::Draw(void)
{
    MV1SetDifColorScale(modelId_, { 1.0f,0.25f, 0.25f, 1.0f });
    CoinBase::Draw();

    matRot_ = MatrixUtility::GetMatrixRotateXYZ(rot_);
    AsoUtility::DrawLineXYZ(pos_, matRot_,100.0f);
}

void CoinMatrix::InitTransform(void)
{

    // 大きさ
    scl_ = { SCALE, SCALE, SCALE };

    // 回転
    rot_ = { 0.0f, 0.0f, 0.0f };
    localRot_ = { AsoUtility::Deg2RadF(90.0f), 0.0f, AsoUtility::Deg2RadF(180.0f) };

    // 位置
    pos_ = { 0.0f, 100.0f, 0.0f };

    // ワールド回転
    matRot_ = MGetIdent();
    matRot_ = MMult(matRot_, MGetRotX(rot_.x));
    matRot_ = MMult(matRot_, MGetRotY(rot_.y));
    matRot_ = MMult(matRot_, MGetRotZ(rot_.z));

    // ローカル回転
    matLocalRot_ = MGetIdent();
    matLocalRot_ = MMult(matLocalRot_, MGetRotX(localRot_.x));
    matLocalRot_ = MMult(matLocalRot_, MGetRotY(localRot_.y));
    matLocalRot_ = MMult(matLocalRot_, MGetRotZ(localRot_.z));

}

void CoinMatrix::SetMatrixModel(void)
{
    MATRIX mat = MatrixUtility::CreateTransformMatrix(scl_, rot_, localRot_, pos_);

    // 行列(大きさ、回転、位置)をモデルに設定
    MV1SetMatrix(modelId_, mat);

}
