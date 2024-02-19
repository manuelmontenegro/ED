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
 * Segunda versión del juego de adivinar letras, en el que
 * se representa un conjunto mediante un array de elementos,
 * y se respeta la encapsulación en la función main().
 */
#include <iostream>
#include "utils.h"

// Puedes alternar entre las dos implementaciones descomentando uno de los siguientes #include
// manteniendo comentado el otro. ¡El método main no cambia!

#include "ConjuntoCharArray.h"
//#include "ConjuntoCharBool.h"

int main() {
  int jugador_actual = 1;

  ConjuntoChar letras_nombradas;
  vacio(letras_nombradas);

  char letra_actual = preguntar_letra(jugador_actual);

  while (!pertenece(letra_actual, letras_nombradas)) {
    anyadir(letra_actual, letras_nombradas);
    jugador_actual = cambio_jugador(jugador_actual);
    letra_actual = preguntar_letra(jugador_actual);
  }

  std::cout << "Jugador " << jugador_actual << " ha perdido!" << std::endl;
  std::cout << "La letra repetida ha sido: " << letra_actual << std::endl;

  return 0;
}
