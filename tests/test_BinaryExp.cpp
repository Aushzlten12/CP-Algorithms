#include "../src/Algebra/BinaryExponentiation/BinaryExp.cpp"
#include <gtest/gtest.h>

TEST(BinaryExpTest, BasicTest) {
  EXPECT_EQ(binpow(2, 0), 1);

  EXPECT_EQ(binpow(2, 1), 2);

  EXPECT_EQ(binpow(3, 13), 1594323);
}

TEST(BinaryExpWithoutRecursion, BasicTest) {
  EXPECT_EQ(binpowSecond(2, 0), 1);

  EXPECT_EQ(binpowSecond(3, 13), 1594323);
}

TEST(BinaryExpModule, BasicTest) {
  EXPECT_EQ(binpowModule(3, 3, 2), 1);
  EXPECT_EQ(binpowModule(3, 13, 15), 3);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
