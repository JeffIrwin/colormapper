# colormapper
it maps colors duh

Load colormap data from a JSON or XML resource file and map scalars to RGB color triplets.

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
    ColorMap c;
    c.paraView = true;
    c.inv = false;
    c.load(file, mapname);
    
    ...
    
    // Map a scalar x in the range [0.0, 1.0] to an RGB triplet
    double x = 0.5;
    std::vector<uint8_t> rgb = c.map(x);
    
    ...
    
For more details and usage context, see some of the projects that use colormapper, for example [maph](https://github.com/JeffIrwin/maph) or [life](https://github.com/JeffIrwin/life).
