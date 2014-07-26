include_directories(${PROJECT_SOURCE_DIR}/addons/root/include)
include_directories(${PROJECT_SOURCE_DIR}/core/include)
include_directories(${PROJECT_SOURCE_DIR}/drawing/include)
include_directories(${PROJECT_SOURCE_DIR}/histogram/include)

set(CMAKE_MODULE_PATH  "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_MODULE_PATH}")
find_package(ROOT)
include_directories(${CAIRO_INCLUDE_DIRS}) 

add_library(titan-rootplugin SHARED
    src/RootReader.cpp
)
target_link_libraries(titan-rootplugin titan-core titan-drawing ${CAIRO_LIBRARIES})

installlib(titan-rootplugin)
