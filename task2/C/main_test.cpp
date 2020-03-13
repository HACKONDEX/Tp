#include "gtest/gtest.h"
#include <iostream>

TEST(CTest1, DemnostrateGTestMacros){
    EXPECT_TRUE(true);
}

TEST(CTest2, DemnostrateGTestMacros2){
    EXPECT_EQ(true, true);
}
