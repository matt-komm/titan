project(TITAN)
cmake_minimum_required(VERSION 2.8.3)

include(detectOS.cmake)


set(CMAKE_CXX_FLAGS "-Wextra -Wall -pedantic -std=c++0x -Wno-unused-parameter"${CMAKE_CXX_FLAGS} )
set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/release)

macro(installheaders package)
    file(GLOB files "${PROJECT_SOURCE_DIR}/${package}/include/titan/${package}/*.hpp")
    install(
        FILES 
            ${files}
        DESTINATION 
            include/titan/${package}
    )
endmacro(installheaders)

macro(installlib targetname)
    install(
        TARGETS
            ${targetname}
        DESTINATION
            libs
    )
endmacro(installlib)

macro(copy_file_if_changed in_file out_file target)  
    	add_custom_command (
    		TARGET     ${target}
    		POST_BUILD
    		COMMAND    ${CMAKE_COMMAND}
    		ARGS       -E copy_if_different ${in_file} ${out_file}
    		COMMENT "Copying file: ${in_file} to: ${out_file}"
    	)
endmacro(copy_file_if_changed)


OPTION(ENABLE_TEST "Build tests" OFF)
OPTION(ENABLE_VERBOSE_TEST "verbose tests" OFF)

include (CMakeParseArguments)

if (ENABLE_TEST)
    enable_testing()
    if (ENABLE_VERBOSE_TEST)
        add_custom_target(runtests ${CMAKE_CTEST_COMMAND} -V)
    else (ENABLE_VERBOSE_TEST)
        add_custom_target(runtests ${CMAKE_CTEST_COMMAND})
    endif (ENABLE_VERBOSE_TEST)
    add_custom_target(buildtests) 
    add_custom_target(prebuildtests) #use for e.g. copying files before tests are run
    add_dependencies(runtests buildtests)
    add_dependencies(buildtests prebuildtests)
    
    include_directories(${PROJECT_SOURCE_DIR}/external/gtest/include)
    
    macro(add_gtest)
        cmake_parse_arguments(
            TEST                        #prefix
            ""                          #options
            "NAME"                   #one_value_keywords
            "SOURCES;LIBRARIES"   #multi_value_keywords
            ${ARGN} 
        )
        add_executable(gtest-${TEST_NAME}
            ${TEST_SOURCES}
        )
        target_link_libraries(gtest-${TEST_NAME} ${TEST_LIBRARIES} gtest gtest_main)
        add_test(${TEST_NAME} gtest-${TEST_NAME} --gtest_color=yes)
        #add_test(memtest-${TEST_NAME} valgrind --tool=memcheck --leak-check=summary ${CMAKE_CURRENT_BINARY_DIR}/gtest-${TEST_NAME} > /dev/null)
        add_dependencies(runtests gtest-${TEST_NAME})
    endmacro(add_gtest)
    
else(ENABLE_TEST)
    macro(add_gtest)
        cmake_parse_arguments(
            TEST                        #prefix
            ""                          #options
            "NAME"                   #one_value_keywords
            "SOURCES;LIBRARIES"   #multi_value_keywords
            ${ARGN} 
        )
        message(STATUS "Testing disabled: Skipping test ... "${TEST_NAME})
    endmacro(add_gtest)
endif(ENABLE_TEST)

add_subdirectory(core)
add_subdirectory(drawing)
add_subdirectory(histogram)
add_subdirectory(addons)
add_subdirectory(external)
add_subdirectory(xml)
add_subdirectory(data)
