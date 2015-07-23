#include "sample.h"

#include <gtest/gtest.h>

TEST(square, seven) {
  EXPECT_EQ(49, square(7));
}

TEST(factorial, ten) {
  EXPECT_EQ(3628800, factorial(10));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
