#!/bin/bash

# Test parsing both XML and JSON
inputs="./submodules/colormaps/ColorMaps5.0.0.xml ./submodules/colormaps/ColorMaps5.6.0.json"

# Test one color from each color space.  None of the maps are in the XYZ space,
# but XYZ is used internally for lab2rgb conversion.
frames=("Cool to Warm"
        "Blue to Red Rainbow"
        "CIELab Blue to Red"
        "Blue to Yellow"
       )

exebase=colormapper
outdir=./submodules/colormaps/
expectedoutdir=./tests/expected-output
outputext=png
use_stdin="false"
use_pushpop="false"

#===============================================================================

source ./submodules/bat/test.sh

