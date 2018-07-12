cmake_minimum_required(VERSION 3.10)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

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

add_executable(smart_wrapper smart_wrapper.cpp)
target_compile_features(smart_wrapper PRIVATE cxx_std_14)
target_compile_definitions(smart_wrapper PUBLIC _GLIBCXX_DEBUG)
target_link_libraries(smart_wrapper legacy)
