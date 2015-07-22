#include <gtest/gtest.h>

#include "sample.h"

TEST(square, seven) {
  EXPECT_EQ(49, square(7));
}

TEST(factorial, ten) {
  EXPECT_EQ(3628800, factorial(10));
}
