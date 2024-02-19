
#include <iostream>
#include <iterator>

using namespace std;

int main() {
    ostream_iterator<int> it(cout, " ");

    *it = 10;
    it++; // Opcional. No hace nada.
    *it = 20;    
    it++; // Opcional. No hace nada.

    cout << endl;

    return 0;
}