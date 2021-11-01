#pragma once

/* EASY
Given an even number (greater than 2), return two prime numbers whose sum will
be equal to the given number.

A solution will always exist. See Goldbach�s conjecture
[https://en.wikipedia.org/wiki/Goldbach%27s_conjecture].

Example:

Input: 4
Output: 2 + 2 = 4


If there are more than one solution possible, return the lexicographically
smaller solution.

If [a, b] is one solution with a <= b, and [c, d] is another solution with c <=
d, then

[a, b] < [c, d]


If a < c OR a==c AND b < d.
*/

#include <vector>

inline std::vector<int> SieveOfEratosthenes( int n )
{
  std::vector<bool> prime( n + 1, true );

  for( int p = 2; p * p <= n; p++ )
  {
    if( prime[p] )
    {
      for( int i = p * p; i <= n; i += p ) prime[i] = false;
    }
  }

  std::vector<int> primes;
  // Print all prime numbers
  for( int p = 2; p <= n; p++ )
    if( prime[p] ) primes.push_back( p );

  return primes;
}

inline std::pair<int, int> primeSum( int n )
{
  auto primes = SieveOfEratosthenes( n / 2 );

  for( int i = 0; i < primes.size(); i++ )
  {
    for( int j = i; j < primes.size(); j++ )
    {
      if( primes[i] + primes[j] == n ) return std::make_pair( primes[i], primes[j] );
    }
  }
  return std::make_pair( -1, -1 );
}
