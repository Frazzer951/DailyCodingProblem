#ifndef PROBLEMS_171_180_PROBLEM_175_HPP
#define PROBLEMS_171_180_PROBLEM_175_HPP

#pragma once

/* EASY
You are given a starting state start, a list of transition probabilities for a
Markov chain, and a number of steps num_steps. Run the Markov chain starting
from start for num_steps and compute the number of times we visited each state.

For example, given the starting state a, number of steps 5000, and the following
transition probabilities:

[
  ('a', 'a', 0.9),
  ('a', 'b', 0.075),
  ('a', 'c', 0.025),
  ('b', 'a', 0.15),
  ('b', 'b', 0.8),
  ('b', 'c', 0.05),
  ('c', 'a', 0.25),
  ('c', 'b', 0.25),
  ('c', 'c', 0.5)
]


One instance of running this Markov chain might produce { 'a': 3012, 'b': 1656,
'c': 332 }.
*/
#include <ctime>
#include <map>
#include <random>
#include <vector>

struct transition {
  char   from;
  char   to;
  double prob;
};

inline char getCharFromProb( double prob, std::map<char, double> probs ) {
  auto   it  = probs.begin();
  double val = 0;

  while ( it != probs.end() ) {
    val += it->second;
    if ( prob <= val ) return it->first;
    it++;
  }
  return probs.begin()->first;
}

inline std::map<char, int> markovChain( char startState, int steps, const std::vector<transition> &transitions ) {
  srand( (unsigned int) time( nullptr ) );

  std::map<char, int>                    count;
  std::map<char, std::map<char, double>> probs;

  for ( transition const t : transitions ) { probs[t.from][t.to] = t.prob; }

  char state = startState;

  for ( int i = 0; i < steps; i++ ) {
    double const prob = ( rand() & 1000 ) / 1000.0;
    state       = getCharFromProb( prob, probs[state] );
    count[state]++;
  }
  return count;
}
#endif
