include_directories(${PROJECT_SOURCE_DIR}/core/include)
include_directories(${PROJECT_SOURCE_DIR}/drawing/include)
include_directories(${PROJECT_SOURCE_DIR}/xml/include)

add_library(titan-drawing SHARED
    src/Stroke.cpp
    src/Fill.cpp
    src/Line.cpp
    src/Rect.cpp
    src/Color.cpp
    src/Font.cpp
    src/Coordinate.cpp
    src/BoundingBox.cpp
    src/Drawing.cpp
)

installheaders(drawing)

installlib(titan-drawing)

add_gtest(
    NAME drawing 
    SOURCES tests/test.cpp 
    LIBRARIES titan-core titan-drawing
)
