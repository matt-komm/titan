include_directories(${PROJECT_SOURCE_DIR}/addons/html/include)
include_directories(${PROJECT_SOURCE_DIR}/core/include)
include_directories(${PROJECT_SOURCE_DIR}/drawing/include)
include_directories(${PROJECT_SOURCE_DIR}/histogram/include)
include_directories(${PROJECT_SOURCE_DIR}/xml/include)

set(CMAKE_MODULE_PATH  "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_MODULE_PATH}")

add_library(titan-addons-htmlplugin SHARED
    src/HTMLCanvas.cpp
    src/HTMLContext.cpp
)
target_link_libraries(titan-addons-htmlplugin titan-core titan-drawing)

installlib(titan-addons-htmlplugin)
