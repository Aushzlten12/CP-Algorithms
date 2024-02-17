#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
int gcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

int SolutionCrucialEquation(int a, int b, int c, int &x, int &y, int &g) {
  g = gcd(abs(a), abs(b), x, y);
  if (c % g) {
    return false;
  }
  x *= c / g;
  y *= c / g;
  if (a < 0)
    x = -x;
  if (b < 0)
    y = -y;
  return true;
}

int main(int argc, char *argv[]) {
  std::string filename = "./../inputSPOJ.txt";
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

  int NParameters = InputsSplited[0].size();
  std::vector<int> parameters(NParameters);
  std::vector<std::string> outputs;
  int x, y, g;
  for (const auto &line : InputsSplited) {
    for (int i = 0; i < line.size(); i++) {
      parameters[i] = line[i];
    }
    std::string output = SolutionCrucialEquation(parameters[0], parameters[1],
                                                 parameters[2], x, y, g)
                             ? "YES"
                             : "NO";
    outputs.push_back(output);
  }

  for (const auto &output : outputs) {
    std::cout << output << std::endl;
  }
  return 0;
}
