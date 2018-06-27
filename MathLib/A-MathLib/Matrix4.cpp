#include "Matrix4.h"

#include <assert.h>
#include <math.h>

#include "Vector4.h"
#include "Vector3.h"



Matrix4::Matrix4()
{
	Identity();
}

Matrix4::Matrix4(
	float m00, float m01, float m02, float m03,
	float m10, float m11, float m12, float m13,
	float m20, float m21, float m22, float m23,
	float m30, float m31, float m32, float m33)
{
	m2[0][0] = m00;
	m2[0][1] = m01;
	m2[0][2] = m02;
	m2[0][3] = m03;
			   
	m2[1][0] = m10;
	m2[1][1] = m11;
	m2[1][2] = m12;
	m2[1][3] = m13;
			   
	m2[2][0] = m20;
	m2[2][1] = m21;
	m2[2][2] = m22;
	m2[2][3] = m23;
			   
	m2[3][0] = m30;
	m2[3][1] = m31;
	m2[3][2] = m32;
	m2[3][3] = m33;
}

Matrix4::~Matrix4()
{
}

void Matrix4::Identity()
{
	m2[0][0] = 1.0f;
	m2[0][1] = 0.0f;
	m2[0][2] = 0.0f;
	m2[0][3] = 0.0f;

	m2[1][0] = 0.0f;
	m2[1][1] = 1.0f;
	m2[1][2] = 0.0f;
	m2[1][3] = 0.0f;

	m2[2][0] = 0.0f;
	m2[2][1] = 0.0f;
	m2[2][2] = 1.0f;
	m2[2][3] = 0.0f;

	m2[3][0] = 0.0f;
	m2[3][1] = 0.0f;
	m2[3][2] = 0.0f;
	m2[3][3] = 1.0f;
}

void Matrix4::LocalTransform(Matrix4 posMat, Matrix4 rotMat, Matrix4 scaleMat)
{
	*this = posMat * rotMat * scaleMat;
}

void Matrix4::GlobalTransform(Matrix4 parentsGlobalTransform, Matrix4 localTransform)
{
	*this = parentsGlobalTransform * localTransform;
}

Vector4 Matrix4::operator*(Vector4 rhs)
{
	Vector4 result;
	result.x = (m1[0] * rhs.x) + (m1[4] * rhs.y) + (m1[8] * rhs.z) + (m1[12] * rhs.w);
	result.y = (m1[1] * rhs.x) + (m1[5] * rhs.y) + (m1[9] * rhs.z) + (m1[13] * rhs.w);
	result.z = (m1[2] * rhs.x) + (m1[6] * rhs.y) + (m1[10] * rhs.z) + (m1[14] * rhs.w);
	result.w = (m1[3] * rhs.x) + (m1[7] * rhs.y) + (m1[11] * rhs.z) + (m1[15] * rhs.w);


	return result;
}

