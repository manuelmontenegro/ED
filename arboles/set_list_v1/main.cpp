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

#include "set_list.h"

using namespace std;

int main() {
  SetList<int> sv;

  sv.insert(10);
  sv.insert(20);

  cout << sv << endl;

  sv.insert(15);

  cout << sv << endl;

  cout << boolalpha << sv.contains(10) << endl;
  sv.erase(10);
  cout << boolalpha << sv.contains(10) << endl;

  return 0;
}
