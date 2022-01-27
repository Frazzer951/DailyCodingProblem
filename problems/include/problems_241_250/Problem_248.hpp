#ifndef PROBLEMS_241_250_PROBLEM_248_HPP
#define PROBLEMS_241_250_PROBLEM_248_HPP

#pragma once

/* HARD
Find the maximum of two numbers without using any if-else statements, branching,
or direct comparisons.
*/

int max( int a, int b ) { return ( abs( a - b ) + ( a + b ) ) / 2; }


#endif
