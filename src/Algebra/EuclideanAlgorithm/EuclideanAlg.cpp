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
