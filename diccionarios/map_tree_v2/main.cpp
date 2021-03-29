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
 * Uso del TAD Diccionario
 */

#include "map_tree.h"

using namespace std;

struct Coords {
  double x;
  double y;
};

struct OrdenLexicografico {
  bool operator()(const Coords &p1, const Coords &p2) const {
    return p1.x < p2.x || p1.x == p2.x && p1.y < p2.y;
  }
};

int main() {
  MapTree<double, string> posiciones;

  posiciones.insert({-3, "Laura"});
  posiciones.insert({4.5, "Gloria"});
  posiciones.insert({2, "Belén"});
  posiciones.insert({0.5, "Samuel"});

  MapTree<Coords, string, OrdenLexicografico> dicc;

  dicc.insert({{3, 3}, "Laura"});
  dicc.insert({{5, -3}, "Gloria"});
  dicc.insert({{1, 2}, "Belén"});
  dicc.insert({{-1, -5}, "Samuel"});

  cout << dicc[{3, 3}] << endl;
}
