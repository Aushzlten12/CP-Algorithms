#include <tuple>
#include <utility>
// Greatest common divisor
int gcd(int a, int b) {
  while (b) {
    a %= b;
    std::swap(a, b);
  }
  return a;
}

// Least common multiple
int lcm(int a, int b) { return a / gcd(a, b) * b; }

// Binary GCD
int gcdBinary(int a, int b) {
  if (!a || !b) {
    return a | b;
  }
  unsigned shift = __builtin_ctz(a | b);
  a >>= __builtin_ctz(a);
  do {
    b >>= __builtin_ctz(b);
    if (a > b)
      std::swap(a, b);
    b -= a;
  } while (b);
  return a << shift;
}

// Extended Euclidean Algorithm
int Egcd(int a, int b, int &x, int &y) {
  // Recursive
  // if (b == 0) {
  //   x = 1;
  //   y = 0;
  //   return a;
  // }
  // int x1, y1;
  // int d = Egcd(b, a % b, x1, y1);
  // x = y1;
  // y = x1 - y1 * (a / b);
  // return d;
  x = 1, y = 0;
  int x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    int q = a1 / b1;
    std::tie(x, x1) = std::make_tuple(x1, x - q * x1);
    std::tie(y, y1) = std::make_tuple(y1, y - q * y1);
    std::tie(a1, b1) = std::make_tuple(b1, a1 - q * b1);
  }
  return a1;
}
