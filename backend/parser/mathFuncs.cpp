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

void popN(std::stack<double>& numStack, std::vector<double>& arr, int32_t n, int32_t& err) {
  for (int i = 0; i < n; ++i) {
    if (numStack.empty()) {
      err = -2;
      return;
    }
    arr.push_back(numStack.top());
    numStack.pop();
  }
}

void applyFunction(std::stack<double>& numStack, const Token& func, int32_t& err) {
  std::vector<double> args;

  switch (func.type) {
    case TokenType::SIN:
      popN(numStack, args, 1, err);
      numStack.push(std::sin(args[0]));
      break;
    case TokenType::COS:
      popN(numStack, args, 1, err);
      numStack.push(std::cos(args[0]));
      break;
    case TokenType::TAN:
      popN(numStack, args, 1, err);
      numStack.push(std::tan(args[0]));
      break;
    case TokenType::LOG:
      popN(numStack, args, 1, err);
      numStack.push(std::log10(args[0]));
      break;
    case TokenType::LN:
      popN(numStack, args, 1, err);
      numStack.push(std::log(args[0]));
      break;
  }
}
