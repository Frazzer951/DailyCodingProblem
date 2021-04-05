#include "Problem_1.h"
#include "Problem_10.h"
#include "Problem_11.h"
#include "Problem_12.h"
#include "Problem_13.h"
#include "Problem_14.h"
#include "Problem_15.h"
#include "Problem_16.h"
#include "Problem_17.h"
#include "Problem_18.h"
#include "Problem_2.h"
#include "Problem_3.h"
#include "Problem_4.h"
#include "Problem_5.h"
#include "Problem_6.h"
#include "Problem_7.h"
#include "Problem_8.h"
#include "Problem_9.h"

#include "gtest/gtest.h"


TEST( Problem_1, Given_Case )
{
  EXPECT_TRUE( arrayAddToNum( { 10, 15, 3, 7 }, 17 ) );
}

TEST( Problem_1, Custom_Case )
{
  EXPECT_FALSE( arrayAddToNum( { 1, 5, 7, 9 }, 11 ) );
}


//int main()
//{
//  prob_1();
//  prob_2();
//  prob_3();
//  prob_4();
//  prob_5();
//  prob_6();
//  prob_7();
//  prob_8();
//  prob_9();
//  prob_10();
//  prob_11();
//  prob_12();
//  prob_13();
//  prob_14();
//  prob_15();
//  prob_16();
//  prob_17();
//  prob_18();
//
//  return 0;
//}