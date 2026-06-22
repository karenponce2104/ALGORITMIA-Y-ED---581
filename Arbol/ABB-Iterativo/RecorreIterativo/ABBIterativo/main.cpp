#include <iostream>
#include "Biblioteca/ArbolBinarioBusqueda.h"
#include "Biblioteca/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaCola/Cola.h"
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
#include "BibliotecaCola/funcionesCola.h"

using namespace std;

NodoArbolBinarioBusqueda*buscaNodo(ArbolBinarioBusqueda arbol,int dato) {
    NodoArbolBinarioBusqueda*prec=arbol.raiz;
    if (prec==nullptr) return nullptr;
    while (prec) {
        if (prec->elemento.numero==dato)
            return prec;
        else {
            if (prec->elemento.numero>dato)
                prec=prec->izquierda;
            else
                prec=prec->derecha;
        }
    }
    return nullptr;
}
void amplitud(ArbolBinarioBusqueda arbol) {
    Cola cola;
    NodoArbolBinarioBusqueda*prec=arbol.raiz;
    if (prec==nullptr) return;
    construir(cola);
    encolar(cola,{prec->elemento.numero});
    while (not esColaVacia(cola)) {
        int dato=desencolar(cola).codigo;
        cout << dato << " ";
        prec=buscaNodo(arbol,dato);
        if (prec->izquierda!=nullptr)
            encolar(cola,{prec->izquierda->elemento.numero});
        if (prec->derecha!=nullptr)
            encolar(cola,{prec->derecha->elemento.numero});
    }
}


void posordeniterativo(ArbolBinarioBusqueda arbol) {
    Pila pila;
    int ultimo;
    if (esArbolVacio(arbol))return;
    NodoArbolBinarioBusqueda *prec=arbol.raiz;
    construir(pila);
    while (true) {
        while (prec) {
            apilar(pila,{prec->elemento.numero});
            prec=prec->izquierda;
        }
        int alto=cima(pila).numero;
        prec=buscaNodo(arbol,alto);
        if (prec->derecha and ultimo!=prec->derecha->elemento.numero)
            prec=prec->derecha;
        else {
            ultimo=desapilar(pila).numero;
            cout << ultimo <<" ";
            prec=nullptr;
        }
        if (esPilaVacia(pila))break;
    }
}


int main() {
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    insertar(arbol,{15});
    insertar(arbol,{5});
    insertar(arbol,{20});
    insertar(arbol,{1});
    insertar(arbol,{10});
    insertar(arbol,{30});

    recorrerPreOrden(arbol);
    cout << endl;
    posordeniterativo(arbol);
    cout << endl;
    amplitud(arbol);

    return 0;
}