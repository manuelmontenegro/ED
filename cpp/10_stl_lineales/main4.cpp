#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

template<typename T>
void imprimir(ostream &out, const T &collection) {
    out << "[";
    auto it = collection.cbegin();
    if (it != collection.cend()) {
        out << *it;
        ++it;
        while (it != collection.cend()) {
            out << ", " << *it;
            ++it;
        }

    }
    out << "]";
}

int main() {
    vector<int> origen;
    list<int> destino;

    for (int i = 0; i < 10; i++) {
        origen.push_back(i);
        destino.push_back(100 + i);
    }

    
    imprimir(cout, origen);
    cout << endl;
    imprimir(cout, destino);
    cout << endl;

    copy(origen.begin(), origen.begin() + 5, ++destino.begin());

    imprimir(cout, destino);
    cout << endl;

    ostream_iterator<int> it_salida(cout, " ");
    copy(origen.begin(), origen.end(), it_salida);
}