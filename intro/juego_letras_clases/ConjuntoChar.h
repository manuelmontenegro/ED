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
 * con un array de booleanos.
 */
#ifndef __CONJUNTO_CHAR_H
#define __CONJUNTO_CHAR_H

const int MAX_CHARS = 26;

class ConjuntoChar {
public:
  ConjuntoChar();

  bool contiene(char letra) const;
  void anyadir(char letra);

private:
  bool esta[MAX_CHARS];
};



#endif
