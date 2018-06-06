cmake_minimum_required(VERSION 3.5)

project(ANPI_proyecto3 VERSION 0.0.0 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 11)

set(PLOTSOURCES src/main.cpp)
#set(PLOTSOURCES src/test.cpp)

find_package (Boost COMPONENTS program_options REQUIRED)

include_directories( ${Boost_INCLUDE_DIR} )
include_directories("src/utilidades" )
include_directories("src/proceso" )
include_directories("src/gui" )

OPTION (USE_OpenMP "Use OpenMP to enable <omp.h>" ON)

add_executable(Proyecto3 ${PLOTSOURCES})
target_link_libraries(Proyecto3 PRIVATE python2.7 ${Boost_LIBRARIES})

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()