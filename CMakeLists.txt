cmake_minimum_required(VERSION 3.25)

project(cpp_llm_edu VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(EDU_ENABLE_SANITIZERS "Build with AddressSanitizer and UBSan" OFF)
option(EDU_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)
option(EDU_BUILD_TESTS "Build unit tests" ON)

add_library(edu_warnings INTERFACE)
target_compile_options(edu_warnings INTERFACE
  $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall -Wextra -Wpedantic -Wshadow -Wconversion>
  $<$<CXX_COMPILER_ID:MSVC>:/W4>)

if(EDU_WARNINGS_AS_ERRORS)
  target_compile_options(edu_warnings INTERFACE $<IF:$<CXX_COMPILER_ID:MSVC>,/WX,-Werror>)
endif()

if(EDU_ENABLE_SANITIZERS AND NOT MSVC)
  target_compile_options(edu_warnings INTERFACE -fsanitize=address,undefined -fno-omit-frame-pointer)
  target_link_options(edu_warnings INTERFACE -fsanitize=address,undefined)
endif()

add_subdirectory(src)
add_subdirectory(app)

if(EDU_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
