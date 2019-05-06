cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)

project(just_a_test)
file(GLOB sources CONFIGURE_DEPENDS ./src/*.cpp ./src/*.hpp)

add_executable(test_exe ${sources})
target_include_directories(test_exe PRIVATE ${CMAKE_SOURCE_DIR}/third_party/glm)

