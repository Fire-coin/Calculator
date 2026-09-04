#include "parser.hpp"
#include <stack>
#include <iostream>


inline bool isFunction(Token token) {
  return functions.find(token.type) != functions.end();
}

inline bool isOperator(Token token) {
  return operators.find(token.type) != operators.end();
}

inline bool isLeftAss(Token token) {
  return leftAss.find(token.type) != leftAss.end();
}
/* there is an operator o2 at the top of the operator stack which is not a left parenthesis, 
 * and (o2 has greater precedence than o1 or (o1 and o2 have the same precedence and o1 is left-associative)) */
inline bool operatorCondition(const std::stack<Token>& opStack, const Token& curToken) {
  return (!opStack.empty() && isOperator(opStack.top())
          && (precedence.at(opStack.top().type) > precedence.at(curToken.type)
              || (precedence.at(opStack.top().type) == precedence.at(curToken.type)
                && isLeftAss(curToken))));
}

/* Using shunting yard algorithm to parse instructions */
void Parser::parse(const std::vector<Token>& input, std::vector<Token>& RPNOut, int32_t& err) {
  RPNOut.clear();
  
  std::stack<Token> opStack;

  for (const Token& curToken : input) {
    /* If a number, push into output */
    if (curToken.type == TokenType::NUM) {
      RPNOut.push_back(curToken);
      continue;
    }
    /* If a function, push onto operator stack */
    if (isFunction(curToken)) {
      opStack.push(curToken);
      continue;
    }

    /* If an operator then push into output under some condition */
    if (isOperator(curToken)) {
        while (operatorCondition(opStack, curToken)) {
          RPNOut.push_back(opStack.top());
          opStack.pop();
        }
        opStack.push(curToken);
    }

    /* Do specific behaviour on rest of the tokens types */
    switch (curToken.type) {
      case TokenType::COMMA:
        /* Popping operators into output until top of stack is not left parenthesis */
        while (!opStack.empty() && opStack.top().type != TokenType::LPAR) {
          RPNOut.push_back(opStack.top());
          opStack.pop();
        }
        break;
      case TokenType::LPAR:
        opStack.push(curToken);
        break;
      case TokenType::RPAR:
        /* Pop operator stack until left parenthesis is found */
        while (!opStack.empty() && opStack.top().type != TokenType::LPAR) {
          RPNOut.push_back(opStack.top());
          opStack.pop();
        }
        /* Mismatched parentheses */
        if (opStack.empty() || opStack.top().type != TokenType::LPAR) {
          std::cerr << "Mismatched parentheses\n";
          err = -1;
          return;
        }

        /* Popping left parenthesis out of the stack */
        opStack.pop();

        /* If there is function at top of operator stack, pop it */
        if (!opStack.empty() && isFunction(opStack.top())) {
          RPNOut.push_back(opStack.top());
          opStack.pop();
        }
        break;
      default:
        break;
    }
  }

  while (!opStack.empty()) {
    /* Mismatched parentheses */
    if (opStack.top().type == TokenType::LPAR || opStack.top().type == TokenType::RPAR) {
      std::cerr << "Mismatched parentheses\n";
      err = -1;
      return;
    }
    RPNOut.push_back(opStack.top());
    opStack.pop();
  }
}
