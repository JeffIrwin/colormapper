
#include <stdio.h>
#include <iostream>

#include <colormapper.h>

const std::string me = "colormapper";

int main(int argc, char* argv[])
{
	// Make a colorbar test image for each colormap contained in the
	// resource file (JSON or XML) given as a command line argument.

	std::cout << std::endl;
	std::cout << "Starting " << me << std::endl;
	std::cout << std::endl;

	int io = 0;

	if (argc < 2)
	{
		std::cout << "Usage:" << std::endl;
		std::cout << "\t" << me << " ColorMaps.json" << std::endl;
		return -1;
	}

	irwincolor::ColorMap c;
	std::string file = argv[1];
	std::vector<std::string> names;
	io = irwincolor::loadColorMapNames(file, names);

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

