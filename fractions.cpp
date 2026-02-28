#include <iostream>
#include <cmath>
#include "fractions.hpp"
#include <algorithm>

bool isDecimal(double number) {
  return number == std::floor(number);
}
// TODO interpret number as string and process also as string to remove floating point error
Fraction::Fraction(double number) {
  // Making number decimal
  int power = 0;
  while (!isDecimal(number)) {
    number *= 10;
    power++;
  }
  this->numerator = number;
  this->power = power;
  this->denominator = std::pow(10, power);
  std::cout << "New number: " << number << "; power: " << power << std::endl; 
}

bool PrimeFactor::operator==(const PrimeFactor& other) {return this->prime == other.prime && this->power == other.power;}

bool PrimeFactor::operator<(const PrimeFactor& other) {return this->prime < other.prime;}

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

void factorise(std::vector<PrimeFactor>& factors, long target) {
  long limit = std::sqrt(target);
  // TODO make the prime number rendering in batches of e.g 1000
  std::vector<long> primes;
  getPrimes(primes, limit); // Getting all prime numbers up to limit
  long primeIndex = 0;
  while (primeIndex < primes.size() && target != 1) {
    long curPrime = primes[primeIndex];
    // Skipping if prime is not prime factor 
    if (target % curPrime != 0) {
      primeIndex++;
      continue;
    }
    // Looking for same prime factor as current prime 
    auto it = std::find_if(factors.begin(), factors.end(), [&curPrime](PrimeFactor p){
      return p.prime == curPrime;
      });
    
    if (it != factors.end()) // Incrementing power of already used prime
      it->power++;
    else { // Adding new prime with power of 1 
      PrimeFactor dummy;
      dummy.prime = curPrime;
      dummy.power = 1;
      factors.push_back(dummy);
    }

    target /= curPrime; 
  }
  // If none of primes up to sqrt(target) was not a factor, then the number itself has to be prime
  if (primeIndex >= primes.size() && target != 1) {
      PrimeFactor dummy;
      dummy.prime = target; 
      dummy.power = 1;
      factors.push_back(dummy);
  }

}
