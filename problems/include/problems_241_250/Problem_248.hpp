#ifndef PROBLEMS_241_250_PROBLEM_248_HPP
#define PROBLEMS_241_250_PROBLEM_248_HPP

#pragma once

/* HARD
Find the maximum of two numbers without using any if-else statements, branching,
or direct comparisons.
*/
inline int max( int x1, int x2 ) { return ( abs( x1 - x2 ) + ( x1 + x2 ) ) / 2; }
#endif
