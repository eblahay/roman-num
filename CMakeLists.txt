cmake_minimum_required(VERSION 3.22)

# set project name
project(roman-num VERSION 0.1.0)

# specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# lib
add_library(roman-num STATIC src/lib/roman-num.cxx)

# app
add_executable(roman-num-app src/app/main.cxx)
target_link_libraries(roman-num-app roman-num Boost::program_options)
set_target_properties(roman-num-app PROPERTIES OUTPUT_NAME roman-num) # make it so the executable is named 'roman-num'

find_package(Boost 1.74 COMPONENTS program_options REQUIRED)

# target_include_directories must be added AFTER add_executable
include_directories(include ${Boost_INCLUDE_DIR}) 