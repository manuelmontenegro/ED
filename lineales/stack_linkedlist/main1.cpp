#include <iostream>
#include "stack_linkedlist.h"




int main() {
  StackLinkedList<int> s;
  s.push(1);
  s.push(5);
  s.push(10);

  std::cout << s.top() << std::endl;
  s.pop();
  std::cout << s.top() << std::endl;
  s.pop();
  std::cout << s.top() << std::endl;
  s.pop();

  
}
