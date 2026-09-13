#ifndef MATH_FUNCS_HPP
#define MATH_FUNCS_HPP

#include "tokenizer.hpp"
#include <stack>

void applyOperator(std::stack<double>& numStack, const Token& op, int32_t& err);
void applyFunction(std::stack<double>& numStack, const Token& func, int32_t& err);

#endif

#pragma once
