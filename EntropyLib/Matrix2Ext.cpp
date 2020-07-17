#include "Matrix2Ext.h"

#include <cmath>

Entropy::Math::Vec2 Entropy::Math::operator*(const Matrix2& left, const Vec2& right)
{
    return Vec2(
        left.r0c0 * right.I + left.r0c1 * right.J,
        left.r1c0 * right.I + left.r1c1 * right.J
    );
}

Entropy::Math::Matrix2 Entropy::Math::ScaleMatrix2(const Vec2 & scaleVector)
{
    return Matrix2(
        scaleVector.I, 0.0f,
        0.0f, scaleVector.J
    );
}

Entropy::Math::Matrix2 Entropy::Math::ScaleMatrix2(float sX, float sY)
{
    return Matrix2(
        sX, 0.0f,
        0.0f, sY
    );
}

Entropy::Math::Matrix2 Entropy::Math::ScaleMatrix2(float scale)
{
    return Matrix2(
        scale, 0.0f,
        0.0f, scale
    );
}

Entropy::Math::Matrix2 Entropy::Math::RotationMatrix2(float angle)
{
    return Matrix2(
        cos(angle), -sin(angle),
        sin(angle), cos(angle)
    );
}