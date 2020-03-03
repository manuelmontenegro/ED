#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v;
  for (int i = 0; i < 10; i++) {
    v.push_back(i * 3);
  }

  cout << v.size() << endl;
  
  int suma = 0;
  for (int x : v) {
    suma += x;
  }

  cout << "Suma total: " << suma << endl;
  
  return 0;
}