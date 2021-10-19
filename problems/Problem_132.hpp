#pragma once

/* EASY
Design and implement a HitCounter class that keeps track of requests (or hits). It should support the following
operations:

        - record(timestamp): records a hit that happened at timestamp
        - total(): returns the total number of hits recorded
        - range(lower, upper): returns the number of hits that occurred between timestamps lower and upper (inclusive)

        Follow-up: What if our system has limited memory?
*/

#include <algorithm>
#include <iostream>
#include <vector>

struct timestamp
{
  int hour;
  int minute;
  int second;

  timestamp( int h, int m, int s ) : hour( h ), minute( m ), second( s ) {}

  friend bool operator<( const timestamp & l, const timestamp & r )
  {
    if( l.hour > r.hour ) return false;
    if( l.hour == r.hour )
    {
      if( l.minute >= r.minute ) return false;
      if( l.minute == r.minute && l.second >= r.second ) return false;
    }
    return true;
  }

  friend bool operator==( const timestamp & l, const timestamp & r )
  {
    if( l.hour != r.hour ) return false;
    if( l.minute != r.minute ) return false;
    if( l.second != r.second ) return false;
    return true;
  }
  friend bool operator>( const timestamp & l, const timestamp & r )
  {
    if( l.hour <= r.hour ) return false;
    if( l.minute <= r.minute ) return false;
    if( l.second <= r.second ) return false;
    return true;
  }
};

inline std::ostream & operator<<( std::ostream & os, const timestamp & t )
{
  os << t.hour << ":" << t.minute << ":" << t.second;
  return os;
}

class hitcounter
{
  std::vector<timestamp> hits;

public:
  void record( timestamp t ) { hits.push_back( t ); }

  std::size_t total() { return hits.size(); }

  std::vector<timestamp> range( timestamp l, timestamp u )
  {
    std::sort( hits.begin(), hits.end() );
    std::vector<timestamp> timestamps;
    auto                   lower = hits.begin();
    auto                   upper = hits.end();
    upper--;

    while( *lower < l ) { lower++; }
    while( *upper > u ) { upper--; }

    for( auto i = lower; i != upper && i != hits.end(); i++ ) { timestamps.push_back( *i ); }

    timestamps.push_back( *upper );

    return timestamps;
  }
};