# - Finds Cairo instalation
# It defines:
# CAIRO_FOUND          If the ROOT is found
# CAIRO_INCLUDE_DIR    PATH to the include directory
# CAIRO_LIBRARIES      Most common libraries

find_package(PkgConfig)
pkg_check_modules(PC_CAIRO cairo QUIET)

find_path(CAIRO_INCLUDE_DIRS
    NAMES cairo.h
    HINTS ${PC_CAIRO_INCLUDEDIR} ${PC_CAIRO_INCLUDE_DIRS}
    PATH_SUFFIXES cairo
    QUIET
)
find_library(CAIRO_LIBRARIES
    NAMES cairo
    HINTS ${PC_CAIRO_LIBDIR}
    ${PC_CAIRO_LIBRARY_DIRS}
    QUIET
)

if (CAIRO_INCLUDE_DIRS)
    if (EXISTS "${CAIRO_INCLUDE_DIRS}/cairo-version.h")
        file(READ "${CAIRO_INCLUDE_DIRS}/cairo-version.h" CAIRO_VERSION_CONTENT)
        string(REGEX MATCH "#define +CAIRO_VERSION_MAJOR +([0-9]+)" _dummy "${CAIRO_VERSION_CONTENT}")
        set(CAIRO_VERSION_MAJOR "${CMAKE_MATCH_1}")
        string(REGEX MATCH "#define +CAIRO_VERSION_MINOR +([0-9]+)" _dummy "${CAIRO_VERSION_CONTENT}")
        set(CAIRO_VERSION_MINOR "${CMAKE_MATCH_1}")
        string(REGEX MATCH "#define +CAIRO_VERSION_MICRO +([0-9]+)" _dummy "${CAIRO_VERSION_CONTENT}")
        set(CAIRO_VERSION_MICRO "${CMAKE_MATCH_1}")
        set(CAIRO_VERSION "${CAIRO_VERSION_MAJOR}.${CAIRO_VERSION_MINOR}.${CAIRO_VERSION_MICRO}")
    endif ()
endif ()

set(VERSION_OK TRUE)
if (Cairo_FIND_VERSION)
    if (Cairo_FIND_VERSION_EXACT)
        if (NOT "${Cairo_FIND_VERSION}" VERSION_EQUAL "${CAIRO_VERSION}")
            set(VERSION_OK FALSE)
        endif ()
    else ()
        if (NOT "${CAIRO_VERSION}" VERSION_GREATER "${Cairo_FIND_VERSION}")
            set(VERSION_OK FALSE)
        endif ()
    endif ()
endif ()

if(NOT Cairo_FIND_QUIETLY)
    message(STATUS "Found Cairo ${CAIRO_VERSION} in ${CAIRO_INCLUDE_DIRS}")
endif()

include(FindPackageHandleStandardArgs)
#FIND_PACKAGE_HANDLE_STANDARD_ARGS(Cairo DEFAULT_MSG CAIRO_INCLUDE_DIRS CAIRO_LIBRARIES VERSION_OK)

