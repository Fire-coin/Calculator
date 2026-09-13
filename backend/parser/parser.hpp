#ifndef PARSER_HPP
#define PARSER_HPP
#include "tokenizer.hpp"
#include <unordered_map>
#include <unordered_set>

/* Stores precedence of operators */
inline const std::unordered_map<TokenType, int8_t> precedence {
  {TokenType::PLUS, 1},
  {TokenType::MINUS, 1},
  {TokenType::MUL, 2},
  {TokenType::DIV, 2},
  {TokenType::POW, 3}
};

/* Stores function types */
inline const std::unordered_set<TokenType> functions {
  TokenType::SIN, TokenType::COS, TokenType::TAN, TokenType::LOG, TokenType::LN
};

/* Stores operator types */
inline const std::unordered_set<TokenType> operators {
  TokenType::PLUS, TokenType::MINUS, TokenType::MUL, TokenType::DIV, TokenType::POW
};

/* Stores left associative operator types */
inline const std::unordered_set<TokenType> leftAss {
  TokenType::PLUS, TokenType::MINUS, TokenType::MUL, TokenType::DIV
};

/* Stores right associative operator types */
inline const std::unordered_set<TokenType> rightAss {
  TokenType::POW
};

inline bool isFunction(Token token);
inline bool isOperator(Token token);
inline bool isLeftAss(Token token);

class Parser {
  public:
    Parser() = default;
    static void parse(const std::vector<Token>& input, std::vector<Token>& RPNOut, int32_t& err);
    static double evaluate(const std::vector<Token>& RPN, int32_t& err);
};
#endif
#pragma once
