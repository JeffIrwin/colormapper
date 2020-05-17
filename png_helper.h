
#ifndef INCLUDE_PNG_HELPER_H_
#define INCLUDE_PNG_HELPER_H_

#include <colormapper_constants.h>
#include <lodepng.h>

namespace irwincolor
{

int savePng(const std::vector<uint8_t>& b, int nx, int ny, std::string f)
{
	std::cout << "Writing file \"" << f << "\" ..." << std::endl;
	std::vector<uint8_t> imageBuffer;
	unsigned error = lodepng::encode(imageBuffer, b, nx, ny);
	if (error)
	{
		std::cout << "\nError: PNG encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
		return ERR_PNG;
	}
	lodepng::save_file(imageBuffer, f);
	return 0;
}

} // namespace irwincolor

#endif  // INCLUDE_PNG_HELPER_H_

