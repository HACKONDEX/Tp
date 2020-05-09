//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>

bool LeapTestCase::my_leap( int year )
{
    return IsLeap( year );
}

TEST( LeapTestCase, test_1 )
{
    EXPECT_TRUE( LeapTestCase::my_leap( 2004 ) );
}

TEST( LeapTestCase, test_2 )
{
    EXPECT_TRUE( LeapTestCase::my_leap( 2000 ) );
}

TEST( LeapTestCase, test_3 )
{
    EXPECT_TRUE( LeapTestCase::my_leap( 2008 ) );
}

TEST( LeapTestCase, test_4 )
{
    EXPECT_TRUE( LeapTestCase::my_leap( 20012 ) );
}

TEST( LeapTestCase, test_5 )
{
    EXPECT_TRUE( LeapTestCase::my_leap( 6000 ) );
}

TEST( LeapTestCase, test_6 )
{
    EXPECT_TRUE( LeapTestCase::my_leap( 2020 ) );
}

TEST( LeapTestCase, test_7 )
{
    EXPECT_TRUE( LeapTestCase::my_leap( 400 ) );
}

TEST( LeapTestCase, test_8 )
{
    EXPECT_TRUE( LeapTestCase::my_leap( 1600 ) );
}

TEST( LeapTestCase, test_9 )
{
    EXPECT_TRUE( LeapTestCase::my_leap( 1024 ) );
}

TEST( LeapTestCase, test_10 )
{
    EXPECT_TRUE( LeapTestCase::my_leap( 256 ) );
}

TEST( LeapTestCase, test_11 )
{
    EXPECT_FALSE( LeapTestCase::my_leap( 1 ) );
}

TEST( LeapTestCase, test_12 )
{
    EXPECT_FALSE( LeapTestCase::my_leap( 2001 ) );
}

TEST( LeapTestCase, test_13 )
{
    EXPECT_FALSE( LeapTestCase::my_leap( 2015 ) );
}

TEST( LeapTestCase, test_14 )
{
    EXPECT_FALSE( LeapTestCase::my_leap( 2011 ) );
}

TEST( LeapTestCase, test_15 )
{
    EXPECT_FALSE( LeapTestCase::my_leap( 2019 ) );
}

TEST( LeapTestCase, test_16 )
{
    EXPECT_FALSE( LeapTestCase::my_leap( 100 ) );
}

TEST( LeapTestCase, throw_test_1 )
{
    EXPECT_THROW( LeapTestCase::my_leap( -100 ), std::invalid_argument );
}

TEST( LeapTestCase, throw_test_2 )
{
    EXPECT_THROW( LeapTestCase::my_leap( -1 ), std::invalid_argument );
}

TEST( LeapTestCase, throw_test_3 )
{
    EXPECT_THROW( LeapTestCase::my_leap( -9 ), std::invalid_argument );
}

TEST( LeapTestCase, throw_test_4 )
{
    EXPECT_THROW( LeapTestCase::my_leap( -13 ), std::invalid_argument );
}

TEST( LeapTestCase, throw_test_5 )
{
    EXPECT_THROW( LeapTestCase::my_leap( -4 ), std::invalid_argument );
}

TEST( LeapTestCase, throw_test_6 )
{
    EXPECT_THROW( LeapTestCase::my_leap( 0 ), std::invalid_argument );
}
