#include "../src/Algebra/FibonacciNumbers/FibonacciNumbers.cpp"
#include <gtest/gtest.h>
#include <utility>

TEST(FibonacciNumber, LinearComplex) {
  EXPECT_EQ(fib(0), 0);
  EXPECT_EQ(fib(8), 21);
  EXPECT_EQ(fib(20), 6765);
  EXPECT_EQ(fib(30), 832040);
  EXPECT_EQ(fib(40), 102334155);
}

TEST(FibonacciNumber, Matrix) {
  EXPECT_EQ(fibMatrix(0), 0);
  EXPECT_EQ(fibMatrix(8), 21);
  EXPECT_EQ(fibMatrix(20), 6765);
  EXPECT_EQ(fibMatrix(30), 832040);
  EXPECT_EQ(fibMatrix(40), 102334155);
}

TEST(FibonacciNumber, FastDoubling) {
  EXPECT_EQ(fibFD(0), std::make_pair(0, 1));
  EXPECT_EQ(fibFD(8), std::make_pair(21, 34));
  EXPECT_EQ(fibFD(20), std::make_pair(6765, 10946));
  EXPECT_EQ(fibFD(30), std::make_pair(832040, 1346269));
  EXPECT_EQ(fibFD(40), std::make_pair(102334155, 165580141));
}

int mainFN(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
