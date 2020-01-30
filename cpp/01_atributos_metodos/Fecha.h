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
 * Definición de la clase Fecha.
 */

#ifndef __FECHA_H
#define __FECHA_H

#include <iostream>

class Fecha {
public:
    int get_dia() {
        return dia;
    }
    void set_dia(int dia) {
        this->dia = dia;
    }

   
    int get_mes() { return mes; }
    void set_mes(int mes) { this->mes = mes; }
    int get_anyo() { return anyo; }
    void set_anyo(int anyo) { this->anyo = anyo; }

    void imprimir();

private:    
    int dia;
    int mes;
    int anyo;
};


#endif