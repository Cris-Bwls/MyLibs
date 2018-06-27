#include "Vector4.h"
#include "Vector3.h"
#include "Vector2.h"
#include <math.h>
#include <assert.h>


Vector4::Vector4()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

Vector4::Vector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector4::~Vector4()
{
}

//------------------------------------------------------
//	One
//		Sets components to 1
//------------------------------------------------------
void Vector4::One()
{
	x = 1.0f;
	y = 1.0f;
	z = 1.0f;
	w = 1.0f;
}

//------------------------------------------------------
//	Zero
//		Sets components to 0
//------------------------------------------------------
void Vector4::Zero()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

//------------------------------------------------------
//	operator+
//		Overloads - operator
//
//		Allows Integer promotion of Vectors
//------------------------------------------------------
Vector4 Vector4::operator+()
{
	Vector4 outVec;
	outVec.x = +(this->x);
	outVec.y = +(this->y);
	outVec.z = +(this->z);
	outVec.w = +(this->w);

	return outVec;
}

//------------------------------------------------------
//	operator-
//		Overloads - operator
//
//		Allows Inverse of Vector
//------------------------------------------------------
Vector4 Vector4::operator-()
{
	Vector4 outVec;
	outVec.x = -(this->x);
	outVec.y = -(this->y);
	outVec.z = -(this->z);
	outVec.w = -(this->w);

	return outVec;
}

//------------------------------------------------------
//	operator+
//		Overloads + operator
//
//		Allows Addition of Vectors
//------------------------------------------------------
Vector4 Vector4::operator+(Vector4 rhs)
{
	Vector4 outVec;
	outVec.x = this->x + rhs.x;
	outVec.y = this->y + rhs.y;
	outVec.z = this->z + rhs.z;
	outVec.w = this->w + rhs.w;

	return outVec;
}

//------------------------------------------------------
//	operator-
//		Overloads - operator
//
//		Allows Subtraction of Vectors
//------------------------------------------------------
Vector4 Vector4::operator-(Vector4 rhs)
{
	Vector4 outVec;
	outVec.x = this->x - rhs.x;
	outVec.y = this->y - rhs.y;
	outVec.z = this->z - rhs.z;
	outVec.w = this->w - rhs.w;

	return outVec;
}

//------------------------------------------------------
//	operator*
//		Overloads * operator
//
//		Allows Multiplication of Vector by rhs scalar
//------------------------------------------------------
Vector4 Vector4::operator*(float scalar)
{
	Vector4 outVec;
	outVec.x = this->x * scalar;
	outVec.y = this->y * scalar;
	outVec.z = this->z * scalar;
	outVec.w = this->w * scalar;

	return outVec;
}

//------------------------------------------------------
//	operator+=
//		Overloads += operator
//
//		Allows Addition assignment of Vectors
//------------------------------------------------------
Vector4& Vector4::operator+=(Vector4 rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	this->w += rhs.w;

	return *this;
}

//------------------------------------------------------
//	operator-
//		Overloads - operator
//
//		Allows Subtraction assignment of Vectors
//------------------------------------------------------
Vector4& Vector4::operator-=(Vector4 rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	this->w -= rhs.w;

	return *this;
}

//------------------------------------------------------
//	operator*
//		Overloads * operator
//
//		Allows Multiplication assignment of Vector by 
//		rhs scalar
//------------------------------------------------------
Vector4& Vector4::operator*=(float scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
	this->w *= scalar;

	return *this;
}

