#include "tokenizer.hpp"
#include <iostream>

std::string Token::toString() {
  return "type: " + std::to_string((int)this->type) + ", val: " + std::to_string(this->val);
}

bool isDigit(const char c) {
 return '0' <= c && c <= '9';
}


bool isLetter(const char c) {
  return 'a' <= c && c <= 'z';
}

/* Returns token type representation of operator. If character is lower case letter, it returns NOTHING, because it can be a multiletter operator / function (sin, cos). Otherwise ERR is returned. */
TokenType getOperator(const char c) {
  switch(c) {
    case '+':
      return TokenType::PLUS;
    case '-':
      return TokenType::MINUS;
    case '*':
      return TokenType::MUL;
    case '/':
      return TokenType::DIV;
    case '(':
      return TokenType::LPAR;
    case ')':
      return TokenType::RPAR;
    case '^':
      return TokenType::POW;
    default:
      if (isLetter(c))
        return TokenType::NOTHING;
      else
        return TokenType::ERR;
  }
}

/* Returns token type representation for multiletter operators / functions. If no function is matched with provided func, returns ERR. */
TokenType getFunction(const std::string& func) {
  if (func == "sin")
    return TokenType::SIN;
  if (func == "cos")
    return TokenType::COS;
  if (func == "tan")
    return TokenType::TAN;
  if (func == "log")
    return TokenType::LOG;
  if (func == "ln")
    return TokenType::LN;

  return TokenType::ERR;
}

/* Splits input into tokens with token types from TokenType. Populates tokens vector with them. */
void Tokenizer::tokenize(const std::string& input, std::vector<Token>& tokens, int& err) {
  tokens.clear();
  std::string numBuffer, opBuffer;

  for (size_t i = 0; i < input.size(); ++i) {
    /* Adding currect character into numBuffer if it is a digit */
    if (isDigit(input[i])) {
      numBuffer += input[i];
      continue;
    } else if (!numBuffer.empty()) { /* Add number from numBuffer as a token */
      tokens.emplace_back(TokenType::NUM, std::stod(numBuffer));
      numBuffer.clear();
    }
    /* Checking if current character is operator */
    TokenType type = getOperator(input[i]);
    
    /* Current character is lower case letter, which can be part of multi letter function name */
    if (type == TokenType::NOTHING) {
      opBuffer += input[i];
      continue;
    }
    
    if (type == TokenType::ERR) {
      std::cout << "Invalid token: " << input[i] << std::endl;
      err = -1;
      return;
    }
    
    /* Checking if operator buffer is one of multi letter functions */
    if (!opBuffer.empty()) {
      TokenType funcType = getFunction(opBuffer);
      if (funcType == TokenType::ERR) {
        std::cout << "Invalid token: " << opBuffer << std::endl;
        err = -1;
        return;
      }
      tokens.emplace_back(funcType);
      opBuffer.clear();
    }
    /* Adding token to the vector */
    tokens.emplace_back(type);
  }
  /* Add number from numBuffer as a token */
  if (!numBuffer.empty()) { 
      tokens.emplace_back(TokenType::NUM, std::stod(numBuffer));
      numBuffer.clear();
  }
  err = 0;
}
