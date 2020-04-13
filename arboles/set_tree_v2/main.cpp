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

int main() {
    SetTree<Point, ComparadorPoint> sv;

    sv.insert({1, 3});
    sv.insert({4, 2});

    cout << boolalpha << sv.contains({1, 3}) << endl;
    return 0;
}
