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


void getPrimes(std::vector<long>& primes, long limit) {
  // Using Sieve of Eratosthenes
  // TODO Implement more effiecent algorithm later

  // Making list for the Sieve
  std::vector<bool> sieve(limit + 1, true);
  // Numbers will be indexed from index 1 for simplicity
  sieve[0] = false;
  sieve[1] = false;
  
  // Starting looking from number 2
  long i = 2;
  while (i < limit) {
    if (!sieve[i]) {
      i++;
      continue;
    }
    
    primes.push_back(i);
    long cur = i * i;
    // Eliminating all multiples of this prime, starting from it's square
    while (cur <= limit) {
      sieve[cur] = false;
      cur += i;
    }
    i++;
  }
}
