include_directories(${PROJECT_SOURCE_DIR}/core/include)
include_directories(${PROJECT_SOURCE_DIR}/data/include)

#add_library(titan-data SHARED
#)

installheaders(data)

#installlib(titan-data)


add_gtest(
    NAME data 
    SOURCES tests/test.cpp 
    LIBRARIES titan-core
)
