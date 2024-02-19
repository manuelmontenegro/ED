/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

/* Distintas formas de implementar una función que devuelva
   varios resultados

   Aquí se muestra el uso de una tipo específico para el resultado.
   */

#include <algorithm>
#include <iostream>
#include <limits>

struct MinMaxResult {
  int min;
  int max;
};

MinMaxResult min_max(int *array, int longitud) {
  MinMaxResult res;
  res.min = std::numeric_limits<int>::max();
  res.max = std::numeric_limits<int>::min();

  for (int i = 0; i < longitud; i++) {
    res.min = std::min(res.min, array[i]);
    res.max = std::max(res.max, array[i]);
  }

  return res;
}

int main() {
  int arr[] = {5, 1, -4, 10, 24, 8, -1};
  int longitud = sizeof(arr) / sizeof(int);

  MinMaxResult r = min_max(arr, longitud);
  std::cout << "Min = " << r.min << " | Max = " << r.max << std::endl;

  return 0;
}
