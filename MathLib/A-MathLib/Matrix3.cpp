#include "Matrix3.h"

#include <assert.h>
#include <math.h>

#include "Vector2.h"
#include "Vector3.h"



Matrix3::Matrix3()
{
	Identity();
}

Matrix3::Matrix3(
	float m00, float m01, float m02,
	float m10, float m11, float m12,
	float m20, float m21, float m22)
{
	m2[0][0] = m00;
	m2[0][1] = m01;
	m2[0][2] = m02;
			  
	m2[1][0] = m10;
	m2[1][1] = m11;
	m2[1][2] = m12;
			  
	m2[2][0] = m20;
	m2[2][1] = m21;
	m2[2][2] = m22;
}

Matrix3::~Matrix3()
{
}

void Matrix3::Identity()
{
	m2[0][0] = 1.0f;
	m2[0][1] = 0.0f;
	m2[0][2] = 0.0f;

	m2[1][0] = 0.0f;
	m2[1][1] = 1.0f;
	m2[1][2] = 0.0f;

	m2[2][0] = 0.0f;
	m2[2][1] = 0.0f;
	m2[2][2] = 1.0f;
}

void Matrix3::LocalTransform(Matrix3 posMat, Matrix3 rotMat, Matrix3 scaleMat)
{
	*this = posMat * rotMat * scaleMat;
}

void Matrix3::GlobalTransform(Matrix3 parentsGlobalTransform, Matrix3 localTransform)
{
	*this = parentsGlobalTransform * localTransform;
}

Vector3 Matrix3::operator*(Vector3 rhs)
{
	Vector3 result;
	result.x = (m1[0] * rhs.x) + (m1[3] * rhs.y) + (m1[6] * rhs.z);
	result.y = (m1[1] * rhs.x) + (m1[4] * rhs.y) + (m1[7] * rhs.z);
	result.z = (m1[2] * rhs.x) + (m1[5] * rhs.y) + (m1[8] * rhs.z);

	return result;
}

Matrix3 Matrix3::operator*(Matrix3 rhs)
{
	Matrix3 result;
	result.m1[0] = (m1[0] * rhs.m1[0]) + (m1[3] * rhs.m1[1]) + (m1[6] * rhs.m1[2]);
	result.m1[1] = (m1[1] * rhs.m1[0]) + (m1[4] * rhs.m1[1]) + (m1[7] * rhs.m1[2]);
	result.m1[2] = (m1[2] * rhs.m1[0]) + (m1[5] * rhs.m1[1]) + (m1[8] * rhs.m1[2]);

	result.m1[3] = (m1[0] * rhs.m1[3]) + (m1[3] * rhs.m1[4]) + (m1[6] * rhs.m1[5]);
	result.m1[4] = (m1[1] * rhs.m1[3]) + (m1[4] * rhs.m1[4]) + (m1[7] * rhs.m1[5]);
	result.m1[5] = (m1[2] * rhs.m1[3]) + (m1[5] * rhs.m1[4]) + (m1[8] * rhs.m1[5]);

	result.m1[6] = (m1[0] * rhs.m1[6]) + (m1[3] * rhs.m1[7]) + (m1[6] * rhs.m1[8]);
	result.m1[7] = (m1[1] * rhs.m1[6]) + (m1[4] * rhs.m1[7]) + (m1[7] * rhs.m1[8]);
	result.m1[8] = (m1[2] * rhs.m1[6]) + (m1[5] * rhs.m1[7]) + (m1[8] * rhs.m1[8]);

	return result;
}

Vector3& Matrix3::operator[](int nIndex)
{
	assert(nIndex >= 0 && "ERROR: Negative Index");
	assert(nIndex <= 3 && "ERROR: Index is past the end of the array");

	return vec3[nIndex];
}

Matrix3::operator float*()
{
	return &m1[0];
}

void Matrix3::setRotateX(float fRadians)
{
	m2[1][1] = cosf(fRadians);
	m2[1][2] = sinf(fRadians);

	m2[2][1] = -sinf(fRadians);
	m2[2][2] = cosf(fRadians);
}
void Matrix3::setRotateY(float fRadians)
{
	m2[0][0] = cosf(fRadians);
	m2[0][2] = -sinf(fRadians);

	m2[2][0] = sinf(fRadians);
	m2[2][2] = cosf(fRadians);
}
void Matrix3::setRotateZ(float fRadians)
{
	m2[0][0] = cosf(fRadians);
	m2[0][1] = sinf(fRadians);

	m2[1][0] = -sinf(fRadians);
	m2[1][1] = cosf(fRadians);
}

void Matrix3::SetRotate2D(float fRadians)
{
	m2[0][0] = cosf(fRadians);
	m2[0][1] = sinf(fRadians);

	m2[1][0] = -sinf(fRadians);
	m2[1][1] = cosf(fRadians);
}

void Matrix3::SetPosition(float x, float y)
{
	vec3[2].x = x;
	vec3[2].y = y;
}
void Matrix3::SetPosition(Vector2 pos)
{
	vec3[2].x = pos.x;
	vec3[2].y = pos.y;
}

void Matrix3::SetScale(float x, float y)
{
	m2[0][0] = x;
	m2[1][1] = y;
}
void Matrix3::SetScale(Vector2 scale)
{
	m2[0][0] = scale.x;
	m2[1][1] = scale.y;
}

Vector2 Matrix3::GetPosition()
{
	Vector2 result;
	result.x = vec3[2].x;
	result.y = vec3[2].y;

	return result;
}

Vector2 Matrix3::GetRight()
{
	Vector2 result;
	result.x = vec3[0].x;
	result.y = vec3[0].y;

	return result;
}

Vector2 Matrix3::GetUp()
{
	Vector2 result;
	result.x = vec3[1].x;
	result.y = vec3[1].y;

	return result;
}

Vector2 Matrix3::GetFacing2D()
{
	Vector2 result;
	result.x = vec3[1].x;
	result.y = vec3[1].y;

	return result;
}