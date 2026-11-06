add_library(cpp_llm_edu STATIC
  greeting.cpp)

target_include_directories(cpp_llm_edu PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(cpp_llm_edu PRIVATE edu_warnings)
