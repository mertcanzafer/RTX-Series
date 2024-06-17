#include <iostream>

// Image
#define WIDTH				256
#define HEIGHT				256

// Render

int main()
{
	std::cout << "P3\n" << WIDTH << " " << HEIGHT << "\n255\n";

	struct Color
	{
		float red = 0.0f;
		float green = 0.0f;
		float blue = 0.0f;
	};

	Color c = {};

	// Traverse the img

	for (int j = 0; j < HEIGHT; j++)
	{
		std::clog << "\nScanlins remaining " << (HEIGHT - j) << " " << std::flush;
		for (int i = 0; i < WIDTH; i++)
		{
			c.red = float(i) / (WIDTH - 1);
			c.green = float(j) / (HEIGHT - 1);
			c.blue = 0.0f;
			// NC pixel between 0 and 1

			// DNC pixel
			int ir = int(255.999 * c.red);
			int ig = int(255.999 * c.green);
			int ib = int(255.999 * c.blue);

			std::cout << ir << " " << ig << " " << ib << "\n";	
		}
	}

	std::clog << "\rDone.					\n";

	return 0;
}
