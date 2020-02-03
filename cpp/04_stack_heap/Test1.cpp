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
  * Creación de objetos en la pila y en el heap.
  */
 
#include "Fecha.h"

int main()  {
    Fecha f1(28, 8, 2038);
    Fecha *f2 = new Fecha(10, 6, 2010);

    std::cout << "Fecha 1: ";
    f1.imprimir();
    std::cout << std::endl;

    std::cout << "Fecha 2: ";
    f2->imprimir();
    std::cout << std::endl;

    delete f2;
}