#include "Problem_131.hpp"
#include "Problem_132.hpp"
#include "Problem_133.hpp"
#include "Problem_134.hpp"
#include "Problem_135.hpp"

#include "gtest/gtest.h"


// Problem 132
TEST( Problem_132, record )
{
  hitcounter h;

  ASSERT_NO_FATAL_FAILURE( h.record( timestamp( 10, 15, 6 ) ) );
  ASSERT_NO_FATAL_FAILURE( h.record( timestamp( 12, 10, 1 ) ) );
  ASSERT_NO_FATAL_FAILURE( h.record( timestamp( 4, 2, 59 ) ) );
}

class HitCounterTest : public ::testing::Test
{
protected:
  void SetUp() override
  {
    h.record( timestamp( 1, 16, 0 ) );
    h.record( timestamp( 4, 2, 59 ) );
    h.record( timestamp( 5, 5, 15 ) );
    h.record( timestamp( 10, 15, 6 ) );
    h.record( timestamp( 12, 10, 1 ) );
    h.record( timestamp( 18, 54, 30 ) );
    h.record( timestamp( 20, 13, 2 ) );
  }

  hitcounter h;
};

TEST_F( HitCounterTest, total ) { EXPECT_EQ( h.total(), 7 ); }

TEST_F( HitCounterTest, range )
{
  auto                   timestamps = h.range( timestamp( 5, 0, 0 ), timestamp( 19, 0, 0 ) );
  std::vector<timestamp> expected   = { timestamp( 5, 5, 15 ), timestamp( 10, 15, 6 ), timestamp( 12, 10, 1 ),
                                      timestamp( 18, 54, 30 ) };

  EXPECT_EQ( timestamps, expected );
}