cmake_minimum_required(VERSION 3.23)

add_library(tokenizer STATIC
  tokenizer.cpp
)

target_include_directories(tokenizer PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(tokenizerTest
  tokenizerTest.cpp
)

target_link_libraries(tokenizerTest PRIVATE
  tokenizer
)
