cmake_minimum_required(VERSION 3.20)
project(labo6crible)

set(CMAKE_CXX_STANDARD 17)

file(GLOB allFiles
        "*.h"
        "*.cpp"
        )
add_executable(labo6crible ${allFiles})