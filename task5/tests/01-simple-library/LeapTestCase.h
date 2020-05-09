//
// Created by akhtyamovpavel on 5/1/20.
//


#pragma once

#include <gtest/gtest.h>

class LeapTestCase : public ::testing::Test 
{
public:
    static bool my_leap( int year );
};


