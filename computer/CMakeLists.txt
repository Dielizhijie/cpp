cmake_minimum_required(VERSION 3.9)
project(computer)

set(CMAKE_CXX_STANDARD 11)

add_executable(computer main.cpp array/Array.cpp array/Array.h data/Data.cpp data/Data.h system/System.cpp system/System.h decimal/Decimal.cpp decimal/Decimal.h matrix/Matrix.cpp matrix/Matrix.h)