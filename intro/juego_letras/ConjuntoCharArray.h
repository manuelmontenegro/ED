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
 * Definición del TAD ConjuntoChar mediante una clase
 * con un array de caracteres.
 */

#ifndef __CONJUNTO_CHAR_ARRAY_H
#define __CONJUNTO_CHAR_ARRAY_H

const int MAX_CHARS = 26;

class ConjuntoChar {
public:
  ConjuntoChar(): num_chars(0) {}

  bool contiene(char c) const;
  void anyadir(char letra);
  
private:
  int num_chars;
  char elementos[MAX_CHARS];
};

#endif
