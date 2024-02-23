#include "../src/Algebra/SieveOfEratosthenes/SieveOfEratosthenes.cpp"
#include <gtest/gtest.h>
#include <vector>

TEST(SieveOfEratosthenes, MarkPrimeNumbers) {
  std::vector<bool> is_prime = sieveEratosthenes(16);
  std::vector<bool> expectPrimes = {false, false, true,  true,  false, true,
                                    false, true,  false, false, false, true,
                                    false, true,  false, false, false};
  EXPECT_EQ(is_prime, expectPrimes);
}

int mainSOE(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
