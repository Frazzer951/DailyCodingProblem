#pragma once

/* EASY
You run an e-commerce website and want to record the last N order ids in a log. Implement a data structure to accomplish this, with the following API:

record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.
You should be as efficient with time and space as possible.
*/

#include <iostream>
#include <vector>

class Store
{
public:
  std::vector<long int> log;

  void record( long int order_id )
  {
    log.push_back( order_id );
  }

  long int get_last( int i )
  {
    return log[log.size() - i];
  }
};

int prob_16()
{
  std::cout << "\nProblem 16\n";

  Store store;

  store.record( 11234 );
  store.record( 11235 );
  store.record( 11236 );
  store.record( 11237 );

  std::cout << "The most recent order_id is " << store.get_last( 1 ) << "\n";
  std::cout << "The second most recent order_id is " << store.get_last( 2 ) << "\n";
  std::cout << "The third most recent order_id is " << store.get_last( 3 ) << "\n";
  std::cout << "The fourth most recent order_id is " << store.get_last( 4 ) << "\n";

  return 0;
}