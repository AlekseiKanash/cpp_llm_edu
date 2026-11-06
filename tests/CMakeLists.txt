include(FetchContent)
include(CheckCXXCompilerFlag)

# SYSTEM keeps our strict warnings from firing inside GoogleTest headers.
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
  SYSTEM)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Newer Clang warns inside GoogleTest's own sources; keep the build output clean.
check_cxx_compiler_flag(-Wno-character-conversion EDU_HAS_WNO_CHARACTER_CONVERSION)
if(EDU_HAS_WNO_CHARACTER_CONVERSION)
  target_compile_options(gtest PRIVATE -Wno-character-conversion)
endif()

add_executable(cpp_llm_edu_tests
  greeting_test.cpp)

target_link_libraries(cpp_llm_edu_tests PRIVATE cpp_llm_edu edu_warnings GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(cpp_llm_edu_tests)
