#include "Vector3.h"
#include "Vector2.h"
#include "Vector4.h"
#include <math.h>
#include <assert.h>


Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3()
{
}

//------------------------------------------------------
//	One
//		Sets components to 1
//------------------------------------------------------
void Vector3::One()
{
	x = 1.0f;
	y = 1.0f;
	z = 1.0f;
}

//------------------------------------------------------
//	Zero
//		Sets components to 0
//------------------------------------------------------
void Vector3::Zero()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

//------------------------------------------------------
//	Right
//		Sets x to 1
//		all others set to 0
//------------------------------------------------------
void Vector3::Right()
{
	x = 1.0f;
	y = 0.0f;
	z = 0.0f;
}

//------------------------------------------------------
//	Left
//		Sets x to -1
//		all others set to 0
//------------------------------------------------------
void Vector3::Left()
{
	x = -1.0f;
	y = 0.0f;
	z = 0.0f;
}

//------------------------------------------------------
//	Up
//		Sets y to 1
//		all others set to 0
//------------------------------------------------------
void Vector3::Up()
{
	x = 0.0f;
	y = 1.0f;
	z = 0.0f;
}

//------------------------------------------------------
//	Down
//		Sets y to -1
//		all others set to 0
//------------------------------------------------------
void Vector3::Down()
{
	x = 0.0f;
	y = -1.0f;
	z = 0.0f;
}

//------------------------------------------------------
//	Forward
//		Sets z to 1
//		all others set to 0
//------------------------------------------------------
void Vector3::Forward()
{
	x = 0.0f;
	y = 0.0f;
	z = 1.0f;
}

//------------------------------------------------------
//	Back
//		Sets z to -1
//		all others set to 0
//------------------------------------------------------
void Vector3::Back()
{
	x = 0.0f;
	y = 0.0f;
	z = -1.0f;
}

//------------------------------------------------------
//	operator+
//		Overloads - operator
//
//		Allows Integer promotion of Vectors
//------------------------------------------------------
Vector3 Vector3::operator+()
{
	Vector3 outVec;
	outVec.x = +(this->x);
	outVec.y = +(this->y);
	outVec.z = +(this->z);

	return outVec;
}

//------------------------------------------------------
//	operator-
//		Overloads - operator
//
//		Allows Inverse of Vector
//------------------------------------------------------
Vector3 Vector3::operator-()
{
	Vector3 outVec;
	outVec.x = -(this->x);
	outVec.y = -(this->y);
	outVec.z = -(this->z);

	return outVec;
}

//------------------------------------------------------
//	operator+
//		Overloads + operator
//
//		Allows Addition of Vectors
//------------------------------------------------------
Vector3 Vector3::operator+(Vector3 rhs)
{
	Vector3 outVec;
	outVec.x = this->x + rhs.x;
	outVec.y = this->y + rhs.y;
	outVec.z = this->z + rhs.z;

	return outVec;
}

//------------------------------------------------------
//	operator-
//		Overloads - operator
//
//		Allows Subtraction of Vectors
//------------------------------------------------------
Vector3 Vector3::operator-(Vector3 rhs)
{
	Vector3 outVec;
	outVec.x = this->x - rhs.x;
	outVec.y = this->y - rhs.y;
	outVec.z = this->z - rhs.z;

	return outVec;
}

//------------------------------------------------------
//	operator*
//		Overloads * operator
//
//		Allows Multiplication of Vector by rhs scalar
//------------------------------------------------------
Vector3 Vector3::operator*(float scalar)
{
	Vector3 outVec;
	outVec.x = this->x * scalar;
	outVec.y = this->y * scalar;
	outVec.z = this->z * scalar;

	return outVec;
}

//------------------------------------------------------
//	operator+=
//		Overloads += operator
//
//		Allows Addition assignment of Vectors
//------------------------------------------------------
Vector3& Vector3::operator+=(Vector3 rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;

	return *this;
}

//------------------------------------------------------
//	operator-
//		Overloads - operator
//
//		Allows Subtraction assignment of Vectors
//------------------------------------------------------
Vector3& Vector3::operator-=(Vector3 rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;

	return *this;
}

//------------------------------------------------------
//	operator*
//		Overloads * operator
//
//		Allows Multiplication assignment of Vector by 
//		rhs scalar
//------------------------------------------------------
Vector3& Vector3::operator*=(float scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;

	return *this;
}

//------------------------------------------------------
//	operator==
//		Overloads == operator
//
//		Allows 'Equal to' relational operator to check 
//		Vectors against each other
//------------------------------------------------------
bool Vector3::operator==(Vector3 rhs)
{
	if (this->x == rhs.x)
	{
		if (this->y == rhs.y)
		{
			if (this->z == rhs.z)
			{
				return true;
			}
		}
	}
	return false;
}

//------------------------------------------------------
//	operator>
//		Overloads > operator
//
//		Allows 'greater than' relational operator to check 
//		Vectors against each other
//------------------------------------------------------
bool Vector3::operator>(Vector3 rhs)
{
	if (this->x > rhs.x)
	{
		if (this->y > rhs.y)
		{
			if (this->z > rhs.z)
			{
				return true;
			}
		}
	}
	return false;
}

