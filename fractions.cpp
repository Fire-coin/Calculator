#include <iostream>
#include <cmath>
#include "fractions.hpp"

bool isDecimal(double number) {
  return number == std::floor(number);
}

Fraction::Fraction(double number) {
  // Making number decimal
  int power = 0;
  while (!isDecimal(number)) {
    number *= 10;
    power++;
  }
  std::cout << "New number: " << number << "; power: " << power << std::endl; 
}
