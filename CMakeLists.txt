cmake_minimum_required(VERSION 2.8)

find_package(LibXml2 REQUIRED)
find_package(CURL REQUIRED)

include(ExternalProject)
externalproject_add(flickcurl_project
	SOURCE_DIR ${PROJECT_SOURCE_DIR}/flickcurl
	BINARY_DIR ${PROJECT_SOURCE_DIR}/flickcurl/
	CONFIGURE_COMMAND ./autogen.sh --prefix=${PROJECT_BINARY_DIR}/flickcurl/
	BUILD_COMMAND ${MAKE}
)

add_library(flickcurl STATIC IMPORTED)
add_dependencies(flickcurl flickcurl_project)
set_target_properties(flickcurl PROPERTIES IMPORTED_LOCATION "${PROJECT_BINARY_DIR}/flickcurl/lib/libflickcurl.a")

include_directories("${PROJECT_SOURCE_DIR}/src" "${PROJECT_BINARY_DIR}/flickcurl/include" "${LIBXML2_INCLUDE_DIR}")
link_directories("${LIBXML2_LIBRARIES}")

add_executable(zubr src/main.cpp
	src/ui.h src/ui.cpp
)
set_property(TARGET zubr PROPERTY CXX_STANDARD 11)

add_library(files
	src/files.h src/files.cpp
)
set_property(TARGET files PROPERTY CXX_STANDARD 11)

add_executable(example src/example.c)
target_link_libraries(example flickcurl curl xml2)

enable_testing()
add_subdirectory(test)
