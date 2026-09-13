#include "mathFuncs.hpp"
#include <cmath>


/* Operator always takes only 2 arguments */
void applyOperator(std::stack<double>& numStack, const Token& op, int32_t& err) {
  /* Pop top 2 elements from the stack */
  double a, b;
  if (numStack.empty()) {
    err = -2;
    return;
  }
  b = numStack.top();
  numStack.pop();
  if (numStack.empty()) {
    err = -2;
    return;
  }
  a = numStack.top();
  numStack.pop();

  switch (op.type) {
    case TokenType::PLUS:
      numStack.push(a + b);
      break;
    case TokenType::MINUS:
      numStack.push(a - b);
      break;
    case TokenType::MUL:
      numStack.push(a * b);
      break;
    case TokenType::DIV:
      if (b == 0) {
        err = -3;
        return;
      }
      numStack.push(a / b);
      break;
    case TokenType::POW:
      numStack.push(std::pow(a, b));
      break;
  }
}
