//Fecha:  lunes 01 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
using namespace std;

void pasapila(Pila &pila1,Pila &pila2) {
    ElementoPila valor,aux;
    while (not esPilaVacia(pila1)) {
        int cont=0;
        valor = desapilar(pila1);
        while (not esPilaVacia(pila1)) {
            apilar(pila2,valor);
            valor = desapilar(pila1);
            cont++;
        }
        while (not esPilaVacia(pila2) and cont>0) {
            aux=desapilar(pila2);
            apilar(pila1,aux);
            cont--;
        }
        apilar(pila2,valor);
    }
}


int main(int argc, char ** argv) {
    /*Funciones de Pila*/
    struct Pila pilaA,pilaB;
    struct ElementoPila elemento{};
    construir(pilaA);
    /*Apilamos elementos en la pila*/
    for (int i = 1; i <= 5; i++) {
        elemento.numero = i;
        apilar(pilaA, elemento);
    }
    elemento = cima(pilaA);
    cout << "La cima es: " << elemento.numero << endl;
    cout << longitud(pilaA) << endl;
    imprimir(pilaA);
    construir(pilaB);
    pasapila(pilaA,pilaB);
    imprimir(pilaB);
    imprimir(pilaA);

    return 0;
}
