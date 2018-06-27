#include "Matrix2.h"

#include <assert.h>
#include <math.h>

#include "Vector2.h"
#include "Vector3.h"



Matrix2::Matrix2()
{
	Identity();
}

Matrix2::Matrix2(
	float m00, float m01,
	float m10, float m11)
{
	m2[0][0] = m00;
	m2[0][1] = m01;

	m2[1][0] = m10;
	m2[1][1] = m11;
}

Matrix2::~Matrix2()
{
}

void Matrix2::Identity()
{
	m2[0][0] = 1.0f;
	m2[0][1] = 0.0f;

	m2[1][0] = 0.0f;
	m2[1][1] = 1.0f;
}

Vector2 Matrix2::operator*(Vector2 rhs)
{
	Vector2 result;
	result.x = (m1[0] * rhs.x) + (m1[2] * rhs.y);
	result.y = (m1[1] * rhs.x) + (m1[3] * rhs.y);

	return result;
}

Matrix2 Matrix2::operator*(Matrix2 rhs)
{
	Matrix2 result;
	result.m1[0] = (m1[0] * rhs.m1[0]) + (m1[2] * rhs.m1[1]);
	result.m1[1] = (m1[1] * rhs.m1[0]) + (m1[3] * rhs.m1[1]);

	result.m1[2] = (m1[0] * rhs.m1[2]) + (m1[2] * rhs.m1[3]);
	result.m1[3] = (m1[1] * rhs.m1[2]) + (m1[3] * rhs.m1[3]);

	return result;
}

Vector2& Matrix2::operator[](int nIndex)
{
	assert(nIndex >= 0 && "ERROR: Negative Index");
	assert(nIndex <= 2 && "ERROR: Index is past the end of the array");

	return vec2[nIndex];
}

Matrix2::operator float*()
{
	return &m1[0];
}

void Matrix2::setRotate(float fRadians)
{
	m2[0][0] = cosf(fRadians);
	m2[0][1] = sinf(fRadians);

	m2[1][0] = -sinf(fRadians);
	m2[1][1] = cosf(fRadians);
}

Vector2 Matrix2::GetRight()
{
	Vector2 result;
	result.x = vec2[0].x;
	result.y = vec2[0].y;

	return result;
}

Vector2 Matrix2::GetUp()
{
	Vector2 result;
	result.x = vec2[1].x;
	result.y = vec2[1].y;

	return result;
}