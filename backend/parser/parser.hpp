#include "tokenizer.hpp"

/* Stores precedence of operators */
inline const std::unordered_map<TokenType, int8_t> precedence {
  {TokenType::PLUS, 1},
  {TokenType::MINUS, 1},
  {TokenType::MUL, 2},
  {TokenType::DIV, 2},
};
