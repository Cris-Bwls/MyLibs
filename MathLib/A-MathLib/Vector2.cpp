#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include <math.h>
#include <assert.h>


Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{
}

//------------------------------------------------------
//	One
//		Sets components to 1
//------------------------------------------------------
void Vector2::One()
{
	x = 1.0f;
	y = 1.0f;
}

//------------------------------------------------------
//	Zero
//		Sets components to 0
//------------------------------------------------------
void Vector2::Zero()
{
	x = 0.0f;
	y = 0.0f;
}

//------------------------------------------------------
//	Right
//		Sets x to 1
//		all others set to 0
//------------------------------------------------------
void Vector2::Right()
{
	x = 1.0f;
	y = 0.0f;
}

//------------------------------------------------------
//	Left
//		Sets x to -1
//		all others set to 0
//------------------------------------------------------
void Vector2::Left()
{
	x = -1.0f;
	y = 0.0f;
}

//------------------------------------------------------
//	Up
//		Sets y to 1
//		all others set to 0
//------------------------------------------------------
void Vector2::Up()
{
	x = 0.0f;
	y = 1.0f;
}

//------------------------------------------------------
//	Down
//		Sets y to -1
//		all others set to 0
//------------------------------------------------------
void Vector2::Down()
{
	x = 0.0f;
	y = -1.0f;
}

//------------------------------------------------------
//	operator+
//		Overloads - operator
//
//		Allows Integer promotion of Vectors
//------------------------------------------------------
Vector2 Vector2::operator+()
{
	Vector2 outVec;
	outVec.x = +(this->x);
	outVec.y = +(this->y);

	return outVec;
}

//------------------------------------------------------
//	operator-
//		Overloads - operator
//
//		Allows Inverse of Vector
//------------------------------------------------------
Vector2 Vector2::operator-()
{
	Vector2 outVec;
	outVec.x = -(this->x);
	outVec.y = -(this->y);

	return outVec;
}

//------------------------------------------------------
//	operator+
//		Overloads + operator
//
//		Allows Addition of Vectors
//------------------------------------------------------
Vector2 Vector2::operator+(Vector2 rhs)
{
	Vector2 outVec;
	outVec.x = this->x + rhs.x;
	outVec.y = this->y + rhs.y;

	return outVec;
}

//------------------------------------------------------
//	operator-
//		Overloads - operator
//
//		Allows Subtraction of Vectors
//------------------------------------------------------
Vector2 Vector2::operator-(Vector2 rhs)
{
	Vector2 outVec;
	outVec.x = this->x - rhs.x;
	outVec.y = this->y - rhs.y;

	return outVec;
}

//------------------------------------------------------
//	operator*
//		Overloads * operator
//
//		Allows Multiplication of Vector by rhs scalar
//------------------------------------------------------
Vector2 Vector2::operator*(float scalar)
{
	Vector2 outVec;
	outVec.x = this->x * scalar;
	outVec.y = this->y * scalar;

	return outVec;
}

//------------------------------------------------------
//	operator+=
//		Overloads += operator
//
//		Allows Addition assignment of Vectors
//------------------------------------------------------
Vector2& Vector2::operator+=(Vector2 rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;

	return *this;
}

//------------------------------------------------------
//	operator-=
//		Overloads -= operator
//
//		Allows Subtraction assignment of Vectors
//------------------------------------------------------
Vector2& Vector2::operator-=(Vector2 rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;

	return *this;
}

//------------------------------------------------------
//	operator*=
//		Overloads *= operator
//
//		Allows Multiplication assignment of Vector by 
//		rhs scalar
//------------------------------------------------------
Vector2& Vector2::operator*=(float scalar)
{
	this->x *= scalar;
	this->y *= scalar;

	return *this;
}

