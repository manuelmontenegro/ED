/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */


#ifndef __UTILS_H
#define __UTILS_H

/*
 * Funciones de utilidad para el ejemplo presentado en
 * la introducción a los TADs.
 */

/*
 * Solicita una letra al jugador pasado como parámetro.
 */ 
char preguntar_letra(int jugador_actual);

/*
 * Devuelve el número de jugador contrario al pasado
 * como parámetro
 */
int cambio_jugador(int jugador_actual);

char preguntar_letra(int jugador_actual) {
  char result;
  std::cout << "Jugador " << jugador_actual << ": ";
  std::cin >> result;

  while (result < 'A' || result > 'Z') {
    std::cout << "Letra no válida. Prueba otra vez: ";
    std::cin >> result;
  }
  return result;
}

int cambio_jugador(int jugador_actual) {
  return 3 - jugador_actual;
}

#endif
