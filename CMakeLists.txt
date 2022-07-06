cmake_minimum_required(VERSION 3.16)
project(ADCM_modules)
find_package(Eigen3 3.4.0 REQUIRED NO_MODULE)
find_library(HDMAP_LIB hdmap "${CMAKE_SOURCE_DIR}/linux")
find_library(PROJ_LIB proj "${CMAKE_SOURCE_DIR}/linux")
find_package(OpenCV REQUIRED)
find_program( MEMORYCHECK_COMMAND valgrind )
set( MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --leak-check=full" )

set(CMAKE_CXX_STANDARD 14)

add_compile_options("-g")

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/map_elements.cpp
    ${PROJECT_SOURCE_DIR}/src/raster_utils.cpp
    ${PROJECT_SOURCE_DIR}/src/map_utils.cpp
    ${PROJECT_SOURCE_DIR}/src/geo_element.cpp
    ${PROJECT_SOURCE_DIR}/src/geo_points.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/inc
)

target_link_libraries(${PROJECT_NAME}
    ${HDMAP_LIB}
    ${PROJ_LIB}
    ${OpenCV_LIBS}
    Eigen3::Eigen
)

