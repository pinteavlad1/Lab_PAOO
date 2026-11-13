cmake_minimum_required(VERSION 3.10)
project(EffectiveCpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Item 4: Make sure objects are initialized before they are used
# item4.cpp comes first, so its globals are initialized before the ones in FileSystem.cpp
add_executable(item4
    item4/item4.cpp
    item4/FileSystem.cpp
)

# Item 5: Know what functions C++ silently writes and calls
add_executable(item5
    item5/item5.cpp
)

# Item 6: Explicitly disallow the use of compiler generated functions you do not want
add_executable(item6
    item6/item6.cpp
)
