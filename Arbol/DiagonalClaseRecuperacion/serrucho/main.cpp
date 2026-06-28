#include "Biblioteca/ElementoArbolBinarioBusqueda.h"
#include "Biblioteca/funcionesArbolBinarioBusqueda.h"
#include "Biblioteca/NodoArbolBinarioBusqueda.h"
#include <iostream>
#include "Biblioteca/ArbolBinarioBusqueda.h"
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaCola/NodoCola.h"

using namespace std;


NodoArbolBinarioBusqueda *buscar(NodoArbolBinarioBusqueda *raiz, int dato) {
    if (raiz==nullptr) return nullptr;
    while (raiz!=nullptr) {
        if (raiz->elemento.numero == dato) return raiz;
        if (raiz->elemento.numero > dato)
            raiz= raiz->izquierda;
        else
            raiz= raiz->derecha;
    }
    return nullptr;
}
void recorridodiafonal(ArbolBinarioBusqueda arbol) {
    Cola cola;
    if (esArbolVacio(arbol)) return;
    construir(cola);
    NodoArbolBinarioBusqueda *parbol =arbol.raiz;
    while (parbol!= nullptr) {
        cout<<parbol->elemento.numero<<" "; 
        if (parbol->izquierda!=nullptr) {
            encolar(cola, {parbol->izquierda->elemento.numero});
        }
        if (parbol->derecha!=nullptr) {
            parbol = parbol->derecha;
        }
        else {
            if (!esColaVacia(cola)){
                ElementoCola aux;
                aux = desencolar(cola);
                parbol = buscar(arbol.raiz, aux.numero);
            }
            else {
                parbol =nullptr;
            }
        }

    }
    //desapilas(?
}

int main() {
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    insertar(arbol, {100});
    insertar(arbol, {150});
    insertar(arbol, {50});
    insertar(arbol, {75});
    insertar(arbol, {125});
    insertar(arbol, {175});
    insertar(arbol, {40});
    insertar(arbol, {200});
    recorrerPreOrden(arbol);
    cout<<endl;
    recorridodiafonal(arbol);
    return 0;
}
