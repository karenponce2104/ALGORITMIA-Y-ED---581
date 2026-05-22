/*
 * File:   main.cpp
 * Author: cueva
 *
 * Created on 17 de octubre de 2024, 01:12 AM
 */

#include <iostream>
#include "BibliotecaPila/funcionesPila.h"
#include"BibliotecaPila/Pila.h"

using namespace std;

void izquierda(int *altura,int *izq_altura,int n)
{
	Pila  pila;
	construir(pila);
	for (int i=0; i<n; i++) {
                int cont=0;
		while (esPilaVacia(pila) == false
			and altura[cima(pila).numero]< altura[i]){
                    cont+=izq_altura[cima(pila).numero]+1;
                    desapilar(pila);
                }
                if(cont>0)
                    izq_altura[i]=cont;
                else
                    izq_altura[i]=0;
		apilar(pila,{i});
	}
	return;
}

void derecha(int * altura,int *der_altura,int n)
{
    Pila pila;
    construir(pila);
	for (int i = n - 1; i >= 0; i--) {
            int cont=0;
		while (esPilaVacia(pila) == false
			and altura[cima(pila).numero]< altura[i]){
                    cont+=der_altura[cima(pila).numero]+1;
                    desapilar(pila);
                }
                if(cont>0)
                    der_altura[i]=cont;//+der_altura[i+1];
                else
                    der_altura[i]=0;
                apilar(pila,{i});
	}
	return;
}

int buscabajos(int *altura, int n,int &pos)
{   pos=0;
	int resultado = 0;
	int der_altura[n],izq_altura[n];
        izquierda(altura, izq_altura, n);
        derecha(altura, der_altura, n);
	for (int i = 0; i < n; i++)
            cout << izq_altura[i] << " ";
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << der_altura[i] << " ";
		cout <<endl;
        for (int i = 0; i < n; i++){
            int i_index = izq_altura[i];
            int d_index = der_altura[i];
            if(resultado<d_index + i_index) pos=i;
            resultado = max(resultado, d_index + i_index);
	}
	return resultado;
}

int main()
{       int pos;
//	int altura[]={ 6, 2, 5, 7, 7, 1, 6 };
        int altura[]={ 6, 2, 5, 7, 8, 1, 6 };
//       int altura[]={ 1, 7, 2, 7, 3, 4, 3, 2, 1, 7, 2, 1, 7 ,3};
 //     int altura[]={ 2, 1, 6, 1, 3};
  //    int altura[]={ 6, 2, 5, 4, 5, 1, 6 };
 //     int altura[]={1, 3, 6, 4};
//	int altura[]={ 2, 5, 7, 7, 1 };
        int N = sizeof(altura)/sizeof(altura[0]);

	cout <<"Altura: "<<endl<< buscabajos(altura, N,pos) << endl;
	cout << "Posicion:"<<pos;
        return 0;
}