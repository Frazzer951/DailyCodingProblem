#ifndef PROBLEMS_231_240_PROBLEM_232_HPP
#define PROBLEMS_231_240_PROBLEM_232_HPP


#pragma once

/* EASY
Implement a PrefixMapSum class with the following methods:

 * insert(key: str, value: int): Set a given key's value in the map. If the key
   already exists, overwrite the value.
 * sum(prefix: str): Return the sum of all values of keys that begin with a
   given prefix.

For example, you should be able to run the following code:

mapsum.insert("columnar", 3)
assert mapsum.sum("col") == 3

mapsum.insert("column", 2)
assert mapsum.sum("col") == 5
*/
#include <map>
#include <string>

class PrefixMapSum
{
public:
  PrefixMapSum() = default;

  void insert( const std::string & key, int value ) { map[key] = value; }

  int sum( const std::string & prefix )
  {
    int sum = 0;
    for( auto it = map.lower_bound( prefix ); it != map.end(); it++ )
    {
      if( it->first.substr( 0, prefix.size() ) != prefix ) { break; }
      sum += it->second;
    }
    return sum;
  }

private:
  std::map<std::string, int> map;
};
#endif
