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
 * Uso del TAD Diccionario mediante tablas hash
 */

#include "map_hash_open.h"

using namespace std;

int main() {
  hash<int> h_int;
  hash<std::string> h_str;

  std::cout << h_int(24) << std::endl;
  std::cout << h_str("Pepe") << std::endl;
  std::cout << h_str("Maria") << std::endl;

  MapHash<string, int> map;
  map.insert({"David", 23});
  map.insert({"Pablo", 31});
  map.insert({"Sandra", 30});

  cout << boolalpha << map.contains("David") << endl;
  cout << map.at("David") << endl;

  map.at("Pablo")++;

  cout << map.at("Pablo") << endl;

  map["Marta"] = 28;
  cout << map.at("Marta") << endl;

  map.erase("Sandra");
  map.erase("Nadie");

  cout << map << endl;
}
