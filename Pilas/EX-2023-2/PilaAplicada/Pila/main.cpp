//Fecha:  lunes 01 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
using namespace std;

void hex(int n,Pila &ini,Pila&fin,Pila &aux1,Pila &aux2) {
    if (n==0)return;
    if (n==1) {
        ElementoPila valor=desapilar(ini);
        apilar(fin,valor);
        return;
    }
    hex(n-2,ini,aux1,aux2,fin);
    ElementoPila valor=desapilar(ini);
    apilar(aux2,valor);
    valor=desapilar(ini);
    apilar(fin,valor);
    valor=desapilar(aux2);
    apilar(fin,valor);
    hex(n-2,aux1,fin,ini,aux2);
}


void hanoi(int n,Pila &ini,Pila &fin,Pila &aux) {
    if (n==1) {
        ElementoPila valor=desapilar(ini);
        apilar(fin,valor);
        return;
    }
    hanoi(n-1,ini,aux,fin);
    ElementoPila valor=desapilar(ini);
    apilar(fin,valor);
    hanoi(n-1,aux,fin,ini);
}


void apila(int *faja,Pila principal,int n) {
    ElementoPila dato;
    Pila fin,aux;
    construir(fin);
    construir(aux);
    for (int i = 0; i < n; i++) {
        dato.numero= faja[i];
        int cont=0;
        if (esPilaVacia(principal) or cima(principal).numero>dato.numero )
            apilar(principal,dato);
        else {
            while (not esPilaVacia(principal)
                and dato.numero>cima(principal).numero) {
                ElementoPila temp=desapilar(principal);
                apilar(fin,temp);
                if (cont>0)
                    hanoi(cont,aux,fin,principal);
                cont++;
                hanoi(cont,fin,aux,principal);
            }
            apilar(principal,dato);
            hanoi(cont,aux,principal,fin);
        }
    }
}


int main(int argc, char ** argv) {
    int faja[]={3,5,8,10,8,2};
    int n=sizeof(faja)/sizeof(faja[0]);
    struct ElementoPila elemento{};
    Pila principal;
    construir(principal);
    apila(faja,principal,n);


    return 0;
}
