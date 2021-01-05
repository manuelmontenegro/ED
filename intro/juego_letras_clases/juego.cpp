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
 * Última versión del juego de adivinar letras. Aquí
 * ya se utilizan clases en C++ para encapsular el acceso a
 * atributos
 */

#include <iostream>

// Es posible alternar entre las dos implementaciones comentando y
// descomentando las líneas siguientes

#include "ConjuntoChar.h"
// #include "ConjuntoCharArray.h"

#include "utils.h"

int main() {
  int jugador_actual = 1;

  ConjuntoChar letras_nombradas;

  char letra_actual = preguntar_letra(jugador_actual);

  while (!letras_nombradas.contiene(letra_actual)) {
    letras_nombradas.anyadir(letra_actual);
    jugador_actual = cambio_jugador(jugador_actual);
    letra_actual = preguntar_letra(jugador_actual);
  }

  std::cout << "Jugador " << jugador_actual << " ha perdido!" << std::endl;
  std::cout << "La letra repetida ha sido: " << letra_actual << std::endl;

  return 0;
}
