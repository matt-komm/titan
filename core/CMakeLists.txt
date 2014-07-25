include_directories(${PROJECT_SOURCE_DIR}/core/include)

add_library(titan-core SHARED
    src/Config.cpp
    src/Unit.cpp
    src/SingleQuantity.cpp
    src/Quantity.cpp
)

installheaders(core)

installlib(titan-core)


add_gtest(
    NAME core 
    SOURCES tests/test.cpp 
    LIBRARIES titan-core
)
