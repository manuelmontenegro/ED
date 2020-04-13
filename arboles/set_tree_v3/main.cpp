/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */
 
/*
 * Uso del TAD Conjunto
 */

#include "set_tree.h"

using namespace std;

struct Point {
    double x;
    double y;
};

class ComparadorPoint {
public:
    bool operator()(const Point &p1, const Point &p2) const { return p1.x < p2.x || p1.x == p2.x && p1.y < p2.y; }
};

class ComparadorPointInverso {
public:
    bool operator()(const Point &p1, const Point &p2) const { return p1.y < p2.y || p1.y == p2.y && p1.x < p2.x; }
};


int main() {
    SetTree<Point, ComparadorPoint> sv;

    sv.insert({1, 3});
    sv.insert({1, 2});
    sv.insert({3, 6});
    sv.insert({4, 2});
    sv.insert({4, 5});

    for (const Point &p : sv) {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }

    cout << "---" << endl;

    SetTree<Point, ComparadorPointInverso> sv2;

    sv2.insert({1, 3});
    sv2.insert({1, 2});
    sv2.insert({3, 6});
    sv2.insert({4, 2});
    sv2.insert({4, 5});

    for (const Point &p : sv2) {
        cout << "(" << p.x << ", " << p.y << ")" << endl;
    }

    return 0;
}
