cmake_minimum_required(VERSION 3.23)

project(Tokenizer)

add_executable(tokenizer)

target_sources(tokenizer
  PRIVATE
  tokenizer.cpp
  tokenizer.hpp
)
