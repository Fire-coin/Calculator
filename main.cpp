#include <iostream>
#include <vector>
#include "fractions.hpp"


int main() {
  
  std::cout << "Enter decimal number: ";
  std::string number;
  
  std::getline(std::cin, number);

  Fraction frac(number);

  std::cout << "#### Generating test prime numbers ####\n";
  std::vector<long> primes;
  getPrimes(primes, 1000);

  for (auto i : primes)
    std::cout << i << ", ";
  std::cout << std::endl;
  
  std::cout << "#### Finished generating test prime numbers ####\n";
  
  std::cout << "#### Simplifying fraction ####\n";
  frac.simplify();
  std::cout << "Numerator: " << frac.numerator << std::endl;
  std::cout << "Denominator: " << frac.denominator << std::endl;
  std::cout << "#### Finished Simplifying fraction ####\n";

  return 0;

}
