//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
using namespace std;

void invierte(Lista &plista) {
    int n=plista.longitud;
    NodoLista *paux,*prec,*pant=nullptr;
    prec=plista.inicio;
    paux=prec->siguiente;
    for (int i=1;i<n;i++) {
        pant=prec;
        prec=paux;
        paux=paux->siguiente;
        prec->siguiente=pant;
        if (i==1)pant->siguiente=nullptr;
    }
    plista.inicio=prec;
}
NodoLista* recorre(NodoLista* prec) {
    if (prec==nullptr)return nullptr;
    if (prec->siguiente==nullptr)return prec;
    NodoLista *pini=recorre(prec->siguiente);
    NodoLista *paux=prec->siguiente;
    paux->siguiente = prec;
    return pini;
}

void invierterec(Lista &plista) {
    recorre(plista.inicio);

}
int main(int argc, char **argv) {

    ElementoLista elemento{};
    Lista listaEnOrden;

    construir(listaEnOrden);

    for (int i = 1; i < 10; i+=2) {
        elemento.codigo = i;
        insertarAlFinal(listaEnOrden, elemento);
    }
    imprimir(listaEnOrden);
    invierte(listaEnOrden);
    imprimir(listaEnOrden);


    return 0;
}
