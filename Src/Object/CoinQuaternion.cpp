#include "CoinQuaternion.h"
#include "../Utility/AsoUtility.h"
#include "../Utility/MatrixUtility.h"


CoinQuaternion::CoinQuaternion(void)
{
}

void CoinQuaternion::InitTransform(void)
{
	// ëÂÇ´Ç≥
	scl_ = { SCALE, SCALE, SCALE };
	// âÒì]
	rot_ = { 0.0f, 0.0f, 0.0f };
	localRot_ = { AsoUtility::Deg2RadF(-90.0f),
				 AsoUtility::Deg2RadF(180.0f),
				 0.0f };

	// à íu
	pos_ = { 0.0f, 200.0f, 0.0f };

	rotX_ = 0.0f;
	rotY_ = 0.0f;

	// ÉèÅ[ÉãÉhâÒì]
	quaRot_ = Quaternion::Identity();

	// ÉçÅ[ÉJÉãâÒì]
	quaLocalRot_ = Quaternion::Identity();

	//quaLocalRot_ = Quaternion::Mult(
	//	quaLocalRot_, Quaternion::AngleAxis(localRot_.y, AsoUtility::AXIS_Y));

	//quaLocalRot_ = Quaternion::Mult(
	//	quaLocalRot_, Quaternion::AngleAxis(localRot_.x, AsoUtility::AXIS_X));

	//quaLocalRot_ = Quaternion::Mult(
	//	quaLocalRot_, Quaternion::AngleAxis(localRot_.z, AsoUtility::AXIS_Z));

	// áEYé≤âÒì]å≈íË
	quaRot_.w = 1.0f;
	quaRot_ = Quaternion::Mult(quaRot_, Quaternion::AngleAxis(AsoUtility::Deg2RadF(90.0f), AsoUtility::AXIS_Y));
	quaRot_ = Quaternion::Mult(quaRot_, Quaternion::AngleAxis(AsoUtility::Deg2RadF(45.0f), AsoUtility::AXIS_X));
	
	//quaRot_ = Quaternion::Mult(quaRot_, Quaternion::AngleAxis(AsoUtility::Deg2RadF(90.0f), AsoUtility::AXIS_X));
	//quaRot_ = Quaternion::Mult(quaRot_, Quaternion::AngleAxis(AsoUtility::Deg2RadF(90.0f), AsoUtility::AXIS_Z));

}

void CoinQuaternion::Update(void)
{
	rotY_ = ((CheckHitKey(KEY_INPUT_J)) ? 1.0f : 0.0f);
	rotY_ = ((CheckHitKey(KEY_INPUT_L)) ? -1.0f : rotY_);

	//rotX_ += ((CheckHitKey(KEY_INPUT_I)) ? 1.0f : 0.0f);
	//rotX_ += ((CheckHitKey(KEY_INPUT_K)) ? -1.0f : 0.0f);


	//quaRot_ = Quaternion::Identity();
	quaRot_.y = AsoUtility::Deg2RadF(45.0f);
	quaRot_ = Quaternion::Mult(quaRot_, Quaternion::AngleAxis(AsoUtility::Deg2RadF(rotY_), quaRot_.GetUp()));
	//quaRot_ = Quaternion::Mult(quaRot_, Quaternion::AngleAxis(AsoUtility::Deg2RadF(rotX_), AsoUtility::AXIS_X));
	//quaRot_ = Quaternion::Mult(quaRot_, Quaternion::AngleAxis(AsoUtility::Deg2RadF(0.0f), AsoUtility::AXIS_Z));
	// áCâÒì]
	//quaRot_ = Quaternion::Mult(quaRot_, Quaternion::AngleAxis(AsoUtility::Deg2RadF(1.0f), AsoUtility::AXIS_X));

	// áDâÒì]
	//quaRot_ = Quaternion::Mult(quaRot_, Quaternion::AngleAxis(AsoUtility::Deg2RadF(1.0f), AsoUtility::AXIS_Z));

	// áEXYâÒì]
	//quaRot_ = Quaternion::Mult(quaRot_, Quaternion::AngleAxis(AsoUtility::Deg2RadF(1.0f), AsoUtility::AXIS_Y));	//quaRot_ = Quaternion::Mult(quaRot_, Quaternion::AngleAxis(AsoUtility::Deg2RadF(1.0f), AsoUtility::AXIS_X));
	
	// áFâÒì]
	//quaRot_ = Quaternion::Mult(quaRot_, Quaternion::AngleAxis(AsoUtility::Deg2RadF(1.0f), AsoUtility::AXIS_X));	//quaRot_ = Quaternion::Mult(quaRot_, Quaternion::AngleAxis(AsoUtility::Deg2RadF(1.0f), AsoUtility::AXIS_X));
	//quaRot_ = Quaternion::Mult(quaRot_, Quaternion::AngleAxis(AsoUtility::Deg2RadF(1.0f), AsoUtility::AXIS_Y));

	// áEâÒì]
	//quaRot_ = Quaternion::Mult(quaRot_, Quaternion::AngleAxis(AsoUtility::Deg2RadF(1.0f), AsoUtility::AXIS_Z));	//quaRot_ = Quaternion::Mult(quaRot_, Quaternion::AngleAxis(AsoUtility::Deg2RadF(1.0f), AsoUtility::AXIS_X));
	//quaRot_ = Quaternion::Mult(quaRot_, Quaternion::AngleAxis(AsoUtility::Deg2RadF(1.0f), AsoUtility::AXIS_Y));
	

	// ÉÇÉfÉãÇçsóÒêßå‰
	SetMatrixModel();
}

void CoinQuaternion::Draw(void)
{
	CoinBase::Draw();
	// å¸Ç´ÇÃï`âÊ
	AsoUtility::DrawLineXYZ(pos_, quaRot_);
}


void CoinQuaternion::SetMatrixModel(void)
{
	// çsóÒ
	MATRIX mat = MatrixUtility::CreateTransformMatrix(scl_, rot_, localRot_, pos_);

	// çsóÒ(ëÂÇ´Ç≥ÅAäpìxÅAà íu)ÇÉÇÉfÉãÇ…ê›íË
	MV1SetMatrix(modelId_, mat);

	// ÉIÉCÉâÅ[äpÇãÅÇﬂÇÈ
	rot_ = quaRot_.ToEuler();
}