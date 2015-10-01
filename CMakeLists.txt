cmake_minimum_required(VERSION 2.8)

LIST(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

include(Findgcrypt)
include(FindSoup)

find_package(LibXml2 REQUIRED)
find_package(gcrypt REQUIRED)
find_package(Soup REQUIRED)

add_subdirectory(flicksoup)


include_directories("${PROJECT_SOURCE_DIR}/src" "${PROJECT_SOURCE_DIR}/flicksoup" "${LIBXML2_INCLUDE_DIR}")
link_directories("${LIBXML2_LIBRARIES}")

add_executable(zubr src/main.cpp
	src/ui.h src/ui.cpp
	src/flickr.h src/flickr.cpp
)
target_link_libraries(zubr files flicksoup xml2 boost_system boost_filesystem)
set_property(TARGET zubr PROPERTY CXX_STANDARD 11)

add_library(files
	src/files.h src/files.cpp
)
set_property(TARGET files PROPERTY CXX_STANDARD 11)

enable_testing()
add_subdirectory(test)
