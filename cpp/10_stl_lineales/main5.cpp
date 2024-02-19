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
    list<int> lista_destino;

    // inicializar origen
    for (int i = 0; i < 10; i++) {
        origen.push_back(i);
    }

    // suponemos que lista_destino está vacía
    back_insert_iterator<list<int>> it_dest(lista_destino);
    copy(origen.begin(), origen.end(), it_dest);

    imprimir(cout, lista_destino);
}

