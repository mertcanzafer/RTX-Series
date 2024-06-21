#pragma once
#include <iostream>
#include <cmath>

class vec3
{
public:

	struct xyz
	{
		float x;
		float y;
		float z;
	};

	xyz v;

	vec3():v{0.0f,0.0f,0.0f}{}

	vec3(float x,float y,float z):
		v{x,y,z}{}

	vec3(const vec3& copy)
		:v{copy.v}{}

	vec3& operator=(const vec3& copy)
	{
		v = copy.v;
	}

	float x()const noexcept{ return v.x; }
	float y()const noexcept { return v.y; }
	float z()const noexcept { return v.z; }

	// Operator overloading

	vec3 operator-()const { return vec3(-v.x, -v.y, -v.z); }

	float operator[](int i)const{
		switch (i)
		{
		case 0:
			return v.x;
		case 1:
			return v.y;
		case 2:
			return v.z;
		default:
			std::clog << "Invalid index!!\n" << std::flush;
			throw - 1; // Exception Message
		}
	}

	float& operator[](int i)
	{
		switch (i)
		{
		case 0:
			return v.x;
		case 1:
			return v.y;
		case 2:
			return v.z;
		default:
			std::clog << "Invalid index!!\n" << std::flush;
			throw - 1; // Exception Message
		}
	}

	vec3& operator+=(const vec3& v)
	{
		this->v.x = this->v.x + v.v.x;
		this->v.y = this->v.y + v.v.y;
		this->v.z = this->v.z + v.v.z;

		return *this;
	}

	vec3& operator *=(float k)
	{
		//scalar multiplication
		v.x *= k;
		v.y *= k;
		v.z *= k;
		return *this;
	}

	vec3& operator/=(float k)
	{
		if (k != 0.0)
		{
			return *this *= 1/k;
		}
		else {
			throw "Divided by zero expetion!!\n";
		}
	}

	float length_squared()const
	{
		return (v.x * v.x + v.y * v.y * v.z * v.z);
	}

	float length()const
	{
		return (std::sqrt(length_squared()));
	}

private:

};

// Alias to vec3
using point3 = vec3;

// Vector utility functions

inline std::ostream& operator<<(std::ostream& os, const vec3& v)
{
	os << v.v.x << " " << v.v.y <<" " << v.v.z;
	return os;
}

inline vec3 operator+(const vec3& v1, const vec3& v2)
{
	return vec3(v1.v.x + v2.v.x , v1.v.y + v2.v.y , v1.v.z + v2.v.z);
}

inline vec3 operator-(const vec3& v1, const vec3& v2)
{
	return vec3(v1.v.x - v2.v.x, v1.v.y - v2.v.y, v1.v.z - v2.v.z);
}

inline vec3 operator*(const vec3& v1, const vec3& v2)
{
	return vec3(v1.v.x * v2.v.x, v1.v.y * v2.v.y, v1.v.z * v2.v.z);
}

inline vec3 operator*(float k, const vec3& v)
{
	return vec3(v.v.x * k, v.v.y * k , v.v.z * k);
}

inline vec3 operator*(const vec3& v,float k)
{
	return k * v;
}

inline vec3 operator/(const vec3& v, float k)
{
	if (k != 0.0)
	{
		return 1 / k * v;
	}
	else {
		throw "Divided by zero expetion!!\n";
	}
}

inline float dot(const vec3& v1, const vec3& v2)
{
	vec3 mult = v1 * v2;
	return(mult.v.x + mult.v.y + mult.v.z);
}

inline vec3 cross(const vec3& v1, const vec3& v2)
{
	return vec3
	(
		v1.v.y * v2.v.z - v1.v.z * v2.v.y,
		v1.v.z * v2.v.x - v1.v.x * v2.v.z,
		v1.v.x * v2.v.y - v1.v.y * v2.v.x
	);
}

inline vec3 unit_vector(const vec3& v)
{
	return v / v.length();
}