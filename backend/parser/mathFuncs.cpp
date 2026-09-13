#include "mathFuncs.hpp"
#include <cmath>

/* Pops N top elements from provided number stack and pushes them to vector arr.
 * Also does checks if elements are present on the stack.
 * */
void popN(std::stack<double>& numStack, std::vector<double>& arr, int32_t N, int32_t& err) {
  for (int i = 0; i < N; ++i) {
    if (numStack.empty()) {
      err = -2;
      return;
    }
    arr.push_back(numStack.top());
    numStack.pop();
  }
}

/* Performs given operation on top 2 elements of number stack, because we work with RPN,
 * operands should be used in reverse order they are poped from stack. */
void applyOperator(std::stack<double>& numStack, const Token& op, int32_t& err) {
  /* Operator always takes only 2 arguments */
  double a, b;
  std::vector<double> arr;

  /* Pop top 2 elements from the stack */
  popN(numStack, arr, 2, err);
  if (err < 0)
    return;
  
  a = arr[0];
  b = arr[1];

  /* Push back the result onto the stack */
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

/* Performs given function to arguments, each function can have any number of arguments,
 * their number is specified in switch statement. */
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
