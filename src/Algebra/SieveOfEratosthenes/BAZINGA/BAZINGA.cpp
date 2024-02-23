#include <fstream>
#include <iostream>
#include <ostream>
#include <vector>
std::vector<int> LinearSieve() {
  const int N = 10600000;
  std::vector<int> lp(N + 1);
  std::vector<int> pr;
  std::vector<int> mt;
  for (int i = 2; i <= N; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; i * pr[j] <= N; ++j) {
      lp[i * pr[j]] = pr[j];
      if (pr[j] == lp[i]) {
        break;
      }
    }
  }

  for (int i = 2; i <= N; i++) {
    for (int prime : pr) {
      if (prime > i)
        break;
      int q = i % prime == 0 ? i / prime : 1;
      if (lp[q] == q && q != prime) {
        mt.push_back(i);
        break;
      }
    }
  }

  return mt;
}

int main(int argc, char *argv[]) {
  // Find the number that result from multiplying two different primes
  std::vector<int> multTwoPrimes = LinearSieve();

  // READ input
  std::ifstream file("./../inputBAZINGA.txt");
  if (!file) {
    std::cerr << "Can't open the file" << std::endl;
    return 1;
  }

  int T;
  file >> T;

  std::vector<int> outputs;

  for (int t = 0; t < T; t++) {
    int position;
    file >> position;
    outputs.push_back(multTwoPrimes[position - 1]);
  }

  file.close();

  for (int &output : outputs) {
    std::cout << output << std::endl;
  }

  return 0;
}
