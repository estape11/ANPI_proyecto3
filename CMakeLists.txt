cmake_minimum_required(VERSION 3.5)

project(ANPI_proyecto3 VERSION 0.0.0 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 11)

#set(PLOTSOURCES src/main.cpp src/test.cpp)
set(PLOTSOURCES src/test.cpp)

find_package (Boost COMPONENTS program_options REQUIRED)

include_directories( ${Boost_INCLUDE_DIR} )
include_directories("src/utilidades" )
include_directories("src/Process" )
include_directories("src/gui" )

set(CMAKE_C_COMPILER "/usr/local/Cellar/llvm/6.0.0/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/local/Cellar/llvm/6.0.0/bin/clang++")
set(OPENMP_LIBRARIES "/usr/local/Cellar/llvm/6.0.0/lib")
set(OPENMP_INCLUDES "/usr/local/Cellar/llvm/6.0.0/include")

OPTION (USE_OpenMP "Use OpenMP to enable <omp.h>" ON)

add_executable(Proyecto3 ${PLOTSOURCES})
target_link_libraries(Proyecto3 PRIVATE python2.7 ${Boost_LIBRARIES})

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")
endif()

if(APPLE AND USE_OpenMP)
    if(CMAKE_C_COMPILER_ID MATCHES "Clang")
        set(OpenMP_C "${CMAKE_C_COMPILER}")
        set(OpenMP_C_FLAGS "-fopenmp=libomp -Wno-unused-command-line-argument")
        set(OpenMP_C_LIB_NAMES "libomp" "libgomp" "libiomp5")
        set(OpenMP_libomp_LIBRARY ${OpenMP_C_LIB_NAMES})
        set(OpenMP_libgomp_LIBRARY ${OpenMP_C_LIB_NAMES})
        set(OpenMP_libiomp5_LIBRARY ${OpenMP_C_LIB_NAMES})
    endif()
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        set(OpenMP_CXX "${CMAKE_CXX_COMPILER}")
        set(OpenMP_CXX_FLAGS "-fopenmp=libomp -Wno-unused-command-line-argument")
        set(OpenMP_CXX_LIB_NAMES "libomp" "libgomp" "libiomp5")
        set(OpenMP_libomp_LIBRARY ${OpenMP_CXX_LIB_NAMES})
        set(OpenMP_libgomp_LIBRARY ${OpenMP_CXX_LIB_NAMES})
        set(OpenMP_libiomp5_LIBRARY ${OpenMP_CXX_LIB_NAMES})
    endif()
endif()

if(USE_OpenMP)
    find_package(OpenMP REQUIRED)
endif(USE_OpenMP)

if (OPENMP_FOUND)
    include_directories("${OPENMP_INCLUDES}")
    link_directories("${OPENMP_LIBRARIES}")
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif(OPENMP_FOUND)