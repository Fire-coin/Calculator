#include <iostream>
#include <vector>
#include "fractions.hpp"


int main() {
  
  std::cout << "Enter decimal number: ";
  double number;
  std::cin >> number;
  
  Fraction frac(number);

  std::cout << "#### Generating prime numbers ####\n";
  std::vector<long> primes;
  getPrimes(primes, 1000);

  for (auto i : primes)
    std::cout << i << ", ";
  std::cout << std::endl;
  
  std::cout << "#### Finished generating prime numbers ####\n";

  return 0;

}
