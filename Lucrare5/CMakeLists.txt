cmake_minimum_required(VERSION 3.10)
project(EffectiveCpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Item 10: Have assignment operators return a reference to *this
add_executable(item10
    item10/item10.cpp
)

# Item 11: Handle assignment to self in operator=
add_executable(item11
    item11/item11.cpp
)

# Item 12: Copy all parts of an object
add_executable(item12
    item12/item12.cpp
)
