x|x#include <iostream>
#include <cmath>
using namespace std;

void cargabin(int num,int n,int *cromo) {
    int res;
    for(int i=0;i<n;i++)cromo[i]=0;
    int i=0;
    while (num>0) {
        res=num%2;
        num=num/2;
        cromo[i]=res;
        i++;
    }
}

int main() {
    int paq[]={10,2,10,12,4};
    int peso=9,mpeso=0,mcromo=0;
    int n=sizeof(paq)/sizeof(paq[0]);
    int comb= (int)pow(2,n);
    int cromo[n];

    for (int i=0;i<comb;i++) {
        int pparcial=0;
        cargabin(i,n,cromo);
        for (int j=0;j<n;j++)
            pparcial+=cromo[j]*paq[j];
        if (peso>=pparcial and pparcial>mpeso) {
            mpeso=pparcial;
            cout << mpeso << endl;
            mcromo=i;
        }
    }
    cout << "La mejor solucion tiene un peso: "<<mpeso<<endl;
    cout << "La mejor combinacion es: "<<mcromo<<endl;

    return 0;
}