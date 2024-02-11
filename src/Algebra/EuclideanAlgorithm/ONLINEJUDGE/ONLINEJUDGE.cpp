#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

int ExtendGCD(int a, int b, int &x, int &y) {
  x = 1, y = 0;
  int x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    int q = a1 / b1;
    std::tie(x, x1) = std::make_tuple(x1, x - q * x1);
    std::tie(y, y1) = std::make_tuple(y1, y - q * y1);
    std::tie(a1, b1) = std::make_tuple(b1, a1 - q * b1);

    // Intercambia x1 e y1 si es necesario para garantizar x1 <= y1
    if (x > y) {
      std::swap(x, y);
      std::swap(x1, y1);
    }
  }
  return a1;
}

int main(int argc, char *argv[]) {
  std::string filename = "./../inputONLINEJUDGE.txt";
  std::ifstream fich(filename);
  if (!fich) {
    std::cout << "Can't open the file";
    return 1;
  }

  std::string line;
  std::vector<int> inputs;

  while (std::getline(fich, line)) {
    std::istringstream iss(line);
    int number;

    while (iss >> number) {
      inputs.push_back(number);
    }
    if (inputs.size() % 2 == 0) {
      int x, y;
      int gcd =
          ExtendGCD(inputs[inputs.size() - 2], inputs[inputs.size() - 1], x, y);
      std::cout << x << " " << y << " " << gcd << std::endl;
    }
  }

  fich.close();

  return 0;
}
