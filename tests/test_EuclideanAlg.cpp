#include "../src/Algebra/EuclideanAlgorithm/EuclideanAlg.cpp"
#include <gtest/gtest.h>
#include <iostream>
#include <ostream>

TEST(EuclideanAlgorithmTest, BasicTest) {
  EXPECT_EQ(gcd(12, 2), 2);

  EXPECT_EQ(gcd(819, 714), 21);

  EXPECT_EQ(gcd(0, 12), 12);

  EXPECT_EQ(gcd(14132, 0), 14132);

  EXPECT_EQ(gcd(12345, 6789), 3);

  EXPECT_EQ(gcd(3, 5), 1);
}

TEST(EuclideanAlgorithmLCM, BasicTest) {
  EXPECT_EQ(lcm(4, 6), 12);
  EXPECT_EQ(lcm(36, 48), 144);
  EXPECT_EQ(lcm(75, 90), 450);
}

TEST(EuclideanAlgorithmGCDBinary, BasicTest) {
  EXPECT_EQ(gcdBinary(12, 2), 2);

  EXPECT_EQ(gcdBinary(819, 714), 21);

  EXPECT_EQ(gcdBinary(0, 12), 12);

  EXPECT_EQ(gcdBinary(14132, 0), 14132);

  EXPECT_EQ(gcdBinary(12345, 6789), 3);

  EXPECT_EQ(gcdBinary(3, 5), 1);
}

TEST(ExtendEuclideanAlgorithm, BasicTest) {
  int x, y;

  int result1 = Egcd(4, 6, x, y);
  EXPECT_EQ(result1, 2);
  std::cout << x << std::endl;
  std::cout << y << std::endl;
}

int mainEA(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
