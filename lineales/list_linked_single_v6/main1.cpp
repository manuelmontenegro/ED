#include <iostream>
#include "list_linked_single.h"

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
  /*
  l.display(); std::cout << std::endl;
  
  std::cout << "Elemento 1: " << l.at(1) << std::endl;

  l.pop_front();
  l.display(); std::cout << std::endl;
  
  return 0;
  */
}
