cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Autograd VERSION 1.0)
# file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS "src/*.cpp")
# add_executable(Autograd src/main.cpp)
# add_executable(Autograd ${SRC_FILES})
# add_executable(test ${SRC_FILES})
add_executable(Autograd src/main.cpp)
add_executable(test src/main.cpp)

# add dependencies (CPM)
include(cmake/CPM.cmake)

CPMAddPackage(
    NAME xtensor
    GITHUB_REPOSITORY xtensor-stack/xtensor
    GIT_TAG 0.25.0
)

CPMAddPackage(
    NAME magic_enum
    GITHUB_REPOSITORY Neargye/magic_enum
    GIT_TAG v0.9.7
)

target_link_libraries(Autograd PUBLIC xtensor)
target_link_libraries(test PUBLIC xtensor)

target_link_libraries(Autograd PUBLIC magic_enum)
target_link_libraries(test PUBLIC magic_enum)