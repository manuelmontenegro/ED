#include "list_array.h"
#include <iostream>

int main() {
  ListArray l1;
  l1.push_back("David");
  l1.push_back("Maria");
  l1.push_back("Eugenio");

  ListArray l2 = l1;
  l2.front() = "Pepe";

  std::cout << l1 << std::endl;
  std::cout << l2 << std::endl;
}
