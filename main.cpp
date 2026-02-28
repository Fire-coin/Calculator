#include <iostream>
#include "fractions.hpp"

int main() {
  
  std::cout << "Enter decimal number: ";
  double number;
  std::cin >> number;
  
  Fraction frac(number);

  return 0;

}
