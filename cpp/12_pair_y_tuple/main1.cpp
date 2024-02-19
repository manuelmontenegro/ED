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

   Aquí se muestra el uso de parámetros de salida.
*/

#include <algorithm>
#include <iostream>
#include <limits>

// Función que calcula el mínimo de los elementos de un array

int min(int *array, int longitud) {
  int min = std::numeric_limits<int>::max();

  for (int i = 0; i < longitud; i++) {
    min = std::min(min, array[i]);
  }

  return min;
}

// Función que calcula el mínimo y el máximo de los elementos de un array
// Devuelve ambos resultados como parámetros de salida

void min_max(int *array, int longitud, int &min, int &max) {
  min = std::numeric_limits<int>::max();
  max = std::numeric_limits<int>::min();

  for (int i = 0; i < longitud; i++) {
    min = std::min(min, array[i]);
    max = std::max(max, array[i]);
  }
}

int main() {
  int arr[] = {5, 1, -4, 10, 24, 8, -1};
  int longitud = sizeof(arr) / sizeof(int);

  int min, max;
  min_max(arr, longitud, min, max);
  std::cout << "Min = " << min << " | Max = " << max << std::endl;

  return 0;
}
