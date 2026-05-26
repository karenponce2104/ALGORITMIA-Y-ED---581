#include <iostream>
using namespace std;

int cuentaceros(int *arreglo, int ini, int fin, int cont) {
    if (ini>fin) return cont;
    int med = (ini+fin)/2;
    if (arreglo[med]==0)
        return cuentaceros(arreglo, ini, med-1, cont+fin-med+1) ;
    else
        return cuentaceros(arreglo, med+1, fin, cont) ;

}

int main() {
    int entrada[]={1,1,1,0,0,0};
    int n= sizeof(entrada)/sizeof(entrada[0]);
    cout<<cuentaceros(entrada, 0, n-1, 0);
    return 0;
}