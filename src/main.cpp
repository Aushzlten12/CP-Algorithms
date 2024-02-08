#include "BinaryExp.cpp"
#include <iostream>
#include <vector>

using namespace std;

// Función para imprimir un vector
void printVector(const vector<int> &vec) {
  for (int num : vec) {
    cout << num << " ";
  }
  cout << endl;
}

int main() {
  // Ejemplo de uso
  vector<int> originalSequence = {1, 2, 3, 4, 5};
  vector<int> permutation = {4, 3, 1, 0, 2}; // Una permutación arbitraria

  cout << "Secuencia original: ";
  printVector(originalSequence);

  // Aplicar la permutación una vez
  vector<int> newSequence = applyPermutation(originalSequence, permutation);
  cout << "Secuencia después de aplicar la permutación una vez: ";
  printVector(newSequence);

  // Aplicar la permutación 3 veces usando la exponenciación rápida
  long long k = 3;
  newSequence = permute(originalSequence, permutation, k);
  cout << "Secuencia después de aplicar la permutación " << k << " veces: ";
  printVector(newSequence);

  return 0;
}
