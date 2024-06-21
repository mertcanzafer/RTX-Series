#pragma once
#include "vec3.h"

using color = vec3;

void write_color(std::ostream& os, const color& pixelColor)
{
	auto r = pixelColor.v.x;
	auto g = pixelColor.v.y;
	auto b = pixelColor.v.z;

	int ir = int(255.999 * r);
	int ig = int(255.999 * g);
	int ib = int(255.999 * b);

	os << ir << " " << ig << " " << ib << "\n";
}