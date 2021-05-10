#pragma once

/* MEDIUM
cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair.
For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

Given this implementation of cons:

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair
Implement car and cdr.
*/

#include <iostream>
#include <utility>

std::pair<int, int> cons( int a, int b ) { return std::make_pair( a, b ); }

int car( std::pair<int, int> p ) { return p.first; }

int cdr( std::pair<int, int> p ) { return p.second; }

int prob_5()
{
  std::cout << "\nProblem 5:\n";

  std::cout << "car(cons(3,4)) returns " << car( cons( 3, 4 ) ) << '\n';
  std::cout << "cdr(cons(3,4)) returns " << cdr( cons( 3, 4 ) ) << '\n';

  return 0;
}