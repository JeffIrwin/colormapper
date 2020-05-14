
set(PROJECT colormapper)

if (APPLE)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

project(${PROJECT})

set(SUBMODULE_DIR submodules)

set(XML_DIR  ${SUBMODULE_DIR}/pugixml/src)
set(JSON_DIR ${SUBMODULE_DIR}/json/single_include/nlohmann)
set(PNG_DIR  ${SUBMODULE_DIR}/lodepng)

# Colormapper lib itself is header-only.
add_library(${PROJECT} ${XML_DIR}/pugixml.cpp ${PNG_DIR}/lodepng.cpp)

set(EXE "${PROJECT}exe")
add_executable(${EXE} main.cpp)
target_link_libraries(${EXE} ${PROJECT})
set_target_properties(${EXE} PROPERTIES OUTPUT_NAME ${PROJECT})

target_include_directories(${PROJECT} PUBLIC
	"."
	${JSON_DIR}
	${XML_DIR}
	${PNG_DIR}
	)

