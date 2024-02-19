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
    vector<int> v;
    v.push_back(10);
    v.push_back(34);
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);

    imprimir(cout, v);
    cout << endl;

    sort(v.begin(), v.end());

    imprimir(cout, v);
    cout << endl;    

    int elems[] = {14, 5, 1, 20, 4, 7};

    sort(elems, elems + 6);

    copy(elems, elems + 6, ostream_iterator<int>(cout, " "));
}

