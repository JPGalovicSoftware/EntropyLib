#include <gtest/gtest.h>
#include <Vector4.h>

using namespace Entropy::Math;

TEST(Vector4, Constructor)
{
	Vector4 empty;
	Vector4 unit(1, 1, 1, 1);
	Vector4 value(2, 3, 4, 5);

	EXPECT_EQ(0, empty.i);
	EXPECT_EQ(0, empty.j);
	EXPECT_EQ(0, empty.k);
	EXPECT_EQ(0, empty.l);

	EXPECT_EQ(1, unit.i);
	EXPECT_EQ(1, unit.j);
	EXPECT_EQ(1, unit.k);
	EXPECT_EQ(1, unit.l);

	EXPECT_EQ(2, value.i);
	EXPECT_EQ(3, value.j);
	EXPECT_EQ(4, value.k);
	EXPECT_EQ(5, value.l);
}

TEST(Vector4, VectorAddition)
{
	Vector4 a(2, 3, 4, 5);
	Vector4 b(4, 5, 6, 7);

	Vector4 result1 = a + b;
	Vector4 result2 = b + a;

	EXPECT_FLOAT_EQ(6, result1.i);
	EXPECT_FLOAT_EQ(8, result1.j);
	EXPECT_FLOAT_EQ(10, result1.k);
	EXPECT_FLOAT_EQ(12, result1.l);

	EXPECT_FLOAT_EQ(result1.i, result2.i);
	EXPECT_FLOAT_EQ(result1.j, result2.j);
	EXPECT_FLOAT_EQ(result1.k, result2.k);
	EXPECT_FLOAT_EQ(result1.l, result2.l);
}

TEST(Vector4, VectorSubtraction)
{
	Vector4 a(2, 3, 4, 5);
	Vector4 b(4, 5, 6, 7);

	Vector4 result1 = a - b;
	Vector4 result2 = b - a;

	EXPECT_FLOAT_EQ(-2, result1.i);
	EXPECT_FLOAT_EQ(-2, result1.j);
	EXPECT_FLOAT_EQ(-2, result1.k);
	EXPECT_FLOAT_EQ(-2, result1.l);

	EXPECT_FLOAT_EQ(2, result2.i);
	EXPECT_FLOAT_EQ(2, result2.j);
	EXPECT_FLOAT_EQ(2, result2.k);
	EXPECT_FLOAT_EQ(2, result2.l);
}

TEST(Vector4, ScalarMultiplycation)
{
	Vector4 a(2, 3, 4, 5);
	float scalar = 3;

	Vector4 result1 = a * scalar;
	Vector4 result2 = scalar * a;

	EXPECT_FLOAT_EQ(6, result1.i);
	EXPECT_FLOAT_EQ(9, result1.j);
	EXPECT_FLOAT_EQ(12, result1.k);
	EXPECT_FLOAT_EQ(15, result1.l);

	EXPECT_FLOAT_EQ(result1.i, result2.i);
	EXPECT_FLOAT_EQ(result1.j, result2.j);
	EXPECT_FLOAT_EQ(result1.k, result2.k);
	EXPECT_FLOAT_EQ(result1.l, result2.l);
}

TEST(Vector4, AssignmentOperator)
{
	Vector4 source(-1, 7, 4, 3);
	Vector4 copy(source);
	EXPECT_FLOAT_EQ(source.i, copy.i);
	EXPECT_FLOAT_EQ(source.j, copy.j);
	EXPECT_FLOAT_EQ(source.k, copy.k);
	EXPECT_FLOAT_EQ(source.l, copy.l);
}

TEST(Vector4, PlusAssignmentOperator)
{
	Vector4 a(-1, 7, 4, 3);
	Vector4 b(-5, 8, 4, -1);

	EXPECT_FLOAT_EQ(-1, a.i);
	EXPECT_FLOAT_EQ(7, a.j);
	EXPECT_FLOAT_EQ(4, a.k);
	EXPECT_FLOAT_EQ(3, a.l);

	a += b;

	EXPECT_FLOAT_EQ(-6, a.i);
	EXPECT_FLOAT_EQ(15, a.j);
	EXPECT_FLOAT_EQ(8, a.k);
	EXPECT_FLOAT_EQ(2, a.l);
}

TEST(Vector4, MinusAssignmentOperator)
{
	Vector4 a(-1, 7, 4, 3);
	Vector4 b(-5, 8, 4, -1);

	EXPECT_FLOAT_EQ(-1, a.i);
	EXPECT_FLOAT_EQ(7, a.j);
	EXPECT_FLOAT_EQ(4, a.k);
	EXPECT_FLOAT_EQ(4, a.k);

	a -= b;

	EXPECT_FLOAT_EQ(4, a.i);
	EXPECT_FLOAT_EQ(-1, a.j);
	EXPECT_FLOAT_EQ(0, a.k);
	EXPECT_FLOAT_EQ(4, a.l);
}