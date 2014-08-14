#determine system: Linux,MacOSX,Windows
set(OSNAME FALSE)
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux" OR UNIX AND NOT APPLE OR CYGWIN)
    set(OSNAME "LINUX")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux" OR UNIX AND NOT APPLE OR CYGWIN)
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin" OR APPLE)
   set(OSNAME "MACOSX")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin" OR APPLE)
if(${CMAKE_SYSTEM_NAME} MATCHES "Win" OR WIN32)
   set(OSNAME "WINDOWS")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Win" OR WIN32)

if(OSNAME)
    message(STATUS "Detected OS: "${OSNAME})
    add_definitions(-DOS_${OSNAME})
else(OSNAME)
    message(FATAL_ERROR "Can not determine OS")
endif(OSNAME)


#determine compiler
set(COMPILER FALSE)
if(${CMAKE_CXX_COMPILER} MATCHES "clang\\+\\+")
    set(COMPILER "CLANG")
endif(${CMAKE_CXX_COMPILER} MATCHES "clang\\+\\+")
if(${CMAKE_CXX_COMPILER} MATCHES "g\\+\\+" OR CMAKE_COMPILER_IS_GNUCXX)
    set(COMPILER "GCC")
endif(${CMAKE_CXX_COMPILER} MATCHES "g\\+\\+" OR CMAKE_COMPILER_IS_GNUCXX)
if(${MSVC} OR ${CMAKE_CL_64})
    set(COMPILER "MSVC")
endif(${MSVC} OR ${CMAKE_CL_64})
if(${CYGWIN})
    set(COMPILER "CYGWIN")
endif(${CYGWIN})
if(${BORLAND})
    set(COMPILER "BORLAND")
endif(${BORLAND})
if (${CMAKE_CXX_COMPILER} MATCHES "icc")
    set(COMPILER "INTEL")
endif(${CMAKE_CXX_COMPILER} MATCHES "icc")

if(COMPILER)
    message(STATUS "Detected Compiler: "${COMPILER})
    add_definitions(-DCOMPILER_${COMPILER})
else(COMPILER)
    message(FATAL_ERROR "Can not determine compiler")
endif(COMPILER)
