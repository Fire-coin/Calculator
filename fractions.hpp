#ifndef FRACTIONS_HPP
#define FRACTIONS_HPP

#include <iostream>
#include <vector>
#include <string>

int getDigit(char num);

class Fraction {

public:
  long numerator;
  long denominator;

  Fraction(std::string number);
  Fraction(long num, long denom);
  Fraction() : numerator(1), denominator(1) {};
  void simplify();
  
  Fraction operator+ (const Fraction& other);
  Fraction operator- (const Fraction& other);
  Fraction operator- () const;
  Fraction operator* (const Fraction& other);
  Fraction operator/ (const Fraction& other);
};

struct PrimeFactor {
  long prime;
  int power;

  bool operator==(const PrimeFactor& other);
  bool operator<(const PrimeFactor& other);

};

void getPrimes(std::vector<long>& primes, long limit);

void factorise(std::vector<PrimeFactor>& factors, long target);

#endif
