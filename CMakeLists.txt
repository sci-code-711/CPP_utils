cmake_minimum_required(VERSION 3.14)

project(source)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  testBuild
  test/vector_unittest.cpp
  source/vector.hpp
  source/vector.cpp
  test/matrix_unittest.cpp
  source/matrix.hpp
  source/matrix.cpp
  test/quaternion_unittest.cpp
  source/quaternion.hpp
  source/quaternion.cpp
)

target_link_libraries(
  testBuild
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(testBuild)
