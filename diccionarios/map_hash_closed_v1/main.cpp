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
 * Uso del TAD Diccionario mediante tablas hash cerradas
 */

#include "map_hash_closed.h"

using namespace std;

int main() {

  MapHash<string, int> map;

  map.insert({"David", 23});
  map.insert({"Pablo", 31});
  map.insert({"Sandra", 30});

  cout << map << endl;

  map.insert({"David", 41});

  cout << map << endl;

  cout << boolalpha << map.contains("David") << endl;
  cout << map.at("David") << endl;
  cout << boolalpha << map.contains("Nadia") << endl;

  map.at("Pablo")++;

  cout << map.at("Pablo") << endl;

  map["Marta"] = 28;
  cout << map.at("Marta") << endl;
  cout << map << endl;

  map.erase("Sandra");
  map.erase("Nadie");

  cout << map << endl;
}
