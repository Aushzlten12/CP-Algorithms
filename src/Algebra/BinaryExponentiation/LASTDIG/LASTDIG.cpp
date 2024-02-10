#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

int LastDig(int a, long long b) {
  a %= 10;
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % 10;
    }
    a = a * a % 10;
    b >>= 1;
  }
  return res;
}

int main() {
  std::ifstream fich("./../inputLASTDIG.txt");
  if (!fich) {
    std::cout << "Can't open the file";
    return 1;
  }

  std::vector<std::vector<int>> InputsSplited;
  std::string line;
  bool isFirstLine = true;

  while (std::getline(fich, line)) {
    if (isFirstLine) {
      isFirstLine = false;
      continue;
    }
    std::istringstream iss(line);
    std::vector<int> inputSplit;
    int number;

    while (iss >> number) {
      inputSplit.push_back(number);
    }

    InputsSplited.push_back(inputSplit);
  }

  fich.close();

  bool firstParameter = true;
  int a;
  long long b;
  std::vector<int> outputs;

  for (const auto &input : InputsSplited) {
    for (int i = 0; i < input.size(); i++) {
      if (firstParameter) {
        a = input[i];
        firstParameter = false;
      } else {
        b = input[i];
        firstParameter = true;
      }
    }
    int output = LastDig(a, b);
    outputs.push_back(output);
  }
  for (const auto &output : outputs) {
    std::cout << output << std::endl;
  }
  return 0;
}
