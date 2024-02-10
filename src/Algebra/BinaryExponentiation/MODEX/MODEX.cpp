#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

long long binpowModule(long long a, long long b, long long n) {
  a %= n;
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % n;
    }
    a = a * a % n;
    b >>= 1;
  }
  return res;
}

int main(int argc, char *argv[]) {
  std::string filename = "./../inputMODEX.txt";
  std::ifstream fich(filename);
  if (!fich) {
    std::cout << "Can't open the file";
    return 1;
  }

  std::vector<std::string> lines;
  std::string line;

  while (std::getline(fich, line)) {
    lines.push_back(line);
  }

  fich.close();

  std::vector<std::vector<int>> InputsSplited;

  for (int i = 1; i <= std::stoi(lines[0]); i++) {
    std::string line = lines[i];
    std::vector<int> inputSplit;
    char separator = ' ';
    int j = 0;
    std::string number;

    while (line[j] != '\0') {
      if (line[j] != separator) {
        number += line[j];
      } else {
        inputSplit.push_back(std::stoi(number));
        number.clear();
      }
      j++;
    }
    inputSplit.push_back(std::stoi(number));
    InputsSplited.push_back(inputSplit);
  }
  // InputsSplited have vectors with each number
  int Nnumbers = InputsSplited[0].size();
  std::vector<long long> parameters(Nnumbers);
  std::vector<long long> outputs;

  for (const auto &line : InputsSplited) {
    for (int i = 0; i < line.size(); i++) {
      parameters[i] = line[i];
    }
    long long output =
        binpowModule(parameters[0], parameters[1], parameters[2]);
    outputs.push_back(output);
  }

  for (const auto &output : outputs) {
    std::cout << output << std::endl;
  }

  return 0;
}
