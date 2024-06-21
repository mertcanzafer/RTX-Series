#include <iostream>
#include "headers\color.h"
// Image
#define WIDTH				256
#define HEIGHT				256

// Render

int main()
{
	try {
		std::cout << "P3\n" << WIDTH << " " << HEIGHT << "\n255\n";

		// Traverse the img

		for (int j = 0; j < HEIGHT; j++)
		{
			std::clog << "\nScanlins remaining " << (HEIGHT - j) << " " << std::flush;
			for (int i = 0; i < WIDTH; i++)
			{
				auto pixel_color = color(float(i) / (WIDTH - 1), float(j) / (HEIGHT - 1), 0.0f);
				write_color(std::cout, pixel_color);
			}
		}

		std::clog << "\rDone.					\n";
	}
	catch (const int& ex)
	{
	  std::cout << "Invalid index is given inside the brackets\n";
	}
	catch (const char* ex)
	{
		std::cout << "Divided by zero exception!!\n";
	}
	return 0;
}
