
set(PROJECT colormapper)

set(SUBMODULE_DIR submodules)
set(XML_DIR ${SUBMODULE_DIR}/pugixml/src)

set(JSON_DIR ${SUBMODULE_DIR}/json/single_include/nlohmann)

# Everything else is header-only
add_library(${PROJECT} ${XML_DIR}/pugixml.cpp)

target_include_directories(${PROJECT} PUBLIC
	"."
	${JSON_DIR}
	${XML_DIR}
	)

