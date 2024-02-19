#include "list_array.h"
#include <iostream>

int main() {
  ListArray l(3);
  l.push_back("Javier");
  l.push_back("Simona");
  l.push_back("Jerry");

  std::string &javier = l[0];

  l.push_back("David");

  javier = "Javier Francisco";

  std::cout << l << std::endl;

  return 0;
}
