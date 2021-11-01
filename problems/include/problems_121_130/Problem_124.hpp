#ifndef PROBLEMS_121_130_PROBLEM_124_HPP
#define PROBLEMS_121_130_PROBLEM_124_HPP

#pragma once

/* EASY
You have n fair coins and you flip them all at the same time. Any that come up
tails you set aside. The ones that come up heads you flip again. How many rounds
do you expect to play before only one coin remains?

Write a function that, given n, returns the number of rounds you'd expect to
play until one coin remains.
*/

#include <cmath>

inline double expected_tosses( int n ) { return std::log2( n ); }
#endif
