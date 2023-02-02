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
 * Definición de la clase Fecha con constructores.
 */

#ifndef __FECHA_H
#define __FECHA_H

#include <iostream>
#include <iomanip>

class Fecha {
public:
    Fecha(int dia, int mes, int anyo): dia(dia), mes(mes), anyo(anyo) {
        // vacío
    }

    Fecha(int anyo): Fecha(1, 1, anyo) {
        // vacío
    }

    int get_dia() const { return dia; } 
    void set_dia(int dia) { this->dia = dia; }
    int get_mes() const { return mes; }
    void set_mes(int mes) { this-> mes = mes; }
    int get_anyo() const { return anyo; }
    void set_anyo(int anyo) { this -> anyo = anyo; }

    void imprimir();
    void imprimir(std::ostream &out);

private:    
    int dia;
    int mes;
    int anyo;
};

void Fecha::imprimir() {
    this->imprimir(std::cout);
}

void Fecha::imprimir(std::ostream &out) {
    out << std::setfill('0') << std::setw(2) << dia << "/" 
        << std::setw(2) << mes << "/" 
        << std::setw(4) << anyo;
}

#endif