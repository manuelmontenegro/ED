#include "list_linked_single.h"
#include <iostream>

template <typename Elem>
int contar_caracteres(const ListLinkedSingle<Elem> &l) {
  int suma = 0;
  for (int i = 0; i < l.size(); i++) {
    suma += l[i].length();
  }
  return suma;
}

int main() {
  ListLinkedSingle<std::string> l;
  l.push_back("David");
  l.push_back("Maria");
  l.push_back("Elvira");

  std::string &m = l[1];
  m = "Manuel";
  std::cout << l << std::endl;

  std::cout << contar_caracteres(l) << std::endl;
}
