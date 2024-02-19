#include "list_linked_single.h"
#include <iostream>

int main() {
  ListLinkedSingle l1;
  l1.push_back("David");
  l1.push_back("Maria");
  l1.push_back("Elvira");

  ListLinkedSingle l2 = l1;

  // La siguiente inserción debería afectar solamente a l2
  l2.push_back("Daniel");

  // Comprobamos que l1 sigue intacto
  l1.display();
  std::cout << std::endl;
  l2.display();
  std::cout << std::endl;
}
