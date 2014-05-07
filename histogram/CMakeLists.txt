include_directories(${PROJECT_SOURCE_DIR}/core/include)
include_directories(${PROJECT_SOURCE_DIR}/drawing/include)
include_directories(${PROJECT_SOURCE_DIR}/histogram/include)

add_library(titan-histogram SHARED
    src/Histogram.cpp
)

installheaders(histogram)

installlib(titan-histogram)
