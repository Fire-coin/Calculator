#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <cstdint>
#include <string>
#include <vector>

enum class TokenType{NUM, PLUS, MINUS, MUL, DIV, POW, LPAR, RPAR, SIN, COS, TAN, LOG, LN, ERR, NOTHING, COMMA};

class Token {
  public:
    Token(TokenType type = TokenType::NUM, double value = 0) : type(type), val(value){};

    std::string toString();

    TokenType type;
    int64_t val;
};

class Tokenizer {
  public:
    Tokenizer() = default;
    static void tokenize(const std::string& input, std::vector<Token>& tokens, int32_t& err);
};

#endif

#pragma once
