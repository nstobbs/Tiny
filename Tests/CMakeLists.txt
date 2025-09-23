# Tests CMakeLists.txt

add_library(doctest INTERFACE)
target_include_directories(doctest INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty)


function(tiny_add_test name)
  add_executable(${name} ${ARGN})
  target_link_libraries(${name} PRIVATE Tiny doctest)
  target_compile_options(${name} PRIVATE -Wall -Wextra -Wpedantic)
  add_test(NAME ${name} COMMAND ${name})
endfunction()

tiny_add_test(vec_tests Unit/Test_Vector.cpp)