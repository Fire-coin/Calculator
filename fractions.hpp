#include <iostream>
#include <vector>
#include <string>

int getDigit(char num);

class Fraction {

public:
  long numerator;
  long denominator;
  int power;

  Fraction(std::string number);

};

struct PrimeFactor {
  long prime;
  int power;

  bool operator==(const PrimeFactor& other);
  bool operator<(const PrimeFactor& other);

};

void getPrimes(std::vector<long>& primes, long limit);

void factorise(std::vector<PrimeFactor>& factors, long target);
