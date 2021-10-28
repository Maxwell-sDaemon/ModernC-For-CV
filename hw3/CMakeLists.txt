cmake_minimum_required(VERSION 3.15.2)
project(image_browser_part1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

add_library(html_writer src/html_writer.cpp)
add_library(helper src/helper.cpp)
add_library(image_browser src/image_browser.cpp)

set(EXECUTABLE_OUTPUT_PATH ../bin)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g 03") # boost optinmized
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.45.0 COMPONENTS filesystem) 

if(Boost_FOUND)
    add_executable(main src/test.cpp)
    target_link_libraries(main html_writer helper ${Boost_LIBRARIES} image_browser)
endif()

