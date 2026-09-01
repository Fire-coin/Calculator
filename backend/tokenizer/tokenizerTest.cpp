#include "tokenizer.hpp"
#include <iostream>

int main() {

  std::cout << "Hello from tokenizer!\n";
  std::vector<Token> tokens;
  std::string line;
  std::getline(std::cin, line);
  int err = 0;
  Tokenizer::tokenize(line, tokens, err);
  if (err < 0) {
    std::cout << "Error\n";
    return -1;
  }

  for (auto token : tokens) {
    std::cout << token.toString() << std::endl;
  }

  return 0;
}
