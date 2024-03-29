#ifndef PROBLEMS_241_250_PROBLEM_244_HPP
#define PROBLEMS_241_250_PROBLEM_244_HPP

#pragma once

/* EASY
The Sieve of Eratosthenes is an algorithm used to generate all prime numbers
smaller than N. The method is to take increasingly larger prime numbers, and
mark their multiples as composite.

For example, to find all primes less than 100, we would first mark [4, 6, 8,
...] (multiples of two), then [6, 9, 12, ...] (multiples of three), and so on.
Once we have done this for all primes less than N, the unmarked numbers that
remain will be prime.

Implement this algorithm.

Bonus: Create a generator that produces primes indefinitely (that is, without
taking N as an input).
*/
#include <vector>

inline std::vector<int> sieveOfEratosthenes( int n ) {
  std::vector<int>  primes;
  std::vector<bool> isPrime( n + 1, true );

  for ( int i = 2; i <= n; ++i ) {
    if ( isPrime[i] ) {
      primes.push_back( i );
      for ( int j = i * i; j <= n; j += i ) { isPrime[j] = false; }
    }
  }

  return primes;
}
#endif
