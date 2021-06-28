#pragma once

/* EASY
Given a function f, and N return a
debounced f of N milliseconds.

That is, as long as the debounced f
continues to be invoked, f itself
will not be called for N milliseconds.
*/


#ifdef _WIN32
#  include <Windows.h>
#else
#  include <unistd.h>
#endif

#include <functional>

inline auto debunce( int f(), int n )
{
#ifdef _WIN32
  auto func = [f, n]() -> int
  {
    Sleep( n );
    return f();
  };
#else
  auto func = [f, n]()
  {
    usleep( n * 1000 );    // takes microseconds
    return f();
  };
#endif

  return std::function( func );
}