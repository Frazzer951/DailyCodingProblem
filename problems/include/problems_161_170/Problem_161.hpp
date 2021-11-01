#ifndef PROBLEMS_161_170_PROBLEM_161_HPP
#define PROBLEMS_161_170_PROBLEM_161_HPP

#pragma once

/* EASY
Given a 32-bit integer, return the number with its bits reversed.

For example, given the binary number 1111 0000 1111 0000 1111 0000 1111 0000,
return 0000 1111 0000 1111 0000 1111 0000 1111.
*/

inline long int reverse( long int x ) { return x ^ 0xFFFFFFFF; }
#endif
