#pragma once
#include <iostream>
#include <cmath>

class vec3
{
public:

	struct xyz
	{
		double x;
		double y;
		double z;
	};

	xyz v;

	vec3():v{0.0,0.0,0.0}{}

	vec3(double x,double y,double z):
		v{x,y,z}{}

	double x()const noexcept{ return v.x; }
	double y()const noexcept { return v.y; }
	double z()const noexcept { return v.z; }

	// Operator overloading

	vec3 operator-()const { return vec3(-v.x, -v.y, -v.z); }

	double operator[](int i)const{
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

	double& operator[](int i)
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

	vec3& operator *=(double k)
	{
		//scalar multiplication
		v.x *= k;
		v.y *= k;
		v.z *= k;
		return *this;
	}

	vec3& operator/=(double k)
	{
		if (k != 0.0)
		{
			return *this *= 1/k;
		}
		else {
			throw "Divided by zero expetion!!\n";
		}
	}

	double length_squared()const
	{
		return (v.x * v.x + v.y * v.y * v.z * v.z);
	}

	double length()const
	{
		return (std::sqrt(length_squared()));
	}

private:

};