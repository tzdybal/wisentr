cmake_minimum_required(VERSION 2.8)

include_directories("${PROJECT_SOURCE_DIR}" "${PROJECT_SOURCE_DIR}/flicksoup" "${SOUP_INCLUDE_DIRS}" "${GCRYPT_INCLUDE_DIR}" "${LIBXML2_INCLUDE_DIR}")

add_library(flicksoup SHARED
       flicksoup.h
       fsp-data.c
       fsp-data.h
       fsp-error.c
       fsp-error.h
       fsp-parser.c
       fsp-parser.h
       fsp-session.c
       fsp-session.h
)

target_link_libraries(flicksoup "${SOUP_LIBRARIES}" "${GCRYPT_LIBRARIES}")
