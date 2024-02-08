#include <vector>
long long binpow(long long a, long long b) {
  if (b == 0) {
    return 1;
  }
  long long res = binpow(a, b / 2);
  if (b % 2 == 1) {
    return res * res * a;
  } else {
    return res * res;
  }
}

long long binpowSecond(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

long long binpowModule(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

// Permutations

std::vector<int> applyPermutation(std::vector<int> sequence,
                                  std::vector<int> permutation) {
  std::vector<int> newSequence(sequence.size());
  for (int i = 0; i < sequence.size(); i++) {
    newSequence[i] = sequence[permutation[i]];
  }
  return newSequence;
}

std::vector<int> permute(std::vector<int> sequence,
                         std::vector<int> permutation, long long k) {
  while (k > 0) {
    if (k & 1) {
      sequence = applyPermutation(sequence, permutation);
    }
    permutation = applyPermutation(permutation, permutation);
    k >>= 1;
  }
  return sequence;
}