//------------------------------------------------------
//	operator==
//		Overloads == operator
//
//		Allows 'Equal to' relational operator to check 
//		Vectors against each other
//------------------------------------------------------
bool Vector2::operator==(Vector2 rhs)
{
	if (this->x == rhs.x)
	{
		if (this->y == rhs.y)
		{
			return true;
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
bool Vector2::operator>(Vector2 rhs)
{
	if (this->x > rhs.x)
	{
		if (this->y > rhs.y)
		{
			return true;
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
bool Vector2::operator>=(Vector2 rhs)
{
	if (this->x >= rhs.x)
	{
		if (this->y >= rhs.y)
		{
			return true;
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
bool Vector2::operator<(Vector2 rhs)
{
	if (this->x < rhs.x)
	{
		if (this->y < rhs.y)
		{
			return true;
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
bool Vector2::operator<=(Vector2 rhs)
{
	if (this->x <= rhs.x)
	{
		if (this->y <= rhs.y)
		{
			return true;
		}
	}
	return false;
}

//------------------------------------------------------
//	operator[]
//		Overloads [] operator
//
//		Converts Vector2 to float* which is then
//		accessed like a normal float array
//------------------------------------------------------
float& Vector2::operator[](int nIndex)
{
	assert(nIndex < 2 && "Vector2: index out of bounds.");
	return ((float*)this)[nIndex];
}

//------------------------------------------------------
//	operator float*
//		(EXPLICIT) Overloads float* cast operator
//
//		Allows casting of Vector into float*
//------------------------------------------------------
Vector2::operator float*()
{
	return &x;
}

//------------------------------------------------------
//	operator Vector2
//		(EXPLICIT) Overloads Vector2 cast operator
//
//		Allows casting of Vector2 into Vector3
//------------------------------------------------------
Vector2::operator Vector3()
{
	Vector3 outVec;
	outVec.x = x;
	outVec.y = y;

	return outVec;
}

//------------------------------------------------------
//	operator Vector2
//		(EXPLICIT) Overloads Vector2 cast operator
//
//		Allows casting of Vector2 into Vector4
//------------------------------------------------------
Vector2::operator Vector4()
{
	Vector4 outVec;
	outVec.x = x;
	outVec.y = y;

	return outVec;
}

//------------------------------------------------------
//	dot
//		Dot Product of two Vectors
//
//			return (float):
//				dot product
//------------------------------------------------------
float Vector2::dot(Vector2 rhs)
{
	return ((x * rhs.x) + (y * rhs.y));
}

//------------------------------------------------------
//	perpCCW
//		Determines Perpendicular Counter Clock Wise Vector		
//
//			return (Vector2):
//				Perpendicular Counter Clock Wise Vector
//------------------------------------------------------
Vector2 Vector2::perpCCW()
{
	Vector2 outVec;
	outVec.x = -y;
	outVec.y = x;

	return outVec;
}

//------------------------------------------------------
//	perpCW
//		Determines Perpendicular Clock Wise Vector		
//
//			return (Vector2):
//				Perpendicular Clock Wise Vector
//------------------------------------------------------
Vector2 Vector2::perpCW()
{
	Vector2 outVec;
	outVec.x = y;
	outVec.y = -x;

	return outVec;
}

//------------------------------------------------------
//	magnitude
//		Calculates magnitude of vector
//
//			return (float):
//				actual magnitude of vector
//------------------------------------------------------
float Vector2::magnitude()
{
	return sqrtf((x*x) + (y*y));
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
float Vector2::magnitudeSqr()
{
	return ((x*x) + (y*y));
}

//------------------------------------------------------
//	normalise
//		Normalises the vector
//
//			return (float):
//				magnitude before normalisation
//------------------------------------------------------
float Vector2::normalise()
{
	float mag = magnitude();

	x /= mag;
	y /= mag;

	if (mag == 0)
	{
		x = 0;
		y = 0;
	}

	return mag;
}

//------------------------------------------------------
//	Swizzle
//		Swizzle the vector
//
//			xy (char*):
//				only allows characters x,X and y,Y
//				any other characters will cause an assert
//				must have 2 characters
//
//			return (Vector2):
//				Swizzled Vector2
//------------------------------------------------------
Vector2 Vector2::Swizzle(const char* xy)
{
	Vector2 outVec;
	for (int i = 0; i < 2; ++i)
	{
		if (xy[i] == 'x' || xy[i] == 'X')
		{
			outVec[i] = x;
		}
		else if (xy[i] == 'y' || xy[i] == 'Y')
		{
			outVec[i] = y;
		}
		else
		{
			assert(!"Invalid character");
		}
	}

	return outVec;
}

Vector2 Vector2::Lerp(Vector2 start, Vector2 end, float time)
{
	Vector2 result = start + (end - start) * time;
	return result;
}