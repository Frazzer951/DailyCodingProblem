#ifndef PROBLEMS_041_050_PROBLEM_041_HPP
#define PROBLEMS_041_050_PROBLEM_041_HPP

#pragma once

/* MEDIUM
Given an unordered list of flights taken by someone, each represented as
(origin, destination) pairs, and a starting airport, compute the person's
itinerary. If no such itinerary exists, return null. If there are multiple
possible itineraries, return the lexicographically smallest one. All flights
must be used in the itinerary.

For example, given the list of flights [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL',
'YYZ'), ('HKO', 'ORD')] and starting airport 'YUL', you should return the list
['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].

Given the list of flights [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport
'COM', you should return null.

Given the list of flights [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')] and
starting airport 'A', you should return the list ['A', 'B', 'C', 'A', 'C'] even
though ['A', 'C', 'A', 'B', 'C'] is also a valid itinerary. However, the first
one is lexicographically smaller.
*/
#include <string>
#include <vector>

inline std::pair<std::string, std::string> getAirportPair( const std::vector<std::pair<std::string, std::string>> &v,
                                                           const std::string                                      &first ) {
  for ( std::pair<std::string, std::string> flight : v ) {
    if ( flight.first == first ) return flight;
  }
  return {};
}

inline int getPairIndex( std::vector<std::pair<std::string, std::string>> v, const std::pair<std::string, std::string> &p ) {
  for ( int i = 0; i < v.size(); i++ ) {
    if ( v[i] == p ) return i;
  }
  return -1;
}

inline std::vector<std::string> getItinerary( std::vector<std::pair<std::string, std::string>> v, const std::string &start ) {
  std::vector<std::string> itinerary = { start };
  std::string              next      = start;

  while ( !v.empty() ) {
    auto flight = getAirportPair( v, next );
    if ( flight.first.empty() && flight.second.empty() ) return {};
    v.erase( v.begin() + getPairIndex( v, flight ) );
    next = flight.second;
    itinerary.push_back( next );
  }

  return itinerary;
}
#endif