//------------------------------------------------------
//	operator>=
//		Overloads >= operator
//
//		Allows 'greater than or equals' relational operator to check 
//		Vectors against each other
//------------------------------------------------------
bool Vector3::operator>=(Vector3 rhs)
{
	if (this->x >= rhs.x)
	{
		if (this->y >= rhs.y)
		{
			if (this->z >= rhs.z)
			{
				return true;
			}
		}
	}
	return false;
}

//------------------------------------------------------
//	operator<
//		Overloads < operator
//
//		Allows 'less than' relational operator to check 
//		Vectors against each other
//------------------------------------------------------
bool Vector3::operator<(Vector3 rhs)
{
	if (this->x < rhs.x)
	{
		if (this->y < rhs.y)
		{
			if (this->z < rhs.z)
			{
				return true;
			}
		}
	}
	return false;
}

//------------------------------------------------------
//	operator<=
//		Overloads <= operator
//
//		Allows 'less than or equals' relational operator to check 
//		Vectors against each other
//------------------------------------------------------
bool Vector3::operator<=(Vector3 rhs)
{
	if (this->x <= rhs.x)
	{
		if (this->y <= rhs.y)
		{
			if (this->z <= rhs.z)
			{
			return true;
			}
		}
	}
	return false;
}

//------------------------------------------------------
//	operator[]
//		Overloads [] operator
//
//		Converts Vector3 to float* which is then
//		accessed like a normal float array
//------------------------------------------------------
float& Vector3::operator[](int nIndex)
{
	assert(nIndex < 3 && "Vector3: index out of bounds.");
	return ((float*)this)[nIndex];
}

//------------------------------------------------------
//	operator float*
//		Overloads float* cast operator
//
//		Allows casting of Vector into float*
//------------------------------------------------------
Vector3::operator float*()
{
	return &x;
}

//------------------------------------------------------
//	operator Vector2
//		(EXPLICIT) Overloads Vector2 cast operator
//
//		Allows casting of Vector3 into Vector2
//------------------------------------------------------
Vector3::operator Vector2()
{
	Vector2 outVec;
	outVec.x = x;
	outVec.y = y;

	return outVec;
}

//------------------------------------------------------
//	operator Vector4
//		(EXPLICIT) Overloads Vector4 cast operator
//
//		Allows casting of Vector3 into Vector4
//------------------------------------------------------
Vector3::operator Vector4()
{
	Vector4 outVec;
	outVec.x = x;
	outVec.y = y;
	outVec.z = z;

	return outVec;
}

//------------------------------------------------------
//	dot
//		Dot Product of two Vectors
//
//			return (float):
//				dot product
//------------------------------------------------------
float Vector3::dot(Vector3 rhs)
{
	return ((x * rhs.x) + (y * rhs.y) + (z * rhs.z));
}

//------------------------------------------------------
//	cross
//		Cross Product of two Vectors
//
//			return (Vector3):
//				Vector at right angle to both input vectors
//------------------------------------------------------
Vector3 Vector3::cross(Vector3 rhs)
{
	Vector3 outVec;
	outVec.x = (y*rhs.z) - (z*rhs.y);
	outVec.y = (z*rhs.x) - (x*rhs.z);
	outVec.z = (x*rhs.y) - (y*rhs.x);

	return outVec;
}

//------------------------------------------------------
//	magnitude
//		Calculates magnitude of vector
//
//			return (float):
//				actual magnitude of vector
//------------------------------------------------------
float Vector3::magnitude()
{
	return sqrtf((x*x) + (y*y) + (z*z));
}

//------------------------------------------------------
//	magnitudeSqr
//		Faster than magnitude
//
//		Calculates magnitude of vector but doesnt sqrt,
//		only useful for checking relative vectors.
//
//			return (float):
//				square of magnitude of vector
//------------------------------------------------------
float Vector3::magnitudeSqr()
{
	return ((x*x) + (y*y) + (z*z));
}

//------------------------------------------------------
//	normalise
//		Normalises the vector
//
//			return (float):
//				magnitude before normalisation
//------------------------------------------------------
float Vector3::normalise()
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
	z /= mag;

	return mag;
}

//------------------------------------------------------
//	Swizzle
//		Swizzle the vector
//
//			xyz (char*):
//				only allows characters (x,X),(y,Y),(z,Z)
//				any other characters will cause an assert
//				must have 3 characters
//
//			return (Vector3):
//				Swizzled Vector3
//------------------------------------------------------
Vector3 Vector3::Swizzle(const char* xyz)
{
	Vector3 outVec;
	for (int i = 0; i < 3; ++i)
	{
		if (xyz[i] == 'x' || xyz[i] == 'X')
		{
			outVec[i] = x;
		}
		else if (xyz[i] == 'y' || xyz[i] == 'Y')
		{
			outVec[i] = y;
		}
		else if (xyz[i] == 'z' || xyz[i] == 'Z')
		{
			outVec[i] = z;
		}
		else
		{
			assert(!"Invalid character");
		}
	}

	return outVec;
}