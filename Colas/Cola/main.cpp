//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
using namespace std;

void ordenaCola(Cola &pcola) {
    int min,temp;
    int n=pcola.longitud;
    int i,j=n;
    while (j>0) {
        min=desencolar(pcola).numero;
        i=1;
        while (i<j) {
            temp=desencolar(pcola).numero;
            if (min>temp) {
                encolar(pcola,{min});
                min=temp;
            }
            else
                encolar(pcola,{temp});
            i++;
        }
        for (i=j;i<n;i++) {
            temp=desencolar(pcola).numero;
            encolar(pcola,{temp});
        }
        encolar(pcola,{min});
        j--;
    }
}


int main(int argc, char **argv) {
    struct Cola cola;
    struct ElementoCola elemento;
    construir(cola);

    encolar(cola,{11});
    encolar(cola,{10});
    encolar(cola,{12});
    encolar(cola,{20});
    encolar(cola,{15});
    imprimir(cola);
    ordenaCola(cola);
    imprimir(cola);
    return 0;
}
