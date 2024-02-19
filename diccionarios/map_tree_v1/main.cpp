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

int main() {
  MapTree<string, int> dicc;
  dicc.insert({"Javier", 23});
  dicc.insert({"David", 25});
  dicc.insert({"Marga", 29});

  cout << dicc << endl;

  cout << "Edad de Marga: " << dicc.at("Marga") << endl;

  dicc.at("Marga") = 30;

  dicc["Diana"] = 41;

  dicc["Javier"]++;

  cout << dicc << endl;

  return 0;
}
