#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

long gcd(long a, long b) {
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

int main(int argc, char *argv[]) {
  std::string namefile = "./../inputCSACADEMY.txt";
  std::ifstream fich(namefile);
  if (!fich) {
    std::cout << "Can't open the file";
    return 1;
  }

  std::vector<long> InputSplited;
  std::string line;

  while (std::getline(fich, line)) {
    std::istringstream iss(line);
    long number;

    while (iss >> number) {
      InputSplited.push_back(number);
    }
  }

  fich.close();

  bool firstParameter = true;
  long output = gcd(InputSplited[0], InputSplited[1]);

  std::cout << output << std::endl;

  return 0;
}
