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

   Aquí se muestra el uso de la clase tuple para devolver más
   de dos valores.
   */

#include <algorithm>
#include <iostream>
#include <limits>
#include <tuple>

// Devuelve una tupla con tres componentes:
// - La primera componente es el valor mínimo del array
// - La segunda componente es el valor máximo del array
// - La tercera componente es la suma de los valores del array

std::tuple<int, int, int> min_max_sum(int *array, int longitud) {
  int min = std::numeric_limits<int>::max();
  int max = std::numeric_limits<int>::min();
  int sum = 0;

  for (int i = 0; i < longitud; i++) {
    min = std::min(min, array[i]);
    max = std::max(max, array[i]);
    sum += array[i];
  }

  return {min, max, sum};
  // return std::make_tuple(min, max, sum);
}

int main() {
  int arr[] = {5, 1, -4, 10, 24, 8, -1};
  int longitud = sizeof(arr) / sizeof(int);

  std::tuple<int, int, int> t = min_max_sum(arr, longitud);
  std::cout << "Min = " << std::get<0>(t) << " | Max = " << std::get<1>(t)
            << " | Sum = " << std::get<2>(t) << std::endl;

  // Uso de la sintaxis permitida a partir de C++17

  // Si no se acepta por Visual Studio 2019: modificar, en las opciones de
  // proyecto, la opción 'Estándar de lenguaje C++' a '/std:c++latest'
  auto [min, max, sum] = min_max_sum(arr, longitud);
  std::cout << "Min = " << min << " | Max = " << max << " | Sum = " << sum
            << std::endl;

  return 0;
}
