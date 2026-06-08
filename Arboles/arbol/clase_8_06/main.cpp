#include <iostream>
#include "BibliotecaArbolBinario/funcionesArbolBinario.h"
#include "BibliotecaArbolBinario/ArbolBinario.h"
using namespace std;

void inserta_der(NodoArbolBinario *nodo, ElementoArbolBinario gen) {
    nodo->izquierda;

    struct NodoArbolBinario *nuevo = new struct NodoArbolBinario;
    nuevo->elemento = gen;
    nuevo->izquierda = nullptr;
    nuevo->derecha = nullptr;
    nodo->derecha = nuevo;
}

void inserta_izq(NodoArbolBinario *nodo, ElementoArbolBinario gen) {
    nodo->izquierda;

    struct NodoArbolBinario *nuevo = new struct NodoArbolBinario;
    nuevo->elemento = gen;
    nuevo->izquierda = nullptr;
    nuevo->derecha = nullptr;
    nodo->izquierda = nuevo;
}
void insertanivelCromo(NodoArbolBinario *nodo, int *pesos, int ini, int n) {
    ElementoArbolBinario gen;
    if (ini == n) return;

    gen.numero=0;
    gen.peso = pesos[ini];
    inserta_izq(nodo, gen);
    insertanivelCromo(nodo->izquierda, pesos, ini+1, n);
    gen.numero=1;
    gen.peso = pesos[ini];
    inserta_der(nodo, gen);
    insertanivelCromo(nodo->derecha, pesos, ini+1, n);
    //cada lado se expande de forma independiente
}

void creaarbolcromo(ArbolBinario &arbol, int *paquete, int n) {
    ArbolBinario arbolvacio;
    construir(arbolvacio);
    plantarArbolBinario(arbol, arbolvacio, {0,0}, arbolvacio);
    insertanivelCromo(arbol.raiz, paquete, 0,  n);

}

int main() {
    struct ArbolBinario arbol;
    int peso[]={10,50};//,20,30,40};
    int n= sizeof(peso)/sizeof(peso[0]);
    construir (arbol);
    creaarbolcromo(arbol, peso, n);
    cout<<endl;
    recorrerPreOrden(arbol);


    return 0;
}