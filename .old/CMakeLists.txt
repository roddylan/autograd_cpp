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

# packages
find_package(xtensor REQUIRED)

# xtensor
target_include_directories(Autograd PUBLIC ${xtensor_INCLUDE_DIRS})
target_link_libraries(Autograd PUBLIC xtensor)

target_include_directories(test PUBLIC ${xtensor_INCLUDE_DIRS})
target_link_libraries(test PUBLIC xtensor)

# magic_enum
target_include_directories(Autograd PUBLIC ${magic_enum})
target_link_libraries(Autograd PUBLIC magic_enum)

target_include_directories(test PUBLIC ${magic_enum})
target_link_libraries(test PUBLIC magic_enum)


# headers
target_include_directories(Autograd PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/autograd)
target_include_directories(test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/autograd)

