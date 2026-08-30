cmake_minimum_required(VERSION 3.23)

project(Parser)

add_executable(parser)

target_sources(parser
  PRIVATE
  parser.cpp
)
