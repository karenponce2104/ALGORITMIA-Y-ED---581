#include <iostream>
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
    int paq[]={1,2,1,12,4};
    int peso=15;
    int n=sizeof(paq)/sizeof(paq[0]);
    int comb= (int)pow(2,n);
    int cromo[n];

    for (int i=0;i<comb;i++) {
        int pparcial=0;
        cargabin(i,n,cromo);
        for (int j=0;j<n;j++)
            pparcial+=cromo[j]*paq[j];
        if (pparcial==peso) {
            cout << "Encontre la solucion"<<endl;
            cout << "Decimal: "<<i<<endl;
            for (int j=0;j<n;j++)
                cout << cromo[j]<<" ";
            cout << endl;
        }
    }


    return 0;
}