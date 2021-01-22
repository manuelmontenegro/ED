#include "list_array.h"
#include <iostream>

int contar_caracteres(const ListArray &l) {
  int suma = 0;
  for (int i = 0; i < l.size(); i++) {
    suma += l[i].length();
  }
  return suma;
}

int main() {
  ListArray l1;
  l1.push_back("David");
  l1.push_back("Maria");
  l1.push_back("Elvira");

  ListArray l2 = l1;
  l2[1] = "Manuel";

  std::cout << l1 << " " << l2 << std::endl;
}
