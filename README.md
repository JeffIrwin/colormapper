![](https://github.com/JeffIrwin/colormapper/workflows/CI/badge.svg)
# colormapper
it maps colors duh

Load colormap data from a JSON or XML resource file and map scalars to RGB color triplets.

For projects that use colormapper, see [maph](https://github.com/JeffIrwin/maph) or [life](https://github.com/JeffIrwin/life).

## Spaces
`colormapper` supports the following color spaces, and provides functions for converting between them:
- CIELAB
- HSV
- Msh
- RGB
- XYZ

## Download
_From your project:_

    git submodule add https://github.com/JeffIrwin/colormapper

## CMake build
    add_subdirectory("/path/to/colormapper/")
    
    ...
    
    target_link_libraries(myProject colormapper)

## Usage
    #include <colormapper.h>
    
    ...
    
    // Load colormap data
    std::string file = "/path/to/ColorMaps5.6.0.json";
    std::string mapname = "Inferno (matplotlib)";
    irwincolor::Map c;
    c.load(file, mapname);
    
    ...
    
    // Map a scalar x in the range [0.0, 1.0] to an RGB triplet
    double x = 0.5;
    std::vector<uint8_t> rgb = c.map(x);
    
    ...
