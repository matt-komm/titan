include_directories(${PROJECT_SOURCE_DIR}/core/include)

add_library(titan-core SHARED
    src/Config.cpp
    src/Quantity.cpp
)

add_executable(titan-core-test
    test/test.cpp
)
target_link_libraries(titan-core-test titan-core)

installheaders(core)

installlib(titan-core)
