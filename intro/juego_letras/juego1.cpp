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
 * Primera versión del juego de mencionar letras, en el
 * que se implementa un conjunto mediante un array de
 * elementos, y no se respeta encapsulación.
 */

#include <iostream>
#include "utils.h"

const int MAX_CHARS = 26;

struct ConjuntoChar {
  int num_chars;
  char elementos[MAX_CHARS];
};


bool esta_en_conjunto(char c, const ConjuntoChar &conjunto) {
  int i = 0;
  while (i < conjunto.num_chars && conjunto.elementos[i] != c) {
    i++;
  }
  return conjunto.elementos[i] == c;
}


int main() {
  int jugador_actual = 1;
  
  ConjuntoChar letras_nombradas;
  letras_nombradas.num_chars = 0;

  char letra_actual = preguntar_letra(jugador_actual);

  while (!esta_en_conjunto(letra_actual, letras_nombradas)) {
    letras_nombradas.elementos[letras_nombradas.num_chars] = letra_actual;
    letras_nombradas.num_chars++;

    jugador_actual = cambio_jugador(jugador_actual);
    letra_actual = preguntar_letra(jugador_actual);
  }

  std::cout << "Jugador " << jugador_actual << " ha perdido!" << std::endl;
  std::cout << "La letra repetida ha sido: " << letra_actual << std::endl;
  
  return 0;
}
