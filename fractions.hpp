#include <iostream>
#include <vector>

bool isDecimal(double number);


class Fraction {

public:
  long numerator;
  long denominator;
  int power;

  Fraction(double number);

};

struct PrimeFactor {
  long prime;
  int power;

  bool operator==(const PrimeFactor& other);
  bool operator<(const PrimeFactor& other);

};

void getPrimes(std::vector<long>& primes, long limit);

void factorise(std::vector<PrimeFactor>& factors, long target);
