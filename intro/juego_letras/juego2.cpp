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
#include <cassert>

#include "utils.h"

const int MAX_CHARS = 26;

struct ConjuntoChar {
  int num_chars;
  char elementos[MAX_CHARS];
};


bool pertenece(char c, const ConjuntoChar &conjunto) {
  int i = 0;
  while (i < conjunto.num_chars && conjunto.elementos[i] != c) {
    i++;
  }
  return conjunto.elementos[i] == c;
}

void vacio(ConjuntoChar &conjunto) {
  conjunto.num_chars = 0;
}

void anyadir(char letra, ConjuntoChar &conjunto) {
  assert (conjunto.num_chars < MAX_CHARS);
  assert (letra >= 'A' && letra <= 'Z');
  conjunto.elementos[conjunto.num_chars] = letra;
  conjunto.num_chars++;
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
