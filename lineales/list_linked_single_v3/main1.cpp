#include "list_linked_single.h"
#include <iostream>

int contar_caracteres(const ListLinkedSingle &l) {
  int suma = 0;
  for (int i = 0; i < l.size(); i++) {
    suma += l.at(i).length();
  }
  return suma;
}

int main() {
  ListLinkedSingle l;
  l.push_back("David");
  l.push_back("Maria");
  l.push_back("Elvira");

  std::string &m = l.at(1);
  m = "Manuel";
  l.display();
  std::cout << std::endl;

  std::cout << contar_caracteres(l) << std::endl;
}