//------------------------------------------------------
//	operator==
//		Overloads == operator
//
//		Allows 'Equal to' relational operator to check 
//		Vectors against each other
//------------------------------------------------------
bool Vector4::operator==(Vector4 rhs)
{
	if (this->x == rhs.x)
	{
		if (this->y == rhs.y)
		{
			if (this->z == rhs.z)
			{
				if (this->w == rhs.w)
				{
					return true;
				}
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
bool Vector4::operator>(Vector4 rhs)
{
	if (this->x > rhs.x)
	{
		if (this->y > rhs.y)
		{
			if (this->z > rhs.z)
			{
				if (this->w > rhs.w)
				{
					return true;
				}
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
bool Vector4::operator>=(Vector4 rhs)
{
	if (this->x >= rhs.x)
	{
		if (this->y >= rhs.y)
		{
			if (this->z >= rhs.z)
			{
				if (this->w >= rhs.w)
				{
					return true;
				}
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
bool Vector4::operator<(Vector4 rhs)
{
	if (this->x < rhs.x)
	{
		if (this->y < rhs.y)
		{
			if (this->z < rhs.z)
			{
				if (this->w < rhs.w)
				{
					return true;
				}
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
bool Vector4::operator<=(Vector4 rhs)
{
	if (this->x <= rhs.x)
	{
		if (this->y <= rhs.y)
		{
			if (this->z <= rhs.z)
			{
				if (this->w <= rhs.w)
				{
					return true;
				}
			}
		}
	}
	return false;
}

//------------------------------------------------------
//	operator[]
//		Overloads [] operator
//
//		Converts Vector4 to float* which is then
//		accessed like a normal float array
//------------------------------------------------------
float& Vector4::operator[](int nIndex)
{
	assert(nIndex < 4 && "Vector4: index out of bounds.");
	return ((float*)this)[nIndex];
}

//------------------------------------------------------
//	operator float*
//		(EXPLICIT) Overloads float* cast operator
//
//		Allows casting of Vector into float*
//------------------------------------------------------
Vector4::operator float*()
{
	return &x;
}

//------------------------------------------------------
//	operator Vector2
//		(EXPLICIT) Overloads Vector2 cast operator
//
//		Allows casting of Vector4 into Vector2
//------------------------------------------------------
Vector4::operator Vector2()
{
	Vector2 outVec;
	outVec.x = x;
	outVec.y = y;

	return outVec;
}

//------------------------------------------------------
//	operator Vector3
//		(EXPLICIT) Overloads Vector3 cast operator
//
//		Allows casting of Vector4 into Vector3
//------------------------------------------------------
Vector4::operator Vector3()
{
	Vector3 outVec;
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
float Vector4::dot(Vector4 rhs)
{
	return ((x * rhs.x) + (y * rhs.y) + (z * rhs.z) + (w * rhs.w));
}

//------------------------------------------------------
//	cross
//		Cross Product of two Vectors
//
//			return (Vector4):
//				Vector at right angle to both input vectors
//------------------------------------------------------
Vector4 Vector4::cross(Vector4 rhs)
{
	Vector4 outVec;
	outVec.x = (y*rhs.z) - (z*rhs.y);
	outVec.y = (z*rhs.x) - (x*rhs.z);
	outVec.z = (x*rhs.y) - (y*rhs.x);
	outVec.w = 0;

	return outVec;
}


//------------------------------------------------------
//	magnitude
//		Calculates magnitude of vector
//
//			return (float):
//				actual magnitude of vector
//------------------------------------------------------
float Vector4::magnitude()
{
	return sqrtf((x*x) + (y*y) + (z*z) + (w*w));
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
float Vector4::magnitudeSqr()
{
	return ((x*x) + (y*y) + (z*z) + (w*w));
}

//------------------------------------------------------
//	normalise
//		Normalises the vector
//
//			return (float):
//				magnitude before normalisation
//------------------------------------------------------
float Vector4::normalise()
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
	w /= mag;

	return mag;
}

//------------------------------------------------------
//	Swizzle
//		Swizzle the vector
//
//			xyzw (char*):
//				only allows characters (x,X),(y,Y),(z,Z),(w,W) 
//				any other characters will cause an assert
//				must have 4 characters
//
//			return (Vector4):
//				Swizzled Vector4
//------------------------------------------------------
Vector4 Vector4::Swizzle(const char* xyzw)
{
	Vector4 outVec;
	for (int i = 0; i < 4; ++i)
	{
		if (xyzw[i] == 'x' || xyzw[i] == 'X')
		{
			outVec[i] = x;
		}
		else if (xyzw[i] == 'y' || xyzw[i] == 'Y')
		{
			outVec[i] = y;
		}
		else if (xyzw[i] == 'z' || xyzw[i] == 'Z')
		{
			outVec[i] = z;
		}
		else if (xyzw[i] == 'w' || xyzw[i] == 'W')
		{
			outVec[i] = w;
		}
		else
		{
			assert(!"Invalid character");
		}
	}

	return outVec;
}

//------------------------------------------------------
//	SwizzleRGBA
//		Swizzle the vector
//
//			xyzw (char*):
//				only allows characters (r,R),(g,G),(b,B),(a,A) 
//				any other characters will cause an assert
//				must have 4 characters
//
//			return (Vector4):
//				Swizzled Vector4
//------------------------------------------------------
Vector4 Vector4::SwizzleRGBA(const char* rgba)
{
	Vector4 outVec;
	for (int i = 0; i < 4; ++i)
	{
		if (rgba[i] == 'r' || rgba[i] == 'R')
		{
			outVec[i] = r;
		}
		else if (rgba[i] == 'g' || rgba[i] == 'G')
		{
			outVec[i] = g;
		}
		else if (rgba[i] == 'b' || rgba[i] == 'B')
		{
			outVec[i] = b;
		}
		else if (rgba[i] == 'a' || rgba[i] == 'A')
		{
			outVec[i] = a;
		}
		else
		{
			assert(!"Invalid character");
		}
	}

	return outVec;
}