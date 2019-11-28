cmake_minimum_required(VERSION 3.15)
project(SimAnnealing)

set(CMAKE_CXX_STANDARD 14)

add_executable(SimAnnealing main.cpp Matrix.cpp Matrix.h Annealing.cpp Annealing.h Solution.cpp Solution.h)