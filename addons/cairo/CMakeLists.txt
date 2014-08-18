include_directories(${PROJECT_SOURCE_DIR}/addons/cairo/include)
include_directories(${PROJECT_SOURCE_DIR}/core/include)
include_directories(${PROJECT_SOURCE_DIR}/drawing/include)
include_directories(${PROJECT_SOURCE_DIR}/histogram/include)
include_directories(${PROJECT_SOURCE_DIR}/xml/include)

set(CMAKE_MODULE_PATH  "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_MODULE_PATH}")
find_package(Cairo)
include_directories(${CAIRO_INCLUDE_DIRS}) 

add_library(titan-cairoplugin MODULE
    src/CairoCanvas.cpp
    src/CairoContext.cpp
    src/CairoPlugin.cpp
)
target_link_libraries(titan-cairoplugin titan-core titan-drawing ${CAIRO_LIBRARIES})

add_executable(titan-addons-cairo-test
    test/test.cpp
)
target_link_libraries(titan-addons-cairo-test titan-core titan-drawing titan-xml)

installlib(titan-cairoplugin)
