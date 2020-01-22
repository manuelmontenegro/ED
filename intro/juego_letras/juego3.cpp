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
 * Tercera versión del juego de adivinar letras, en el que
 * se representa un conjunto mediante un array de booleanos,
 * y se respeta la encapsulación en la función main().
 */
#include <iostream>
#include <cassert>

#include "utils.h"

const int MAX_CHARS = 26;

struct ConjuntoChar {
  bool esta[MAX_CHARS];
};


bool pertenece(char c, const ConjuntoChar &conjunto) {
  assert (c >= 'A' && c <= 'Z');
  return conjunto.esta[c - 'A'];
}

void vacio(ConjuntoChar &result) {
  for (int i = 0; i < MAX_CHARS; i++) {
    result.esta[i] = false;
  }
}

void anyadir(char letra, ConjuntoChar &conjunto) {
  assert (letra >= 'A' && letra <= 'Z');
  conjunto.esta[letra - 'A'] = true;
}


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
