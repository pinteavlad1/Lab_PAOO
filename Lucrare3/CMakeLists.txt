cmake_minimum_required(VERSION 3.10)
project(DSU)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(dsu_working
    src/main.cpp 
    src/Dsu.cpp    
)
target_include_directories(dsu_working
    PRIVATE include
)
target_compile_definitions(dsu_working PRIVATE 
    VARIANT_NAME="WORKING"
)

add_executable(dsu_no_destructor
    src/main.cpp 
    src/Dsu.cpp    
)
target_include_directories(dsu_no_destructor
    PRIVATE include
)
target_compile_definitions(dsu_no_destructor PRIVATE 
    VARIANT_NAME="NO_DESTRUCTOR"
    NO_DESTRUCTOR
    NO_COPY_CONSTRUCTOR
    NO_MOVE_CONSTRUCTOR
)

add_executable(dsu_no_copy_constructor
    src/main.cpp 
    src/Dsu.cpp    
)
target_include_directories(dsu_no_copy_constructor
    PRIVATE include
)
target_compile_definitions(dsu_no_copy_constructor PRIVATE 
    VARIANT_NAME="NO_COPY_CONSTRUCTOR"
    NO_COPY_CONSTRUCTOR
    NO_MOVE_CONSTRUCTOR
)

add_executable(dsu_no_move_constructor
    src/main.cpp 
    src/Dsu.cpp    
)
target_include_directories(dsu_no_move_constructor
    PRIVATE include
)
target_compile_definitions(dsu_no_move_constructor PRIVATE 
    VARIANT_NAME="NO_MOVE_CONSTRUCTOR"
    NO_MOVE_CONSTRUCTOR
)