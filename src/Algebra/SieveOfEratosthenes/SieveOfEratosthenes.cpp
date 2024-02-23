#include <algorithm>
#include <cmath>
#include <vector>
// NOTE: Algorithm to find prime number
std::vector<bool> sieveEratosthenes(int n) {
  std::vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  return is_prime;
}

// Optimization Algorithm
// COMPLETE: Sieving till root

std::vector<bool> sieveEratosthenesRoot(int n) {
  std::vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;
    }
  }
  return is_prime;
}

// COMPLETE: Segmented Sieve
int count_primes(int n) {
  const int S = 10000;

  std::vector<int> primes;
  int nsqrt = sqrt(n);
  std::vector<char> is_prime(nsqrt + 2, true);
  for (int i = 2; i <= nsqrt; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= nsqrt; j += i) {
        is_prime[j] = false;
      }
    }
  }

  int result = 0;
  std::vector<char> block(S);
  for (int k = 0; k * S <= n; k++) {
    fill(block.begin(), block.end(), true);
    int start = k * S;
    for (int p : primes) {
      int start_idx = (start + p - 1) / p;
      int j = std::max(start_idx, p) * p - start;
      for (; j < S; j += p)
        block[j] = false;
    }
    if (k == 0)
      block[0] = block[1] = false;
    for (int i = 0; i < S && start + i <= n; i++) {
      if (block[i])
        result++;
    }
  }
  return result;
}

// COMPLETE: Find primes in range
std::vector<char> segmentedSieve(long long L, long long R) {
  // IMPORTANT: generate all primes up to sqrt(R)
  // NOTE: as count primes algorithm
  long long lim = sqrt(R);
  std::vector<char> mark(lim + 1, false);
  std::vector<long long> primes;
  for (long long i = 2; i <= lim; ++i) {
    if (!mark[i]) {
      primes.emplace_back(i);
      for (long long j = i * i; j <= lim; j += i)
        mark[j] = true;
    }
  }

  std::vector<char> isPrime(R - L + 1, true);
  for (long long i : primes) {
    for (long long j = std::max(i * i, (L + i - 1) / i * i); j <= R; j += i)
      isPrime[j - L] = false;
  }
  if (L == 1)
    isPrime[0] = false;
  return isPrime;
}

// COMPLETE: SegmentedSieve withou PreGen
std::vector<char> segmentedSieveNoPreGen(long long L, long long R) {
  std::vector<char> isPrime(R - L + 1, true);
  long long lim = sqrt(R);
  for (long long i = 2; i <= lim; ++i)
    for (long long j = std::max(i * i, (L + i - 1) / i * i); j <= R; j += i)
      isPrime[j - L] = false;
  if (L == 1)
    isPrime[0] = false;
  return isPrime;
}

// IMPORTANT: Linear Sieve

std::vector<int> lowerPrimeForEachNumber() {
  const int N = 10000000;
  std::vector<int> lp(N + 1);
  std::vector<int> pr;

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
  return lp;
}

// PENDING: Solve an BAZINGA exercise
