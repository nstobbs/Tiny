# Root CMakeLists.txt

cmake_minimum_required(VERSION 3.20)
set(CXX_STANDARD 20)

project(Tiny)

add_library(Tiny INTERFACE)

target_include_directories(Tiny INTERFACE ${CMAKE_SOURCE_DIR}/include)
target_compile_features(Tiny INTERFACE cxx_std_20) #fixes build issues on macOS

add_subdirectory(ThirdParty)

option(TINY_BUILD_TESTS "Build Tests" ON)
if (TINY_BUILD_TESTS)
  enable_testing()
  add_subdirectory(Tests)
endif()

# TODO: Coming Soon!
option(TINY_BUILD_EXAMPLES "Build Examples" OFF)
if (TINY_BUILD_EXAMPLES)
  enable_testing()
  add_subdirectory(Examples)
endif()