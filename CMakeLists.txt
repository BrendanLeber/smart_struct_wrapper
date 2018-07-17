cmake_minimum_required(VERSION 3.9)

project(smart_wrapper VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(default_build_type "RelWithDebInfo")
if(EXISTS "${CMAKE_SOURCE_DIR}/.git")
  set(default_build_type "Debug")
endif()

if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE STRING "Choose type of build." FORCE)
endif()


option(ENABLE_COVERAGE "Generate code coverage reports." OFF)


if(MSVC)
  add_compile_options(/W3 /WX)
else()
  add_compile_options(-Weverything -pedantic)
  add_compile_options(-Wno-c++98-compat -Wno-c++98-compat-pedantic)
  add_compile_options(-Wno-newline-eof)
  add_compile_options(-Wno-missing-prototypes)
  add_compile_options(-Wno-zero-as-null-pointer-constant)
endif()


add_library(legacy legacy.c)
if(ENABLE_COVERAGE)
  message(STATUS "Enabling code coverage for liblegacy.")
  target_compile_options(legacy PRIVATE -fprofile-instr-generate -fcoverage-mapping)
endif()


add_executable(smart_wrapper smart_wrapper.cpp)
target_compile_features(smart_wrapper PRIVATE cxx_std_14)
target_compile_definitions(smart_wrapper PUBLIC _GLIBCXX_DEBUG)
target_link_libraries(smart_wrapper PRIVATE legacy)
target_link_libraries(smart_wrapper INTERFACE catch2/catch.hpp)
if(ENABLE_COVERAGE)
  message(STATUS "Enabling code coverage for smart_wrappers.")
  target_compile_options(smart_wrapper PRIVATE -fprofile-instr-generate -fcoverage-mapping)
  target_link_libraries(smart_wrapper PRIVATE -fprofile-instr-generate -fcoverage-mapping)
endif()
