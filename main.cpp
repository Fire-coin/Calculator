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
  
  std::cout << "#### Fraction ####\n";
  std::cout << "Numerator: " << frac.numerator << std::endl;
  std::cout << "Denominator: " << frac.denominator << std::endl;
  std::cout << "#### Finished Fraction ####\n";
  
  std::cout << "Enter second decimal number: ";
  std::getline(std::cin, number);

  Fraction frac2(number);

  std::cout << "#### Second fraction ####\n";
  std::cout << "Numerator: " << frac2.numerator << std::endl;
  std::cout << "Denominator: " << frac2.denominator << std::endl;
  std::cout << "#### Finished Second fraction ####\n";
  
  std::cout << "#### Addition of fractions ####\n";
  Fraction frac3 = frac + frac2;
  std::cout << "Result Numerator: " << frac3.numerator << std::endl;
  std::cout << "Result Denominator: " << frac3.denominator << std::endl;
  std::cout << "#### Finished addition of fractions ####\n";
  
  
  std::cout << "#### Substraction of fractions ####\n";
  Fraction frac4 = frac - frac2;
  std::cout << "Result Numerator: " << frac4.numerator << std::endl;
  std::cout << "Result Denominator: " << frac4.denominator << std::endl;
  std::cout << "#### Finished substraction of fractions ####\n";

  std::cout << "#### Multiplication of fractions ####\n";
  Fraction frac5 = frac * frac2;
  std::cout << "Result Numerator: " << frac5.numerator << std::endl;
  std::cout << "Result Denominator: " << frac5.denominator << std::endl;
  std::cout << "#### Finished multiplication of fractions ####\n";
  
  std::cout << "#### Division of fractions ####\n";
  Fraction frac6 = frac / frac2;
  std::cout << "Result Numerator: " << frac6.numerator << std::endl;
  std::cout << "Result Denominator: " << frac6.denominator << std::endl;
  std::cout << "#### Finished division of fractions ####\n";
            
  return 0;

}
