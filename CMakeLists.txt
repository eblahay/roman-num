cmake_minimum_required(VERSION 3.22)

# set project name
project(roman-num)

# add library
set(LIB_SOURCES
    src/roman-num.cxx
)
add_library(roman-num-lib STATIC ${LIB_SOURCES})

# add executable
set(APP_SOURCES
    src/main.cxx
)
add_executable(roman-num ${APP_SOURCES})
target_link_libraries(roman-num roman-num-lib)

# target_include_directories must be added AFTER add_executable
include_directories(include)

# libraries


# specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)