Matrix4 Matrix4::operator*(Matrix4 rhs)
{
	Matrix4 result;
	result.m1[0] = (m1[0] * rhs.m1[0]) + (m1[4] * rhs.m1[1]) + (m1[8] * rhs.m1[2]) + (m1[12] * rhs.m1[3]);
	result.m1[1] = (m1[1] * rhs.m1[0]) + (m1[5] * rhs.m1[1]) + (m1[9] * rhs.m1[2]) + (m1[13] * rhs.m1[3]);
	result.m1[2] = (m1[2] * rhs.m1[0]) + (m1[6] * rhs.m1[1]) + (m1[10] * rhs.m1[2]) + (m1[14] * rhs.m1[3]);
	result.m1[3] = (m1[3] * rhs.m1[0]) + (m1[7] * rhs.m1[1]) + (m1[11] * rhs.m1[2]) + (m1[15] * rhs.m1[3]);

	result.m1[4] = (m1[0] * rhs.m1[4]) + (m1[4] * rhs.m1[5]) + (m1[8] * rhs.m1[6]) + (m1[12] * rhs.m1[7]);
	result.m1[5] = (m1[1] * rhs.m1[4]) + (m1[5] * rhs.m1[5]) + (m1[9] * rhs.m1[6]) + (m1[13] * rhs.m1[7]);
	result.m1[6] = (m1[2] * rhs.m1[4]) + (m1[6] * rhs.m1[5]) + (m1[10] * rhs.m1[6]) + (m1[14] * rhs.m1[7]);
	result.m1[7] = (m1[3] * rhs.m1[4]) + (m1[7] * rhs.m1[5]) + (m1[11] * rhs.m1[6]) + (m1[15] * rhs.m1[7]);

	result.m1[8] = (m1[0] * rhs.m1[8]) + (m1[4] * rhs.m1[9]) + (m1[8] * rhs.m1[10]) + (m1[12] * rhs.m1[11]);
	result.m1[9] = (m1[1] * rhs.m1[8]) + (m1[5] * rhs.m1[9]) + (m1[9] * rhs.m1[10]) + (m1[13] * rhs.m1[11]);
	result.m1[10] = (m1[2] * rhs.m1[8]) + (m1[6] * rhs.m1[9]) + (m1[10] * rhs.m1[10]) + (m1[14] * rhs.m1[11]);
	result.m1[11] = (m1[3] * rhs.m1[8]) + (m1[7] * rhs.m1[9]) + (m1[11] * rhs.m1[10]) + (m1[15] * rhs.m1[11]);

	result.m1[12] = (m1[0] * rhs.m1[12]) + (m1[4] * rhs.m1[13]) + (m1[8] * rhs.m1[14]) + (m1[12] * rhs.m1[15]);
	result.m1[13] = (m1[1] * rhs.m1[12]) + (m1[5] * rhs.m1[13]) + (m1[9] * rhs.m1[14]) + (m1[13] * rhs.m1[15]);
	result.m1[14] = (m1[2] * rhs.m1[12]) + (m1[6] * rhs.m1[13]) + (m1[10] * rhs.m1[14]) + (m1[14] * rhs.m1[15]);
	result.m1[15] = (m1[3] * rhs.m1[12]) + (m1[7] * rhs.m1[13]) + (m1[11] * rhs.m1[14]) + (m1[15] * rhs.m1[15]);

	return result;
}

Vector4& Matrix4::operator[](int nIndex)
{
	assert(nIndex >= 0 && "ERROR: Negative Index");
	assert(nIndex <= 4 && "ERROR: Index is past the end of the array");

	return vec4[nIndex];
}

Matrix4::operator float*()
{
	return &m1[0];
}

void Matrix4::setRotateX(float fRadians)
{
	m2[1][1] = cosf(fRadians);
	m2[1][2] = sinf(fRadians);

	m2[2][1] = -sinf(fRadians);
	m2[2][2] = cosf(fRadians);
}
void Matrix4::setRotateY(float fRadians)
{
	m2[0][0] = cosf(fRadians);
	m2[0][2] = -sinf(fRadians);

	m2[2][0] = sinf(fRadians);
	m2[2][2] = cosf(fRadians);
}
void Matrix4::setRotateZ(float fRadians)
{
	m2[0][0] = cosf(fRadians);
	m2[0][1] = sinf(fRadians);

	m2[1][0] = -sinf(fRadians);
	m2[1][1] = cosf(fRadians);
}

void Matrix4::SetPosition(float x, float y, float z)
{
	vec4[3].x = x;
	vec4[3].y = y;
	vec4[3].z = z;
}
void Matrix4::SetPosition(Vector3 pos)
{
	vec4[3].x = pos.x;
	vec4[3].y = pos.y;
	vec4[3].z = pos.z;
}

void Matrix4::SetScale(float x, float y, float z)
{
	m2[0][0] = x;
	m2[1][1] = y;
	m2[2][2] = z;
}
void Matrix4::SetScale(Vector3 scale)
{
	m2[0][0] = scale.x;
	m2[1][1] = scale.y;
	m2[2][2] = scale.z;
}

Vector3 Matrix4::GetPosition()
{
	Vector3 result;
	result.x = vec4[3].x;
	result.y = vec4[3].y;
	result.z = vec4[3].z;

	return result;
}

Vector3 Matrix4::GetRight()
{
	Vector3 result;
	result.x = vec4[0].x;
	result.y = vec4[0].y;
	result.z = vec4[0].z;

	return result;
}

Vector3 Matrix4::GetUp()
{
	Vector3 result;
	result.x = vec4[1].x;
	result.y = vec4[1].y;
	result.z = vec4[1].z;

	return result;
}

Vector3 Matrix4::GetFacing()
{
	Vector3 result;
	result.x = vec4[2].x;
	result.y = vec4[2].y;
	result.z = vec4[2].z;

	return result;
}