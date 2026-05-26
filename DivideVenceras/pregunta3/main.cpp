#include <iostream>
using namespace std;
int buscarotado(int *arreglo, int ini, int fin) {
    if (ini==fin)
        return arreglo[ini];
    int med = (ini + fin)/2;
    if (arreglo[fin]>arreglo[ini])
        return arreglo[ini];
    if (arreglo[med] < arreglo[fin])
        return buscarotado(arreglo, ini, med);
    else
        return buscarotado(arreglo, med+1, fin);
}

int main() {
    int arreglo[]={5,4,1,2,3};
    int n=sizeof(arreglo)/sizeof(arreglo[0]);
    cout<<buscarotado(arreglo,0,n-1);
    return 0;
}