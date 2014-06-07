include_directories(${PROJECT_SOURCE_DIR}/core/include)
include_directories(${PROJECT_SOURCE_DIR}/drawing/include)

add_library(titan-drawing SHARED
    src/Stroke.cpp
    src/Fill.cpp
    src/Line.cpp
    src/Rect.cpp
    src/Color.cpp
    src/Canvas.cpp
    src/Context.cpp
)

installheaders(drawing)

installlib(titan-drawing)
