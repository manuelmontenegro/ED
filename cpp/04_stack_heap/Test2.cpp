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
  * Compartición de objetos
  */
  
#include "Fecha.h"
#include <iostream>



int main() {
    Fecha *f1 = new Fecha(28, 8, 2019);
    Fecha *f2 = f1;

    std::cout << "Antes de modificar f1:" << std::endl;
    f1->imprimir();
    std::cout << std::endl;
    f2->imprimir();
    std::cout << std::endl;

    f1->set_dia(1);

    std::cout << "Después de modificar f1:" << std::endl;
    f1->imprimir();
    std::cout << std::endl;
    f2->imprimir();
    std::cout << std::endl;

    delete f1;
    // ¡Ojo! No hacer 'delete f2'

    return 0;
}