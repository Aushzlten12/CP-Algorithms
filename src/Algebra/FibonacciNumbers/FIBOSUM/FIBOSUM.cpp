
#include <fstream>
#include <iostream>
#include <vector>

std::pair<int, int> fib(int n) {
  if (n == 0)
    return {0, 1};
  auto p = fib(n >> 1);
  int c = p.first * (2 * p.second - p.first);
  int d = p.first * p.first + p.second * p.second;
  if (n & 1)
    return {d, d + c};
  else
    return {c, d};
}

long long fiboSum(int a, int b) {
  std::pair<int, int> firstPair = fib(a);
  long long sum = firstPair.first + firstPair.second;
  for (int i = 1; i < (b - a); i++) {
    long long additionalNumber = firstPair.first + firstPair.second;
    sum = sum + additionalNumber;
    firstPair.first = firstPair.second;
    firstPair.second = additionalNumber;
  }
  return sum;
}

int main() {
  std::ifstream file("./../inputFIBOSUM.txt");
  if (!file) {
    std::cerr << "Can't open the file" << std::endl;
    return 1;
  }

  int T;
  file >> T;

  std::vector<long long> outputs;

  for (int t = 0; t < T; ++t) {
    int N, M;
    file >> N >> M;
    outputs.push_back(fiboSum(N, M));
  }

  file.close();

  for (const auto &output : outputs) {
    std::cout << output << std::endl;
  }

  return 0;
}
