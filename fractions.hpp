#include <iostream>
#include <vector>

bool isDecimal(double number);


class Fraction {

public:
  
  Fraction(double number);

};

struct PrimeFactor {
  long prime;
  int power;
};

void getPrimes(std::vector<long>& primes, long limit);
