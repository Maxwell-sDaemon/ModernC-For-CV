cmake_minimum_required(VERSION 3.15.2)
project(hw1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

add_library(ipb_arithmetic src/sum.cpp src/subtract.cpp)

set(EXECUTABLE_OUTPUT_PATH ../src)

add_executable(cmake_main src/main.cpp)
target_link_libraries(cmake_main ipb_arithmetic)

set_target_properties(
    cmake_main 
    PROPERTIES 
        OUTPUT_NAME "my_cmake_main"
        
)