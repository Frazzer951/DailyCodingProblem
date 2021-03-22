#pragma once

#include <utility>

std::pair<int, int> cons( int a, int b );

int car( std::pair<int, int> p );

int cdr( std::pair<int, int> p );

int prob_5();