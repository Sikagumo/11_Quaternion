#include "MatrixUtility.h"

MATRIX MatrixUtility::GetMatrixRotateXYZ(const VECTOR& euler)
{
	MATRIX ret = MGetIdent();
	ret = MMult(ret, MGetRotX(euler.x));
	ret = MMult(ret, MGetRotY(euler.y));
	ret = MMult(ret, MGetRotZ(euler.z));
    return ret;
}

MATRIX MatrixUtility::Multiplication(const MATRIX& child, const MATRIX& parent)
{
	return MMult(child, parent);
}

MATRIX MatrixUtility::Multiplication(const VECTOR& childEuler, const VECTOR& parentEuler)
{
	MATRIX parent = MatrixUtility::GetMatrixRotateXYZ(parentEuler);
	MATRIX child = MatrixUtility::GetMatrixRotateXYZ(childEuler);
	return MMult(child, parent);
}

MATRIX MatrixUtility::CreateTransformMatrix(const VECTOR& scl, const VECTOR& rot, const VECTOR& localRot, const VECTOR& pos)
{
    // 大きさ
    MATRIX matScl = MGetScale(scl);

    // 回転(ローカル回転とワールド回転を合成)
    MATRIX mixMatRot = Multiplication(localRot, rot);

    // 位置
    MATRIX matPos = MGetTranslate(pos);


    // 行列の合成
    //---------------------------------
    MATRIX mat = MGetIdent();

    // 大きさ
    mat = MMult(mat, matScl);

    // 回転
    mat = MMult(mat, mixMatRot);

    // 位置
    mat = MMult(mat, matPos);
    

    return mat;
}
