//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
using namespace std;


int main(int argc, char **argv) {
    struct Cola cola;
    construir(cola);

    encolarprioridad(cola,{2,11});
    encolarprioridad(cola,{1,10});
    encolarprioridad(cola,{1,12});
    encolarprioridad(cola,{2,20});
    encolarprioridad(cola,{1,15});

    imprimir(cola);
    return 0;
}
