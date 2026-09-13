#ifndef MATH_FUNCS_HPP
#define MATH_FUNCS_HPP

#include "tokenizer.hpp"


void applyOperator(std::stack<Token>& numStack, const Token& op);
void applyFunction(std::stack<Token>& numStack, const Token& func);

#endif

#pragma once
