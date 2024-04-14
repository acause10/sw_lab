#CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

project(sel-homework_2)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CODE_COVERAGE ON)
  include(CodeCoverage)
  add_code_coverage_all_targets(EXCLUDE /usr/* /Library/*
                                ${PROJECT_BINARY_DIR}/_deps/*)
  add_custom_target(coverage DEPENDS ccov-all)
endif()

add_subdirectory(geometry2d)
add_subdirectory(util)

add_executable(main test/main.cpp  
test/util/compare_test.cpp
test/geometry2d/angle_test.cpp
test/geometry2d/line_test.cpp
test/geometry2d/pose_test.cpp
test/geometry2d/geo_compare_test.cpp
test/geometry2d/point_test.cpp
test/geometry2d/circle_test.cpp
)

target_link_libraries(main PUBLIC geometry2d)
target_link_libraries(main PRIVATE gtest gtest_main)

if(CODE_COVERAGE)
  target_code_coverage(main AUTO ALL)
endif()

if(CODE_COVERAGE)
  target_code_coverage(geometry2d AUTO ALL)
endif()

if(CODE_COVERAGE)
  target_code_coverage(util AUTO ALL)
endif()

include(CTest)
enable_testing()

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY git://github.com/google/googletest.git
  GIT_TAG origin/master)

FetchContent_MakeAvailable(googletest)
# Now these targets are available:
# gtest
# gtest_main

include(GoogleTest)

gtest_discover_tests(main)

include(ClangTidy)
