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
 * Ejemplos con funciones plantilla
 */

#include <iostream>

template <typename T> const T &min(const T &a, const T &b) {
  if (a <= b) {
    return a;
  } else {
    return b;
  }
}

template <typename T> int min_array(const T *array, int num_elems) {
  int result = 0;
  for (int i = 1; i < num_elems; i++) {
    if (array[i] <= array[result]) {
      result = i;
    }
  }
  return result;
}

int main() {
  std::cout << min<int>(6, 2) << std::endl;
  std::cout << min<double>(3.3, 5.5) << std::endl;
  std::cout << min<std::string>("Pepito", "Ramiro") << std::endl;

  int arr1[] = {1, -3, 5, 7};
  std::string arr2[] = {"David", "Susana", "Miguel Ángel", "Adolfo"};

  std::cout << min_array(arr1, 4) << std::endl;
  std::cout << min_array(arr2, 4) << std::endl;
}
