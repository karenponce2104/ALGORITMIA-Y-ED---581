//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "Cola.h"
#include "funcionesCola.h"
using namespace std;

void construir(struct Cola & colaTAD){
    colaTAD.inicio = nullptr;
    colaTAD.fin = nullptr;
    colaTAD.vip = nullptr;
    colaTAD.longitud = 0;
}

/*devuelve la longitud de la cola*/
int longitud(const struct Cola & colaTAD) {
    return colaTAD.longitud;
}

void encolar(struct Cola &colaTAD, const struct ElementoCola & elemento){
    struct NodoCola *nuevo;
    nuevo = new NodoCola{};
    nuevo->elemento = elemento;
    if(esColaVacia(colaTAD)){
        colaTAD.inicio = nuevo;
        colaTAD.fin = nuevo;
    }
    else {
        colaTAD.fin->siguiente = nuevo;
        colaTAD.fin = nuevo;
    }
    colaTAD.longitud++;
}

void encolarprioridad(Cola &colaTAD, const ElementoCola & elemento) {
    struct NodoCola *nuevo;
    nuevo = new NodoCola{};
    nuevo->elemento = elemento;
    if (esColaVacia(colaTAD)) {
        colaTAD.inicio = nuevo;
        colaTAD.fin = nuevo;
        if (nuevo->elemento.tipo==1)
            colaTAD.vip = nuevo;
    }
    else {
        if (nuevo->elemento.tipo==1) {
            if (colaTAD.vip==nullptr) {
                nuevo->siguiente=colaTAD.inicio;
                colaTAD.inicio=nuevo;
            }
            else {
                nuevo->siguiente =colaTAD.vip->siguiente;
                colaTAD.vip->siguiente=nuevo;
                if (colaTAD.fin->elemento.tipo==1)
                    colaTAD.fin=nuevo;
            }
            colaTAD.vip=nuevo;
        }
        else {
            colaTAD.fin->siguiente=nuevo;
            colaTAD.fin=nuevo;
        }
    }
    colaTAD.longitud++;
}

struct ElementoCola desencolar(struct Cola & colaTAD){
    struct NodoCola * pSale;
    struct ElementoCola elemento;
    pSale = colaTAD.inicio;
    colaTAD.inicio = colaTAD.inicio->siguiente;
    elemento = pSale->elemento;
    colaTAD.longitud--;
    delete pSale;
    return elemento;
}

bool esColaVacia(const struct Cola & colaTAD){
    return colaTAD.inicio == nullptr;
}

void imprimir(const struct Cola & colaTAD) {
    if (esColaVacia(colaTAD)) {
        cout << "La cola esta vacia no se puede mostrar" << endl;
    } else {
        struct NodoCola * recorrido = colaTAD.inicio;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca las comas despues del inicio*/
            if ( not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout <<recorrido->elemento.tipo<<"-"<<recorrido->elemento.numero;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}