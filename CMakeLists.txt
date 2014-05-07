project(TITAN)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-Wextra -Wall -pedantic -std=c++0x"${CMAKE_CXX_FLAGS})
set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/release)

macro(installheaders package)
    file(GLOB files "${PROJECT_SOURCE_DIR}/${package}/include/titan/${package}/*.hpp")
    INSTALL(
        FILES 
            ${files}
        DESTINATION 
            include/titan/${package}
    )
endmacro(installheaders)

macro(installlib targetname)
    install(
        TARGETS
            ${targetname}
        DESTINATION
            libs
    )
endmacro(installlib)

add_subdirectory(core)
add_subdirectory(drawing)
add_subdirectory(histogram)
