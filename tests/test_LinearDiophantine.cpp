#include "../src/Algebra/LinearDiophantine/LinearDiophantine.cpp"
#include <gtest/gtest.h>

TEST(LinearDiophantineFindAnySolution, BasicTest) {
  int x, y, g;
  // c ≡ 0 (mod gcd(a,b))
  EXPECT_EQ(find_any_solution(2, 4, 5, x, y, g), false);
  EXPECT_EQ(find_any_solution(2, 7, 8, x, y, g), true);
  // std::cout << x << std::endl;
  // std::cout << y << std::endl;
  // std::cout << g << std::endl;
}

int mainLD(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
