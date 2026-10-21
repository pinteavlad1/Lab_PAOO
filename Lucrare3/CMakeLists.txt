cmake_minimum_required(VERSION 3.10)
project(DSU)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(dsu 
    src/main.cpp 
    src/Dsu.cpp
    src/no_copy_constructor.cpp
    src/no_move_constructor.cpp
    src/no_destructor.cpp
    endmacro()
    
)

target_include_directories(dsu PRIVATE include)