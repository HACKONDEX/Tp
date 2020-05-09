//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"

int AddTestCase::my_addition( int x, int y )
{
    return x + y;
}

TEST(AddTestCase, random_1)
{
    int x = 123;
    int y = 666;
    EXPECT_EQ( AddTestCase::my_addition( x, y ), Add( x, y ) );
}

TEST(AddTestCase, random_2)
{
    int x = -143;
    int y = 123;
    EXPECT_EQ( AddTestCase::my_addition( x, y ), Add( x, y ) );
}

TEST(AddTestCase, random_3)
{
    int x = 115;
    int y = -6;
    EXPECT_EQ( AddTestCase::my_addition( x, y ), Add( x, y ) );
}

TEST(AddTestCase, random_4)
{
    int x = 143;
    int y = 143;
    EXPECT_EQ( AddTestCase::my_addition( x, y ), Add( x, y ) );
}

TEST(AddTestCase, zero_zero)
{
    int x = 0, y = 0;
    EXPECT_EQ( AddTestCase::my_addition( x, y ), Add( x, y ) );
}

TEST(AddTestCase, hand_test_1)
{
    int x = 0, y = 1;
    EXPECT_EQ( AddTestCase::my_addition( x, y ), Add( x, y ) );
}

TEST(AddTestCase, hand_test_2)
{
    int x = 1, y = 0;
    EXPECT_EQ( AddTestCase::my_addition( x, y ), Add( x, y ) );
}

TEST(AddTestCase, hand_test_3)
{
    int x = -5, y = 6;
    EXPECT_EQ( AddTestCase::my_addition( x, y ), Add( x, y ) );
}

TEST(AddTestCase, hand_test_4)
{
    int x = 6, y = -5;
    EXPECT_EQ( AddTestCase::my_addition( x, y ), Add( x, y ) );
}

TEST(AddTestCase, hand_test_5)
{
    int x = 1, y = 1;
    EXPECT_EQ( AddTestCase::my_addition( x, x ), Add( y, y ) );
}

TEST(AddTestCase, hand_test_6)
{
    int x = 13, y = 6;
    EXPECT_EQ( AddTestCase::my_addition( x, y ), Add( x, y ) );
}

TEST(AddTestCase, reversed)
{
    int x = 5, y = 0;
    EXPECT_EQ( Add(y, x), Add( x, y ) );
}

TEST(AddTestCase, hand_test_7)
{
    int x = 13, y = 6;
    EXPECT_EQ( AddTestCase::my_addition( x, y ), Add( x, y ) );
}

TEST(AddTestCase, hand_test_8)
{
    int x = 0, y = 0;
    EXPECT_EQ( AddTestCase::my_addition( x, y ), Add( x, y ) );
}

TEST(AddTestCase, hand_test_9)
{
    int x = -13, y = 6;
    EXPECT_EQ( AddTestCase::my_addition( x, y ), Add( x, y ) );
}

TEST(AddTestCase, hand_test_10)
{
    int x = 13, y = -6;
    EXPECT_EQ( AddTestCase::my_addition( x, y ), Add( x, y ) );
}

TEST(AddTestCase, hand_test_11)
{
    int x = -13, y = -6;
    EXPECT_EQ( AddTestCase::my_addition( x, y ), Add( x, y ) );
}

TEST(AddTestCase, hand_test_12)
{
    int x = 41, y = 29;
    EXPECT_EQ( AddTestCase::my_addition( x, y ), Add( x, y ) );
}

TEST(AddTestCase, hand_test_13)
{
    int x = 0, y = 6;
    EXPECT_EQ( AddTestCase::my_addition( x, y ), Add( x, y ) );
}

TEST(AddTestCase, hand_test_14)
{
    int x = -6, y = 0;
    EXPECT_EQ( AddTestCase::my_addition( x, y ), Add( x, y ) );
}

TEST(AddTestCase, hand_test_15)
{
    int x = 13, y = 0;
    EXPECT_EQ( AddTestCase::my_addition( x, y ), Add( x, y ) );
}