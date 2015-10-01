# fetched from https://gitlab.cern.ch/fts/fts3/raw/c26d3a25d86ed7327649e48a14d1f231cecd917d/cmake/modules/FindSoup.cmake

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SOUP "REQUIRED" libsoup-2.4)

IF(SOUP_FOUND)
  MESSAGE(STATUS "Found libsoup")
ENDIF(SOUP_FOUND)

MARK_AS_ADVANCED(
  SOUP_CFLAGS
  SOUP_LIBRARIES
) 
