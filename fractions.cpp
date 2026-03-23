#include <iostream>
#include <cmath>
#include "fractions.hpp"
#include <algorithm>

Fraction::Fraction(std::string num) {
  // Load numbers until decimal dot
  long number = 0;
  int power = 0;
  
  int n = num.size();
  int i = 0;
  while (i < n && num[i] != '.') {
    number *= 10;
    // getDigit by substracting 48 (ASCII valueo of 0) from the char value of char number
    number += getDigit(num[i]);
    i++;
  }
  // Skipping decimal dot
  i++;

  // Load numbers after dot, with each number increase power by 1
  while (i < n) {
    number *= 10;
    number += getDigit(num[i]);
    power++;
    i++;
  }
  
  this->numerator = number;
  this->power = power;
  this->denominator = std::pow(10, power);
  this->simplify();
}


void Fraction::simplify() {
  // Getting prime factors of numerator and denominator
  std::vector<PrimeFactor> numi;
  std::vector<PrimeFactor> denomi;
  
  if (this->numerator < 0)
    factorise(numi, -this->numerator);
  else
    factorise(numi, this->numerator);
  
  if (this->denominator < 0)
    factorise(denomi, -this->denominator);
  else
    factorise(denomi, this->denominator);
  // Either top or bottom have to be negative for fraction to be negative, if they are the same sign, fraction will be positive
  bool negative = (this->numerator < 0) ^ (this->denominator < 0);

  // Checking for common factors
  for (int i = 0; i < numi.size(); ++i) {
    auto it = std::find_if(denomi.begin(), denomi.end(), [&numi, &i](PrimeFactor p){
       return numi[i].prime == p.prime;
       });

    // Skipping if this prime is not common for both top and botton of fraction
    if (it == denomi.end())
      continue;
   
    int lowest = std::min(it->power, numi[i].power);
    // Substracting the highest power of prime from both top and bottom
    numi[i].power -= lowest;
    it->power -= lowest;
  }

  // Reconstructiong simplified numerator and denominator
  long newNumerator = 1;
  long newDenominator = 1;
  if (negative)
    newNumerator = -1;

  for (int i = 0; i < numi.size(); ++i)
    newNumerator *= std::pow(numi[i].prime, numi[i].power);

  for (int i = 0; i < denomi.size(); ++i)
    newDenominator *= std::pow(denomi[i].prime, denomi[i].power);

  this->numerator = newNumerator;
  this->denominator = newDenominator;
}

Fraction Fraction::operator+ (const Fraction& other){
  // TODO make this more effiecent by multipling only to get denominators to LCM
  Fraction newFrac("1");
  long newNumerator = 0;
  long newDenominator = 1;
  if (this->denominator != other.denominator) { // If denominators are different, performing cross multiplication
    newNumerator += this->numerator * other.denominator;
    newNumerator += other.numerator * this->denominator;
    newDenominator = this->denominator * other.denominator;
  } else { // If denominators are same, just summing up numerators
    newNumerator = this->numerator + other.numerator;
    newDenominator = this->denominator;
  }
  newFrac.numerator = newNumerator;
  newFrac.denominator = newDenominator;
  newFrac.simplify();
  return newFrac;
}

// Adding negative value of other fraction
Fraction Fraction::operator- (const Fraction& other) {
  return *this + (-other);
}

// Unary operator
Fraction Fraction::operator- () const {
  Fraction temp = *this;
  temp.numerator = -temp.numerator;
  return temp;
}

// Multiplies both numerators and denominators together and then simplifies resultant fraction
Fraction Fraction::operator* (const Fraction& other) {
  Fraction newFrac = *this;
  newFrac.numerator *= other.numerator;
  newFrac.denominator *= other.denominator;
  
  newFrac.simplify();
  return newFrac;
}
// Flipping other fraction and multipling them together
Fraction Fraction::operator/ (const Fraction& other) {
  Fraction temp = other;
  temp.numerator = other.denominator;
  temp.denominator = other.numerator;
  return *this * temp;
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
/* Populates @factors with prime factors of @target */
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


int getDigit(char num) {
  // ASCII number of 0 is 48
  return (int)num - 48;
}
