include_directories(${PROJECT_SOURCE_DIR}/core/include)

add_library(titan-core SHARED
    src/Config.cpp
    src/Unit.cpp
    src/Types.cpp
    src/SingleQuantity.cpp
    src/Quantity.cpp
    src/PluginFactory.cpp
    src/StreamInterface.cpp
)

if (${OSNAME} MATCHES "LINUX")
    target_link_libraries(titan-core dl)
endif (${OSNAME} MATCHES "LINUX")

if (${OSNAME} MATCHES "MACOSX")
    target_link_libraries(titan-core dl)
endif (${OSNAME} MATCHES "MACOSX")

if (${OSNAME} MATCHES "WINDOWS")
    # !!! write lib loader for windows !!!
    #target_link_libraries(titan-core dl)
endif (${OSNAME} MATCHES "WINDOWS")

installheaders(core)

installlib(titan-core)


add_gtest(
    NAME core 
    SOURCES tests/test.cpp 
    LIBRARIES titan-core
    DEPS titan-core
)
