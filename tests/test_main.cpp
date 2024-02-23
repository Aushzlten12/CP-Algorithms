#include "test_BinaryExp.cpp"
#include "test_EuclideanAlg.cpp"
#include "test_FibonacciNumbers.cpp"
#include "test_LinearDiophantine.cpp"
#include "test_SieveOfEratosthenes.cpp"

int main(int argc, char *argv[]) {
  mainBE(argc, argv);
  mainEA(argc, argv);
  mainLD(argc, argv);
  mainSOE(argc, argv);
  return 0;
}
