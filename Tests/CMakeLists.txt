# Tests CMakeLists.txt

target_include_directories(Tiny INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty)


function(tiny_add_test name)
  add_executable(${name} ${ARGN})
  target_link_libraries(${name} PRIVATE Tiny doctest)
  target_compile_options(${name} PRIVATE)
  add_test(NAME ${name} COMMAND ${name})
endfunction()

tiny_add_test(Test_Vector Unit/Test_Vector.cpp)
tiny_add_test(Test_Matrix Unit/Test_Matrix.cpp)