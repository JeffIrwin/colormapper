
#include <stdio.h>
#include <iostream>

#include <fire.hpp>

#include <colormapper.h>

const std::string me = "colormapper";

int fired_main(std::string file = fire::arg({0, "<ColorMapFile>",
			"JSON or XML resource file containing one or more colormaps"}))
{
	// Make a colorbar test image for each colormap contained in the
	// resource file (JSON or XML) given as a command line argument.

	std::cout << std::endl;
	std::cout << "Starting " << me << std::endl;
	std::cout << std::endl;

	int io = 0;

	irwincolor::Map c;
	std::vector<std::string> names;
	io = irwincolor::loadMapNames(file, names);

	std::string fbase = file.substr(0, file.find_last_of("."));

	int nx = 1080;
	int ny = 240;
	std::vector<uint8_t> rgb(3);
	std::vector<uint8_t> pix(4 * nx * ny);
	for (int i = 0; i < names.size(); i++)
	{
		c.load(file, names[i]);
		for (int ix = 0; ix < nx; ix++)
		{
			rgb = c.map((double) ix / (nx - 1));
			for (int iy = 0; iy < ny; iy++)
			{
				//std::cout << iy << std::endl;
				int ip = 4 * (iy * nx + ix);
				pix[ip + 0] = rgb[0];
				pix[ip + 1] = rgb[1];
				pix[ip + 2] = rgb[2];
				pix[ip + 3] = 255;
			}
		}
		io = irwincolor::savePng(pix, nx, ny, fbase + "_" + names[i] + ".png");
		if (io != 0) return io;
	}

	std::cout << "Done " << me << std::endl;
	std::cout << std::endl;
	return io;
}

FIRE_NO_SPACE_ASSIGNMENT(fired_main)

