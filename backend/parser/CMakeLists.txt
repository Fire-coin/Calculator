cmake_minimum_required(VERSION 3.23)

add_library(parser STATIC
  parser.cpp
)

target_include_directories(parser PRIVATE
  ${CMAKE_CURRENT_DIR}
)

target_link_libraries(parser PUBLIC 
  tokenizer
)

add_executable(parserTest
  parserTest.cpp
)

target_link_libraries(parserTest PRIVATE
  parser
)
