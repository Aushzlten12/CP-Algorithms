#include <utility>

// Complex O(n)
int fib(int n) {
  int a = 0;
  int b = 1;
  for (int i = 0; i < n; i++) {
    int tmp = a + b;
    a = b;
    b = tmp;
  }
  return a;
}

// Matrix fo}rm
struct matrix {
  long long mat[2][2];
  matrix friend operator*(const matrix &a, const matrix &b) {
    matrix c;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        c.mat[i][j] = 0;
        for (int k = 0; k < 2; k++) {
          c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
        }
      }
    }
    return c;
  }
};

matrix matpow(matrix base, long long n) {
  matrix ans{{{1, 0}, {0, 1}}};
  while (n) {
    if (n & 1) {
      ans = ans * base;
    }
    base = base * base;
    n >>= 1;
  }
  return ans;
}

long long fibMatrix(int n) {
  matrix base{{{1, 1}, {1, 0}}};
  return matpow(base, n).mat[0][1];
}

// Fast Doubling Method
std::pair<int, int> fibFD(int n) {
  if (n == 0)
    return {0, 1};
  auto p = fibFD(n >> 1);
  int c = p.first * (2 * p.second - p.first);
  int d = p.first * p.first + p.second * p.second;
  if (n & 1)
    return {d, d + c};
  else
    return {c, d};
}
