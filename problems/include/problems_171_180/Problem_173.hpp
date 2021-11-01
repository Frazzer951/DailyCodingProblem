#ifndef PROBLEMS_171_180_PROBLEM_173_HPP
#define PROBLEMS_171_180_PROBLEM_173_HPP

#pragma once

/* EASY
Write a function to flatten a nested dictionary. Namespace the keys with a
period.

For example, given the following dictionary:

{
    "key": 3,
    "foo": {
        "a": 5,
        "bar": {
            "baz": 8
        }
    }
}


it should become:

{
    "key": 3,
    "foo.a": 5,
    "foo.bar.baz": 8
}


You can assume keys do not contain dots in them, i.e. no clobbering will occur.
*/

#include <any>
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>

using anymap = std::map<std::string, std::any>;

inline std::map<std::string, int> flatten( const anymap & d, char separator = '.' )
{
  std::map<std::string, int> new_dict;

  for( const auto & [key, value] : d )
  {
    if( value.type().name() == typeid( int ).name() ) { new_dict[key] = std::any_cast<int>( value ); }
    else
    {
      std::map<std::string, int> flattened_subdict = flatten( std::any_cast<anymap>( value ) );
      for( auto & [flatkey, flatvalue] : flattened_subdict ) new_dict[key + separator + flatkey] = flatvalue;
    }
  }

  return new_dict;
}
#endif
