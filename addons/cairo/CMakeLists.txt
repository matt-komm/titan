include_directories(${PROJECT_SOURCE_DIR}/addons/cairo/include)
include_directories(${PROJECT_SOURCE_DIR}/core/include)
include_directories(${PROJECT_SOURCE_DIR}/drawing/include)
include_directories(${PROJECT_SOURCE_DIR}/histogram/include)

set(CMAKE_MODULE_PATH  "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_MODULE_PATH}")
find_package(Cairo)
include_directories(${CAIRO_INCLUDE_DIRS}) 

add_library(titan-cairoplugin SHARED
    src/CairoRenderer.cpp
    src/CairoCanvas.cpp
    src/CairoContext.cpp
)
target_link_libraries(titan-cairoplugin titan-core titan-drawing ${CAIRO_LIBRARIES})

installlib(titan-cairoplugin)
