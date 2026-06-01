#include <climits>
#include <iostream>
#define N 6
#define G 9999
using namespace std;
void merge(int *arr, int ini, int med, int fin) {
    int largo1 = med-ini+1;
    int largo2 = fin-med;
    int aux1[largo1+1];
    int aux2[largo2+1];

    for (int i=ini; i<=med; i++)
        aux1[i-ini] = arr[i]; 
    aux1[largo1]=INT_MAX;
    for (int i=med+1; i<=fin; i++) {
        aux2[i-med-1] = arr[i];
    }
    aux2[largo2]=INT_MAX;

    int i1=0, i2=0;
    for (int i=ini; i<=fin; i++) {
        if (aux1[i1] < aux2[i2]) {
            arr[i]=aux1[i1++];
        }
        else {
            arr[i]=aux2[i2++];
        }
    }
}
void buscasolo(int *arr, int ini, int fin) {
    if (ini>fin) return;
    if (ini==fin) {
        cout<<"El solitario es: "<<arr[ini]<<endl;
        return;
    }
    int med=(ini+fin)/2;
    if (med%2==0) {
        if (arr[med]==arr[med+1])
            buscasolo(arr, med+2, fin);
        else
            buscasolo(arr, ini, med);
    }
    else {
        if (arr[med]==arr[med-1])
            buscasolo(arr, med+1, fin);
        else
            buscasolo(arr,ini, med-1);
    }
}

void muestra(int canarios[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout<<canarios[i][j]<<" ";
        }
        cout<<endl;
    }
}
void verificasolo(int canarios[][N]) {
    for (int i = 0; i < N; i++)
        if (canarios[i][N-1]==G)
            buscasolo(canarios[i], 0, N-2);
        else
            cout<<"No faltan canarios"<<endl;
}
void mergesort(int *arr, int ini, int fin) {
    if (ini==fin) return;
    int med = (ini+fin)/2;
    mergesort(arr, ini, med);
    mergesort(arr, med+1, fin);
    merge(arr, ini, med, fin);
}

void ordenamatriz(int canarios[][N]) {
    for (int i = 0; i < N; i++)
        mergesort(canarios[i], 0, N-1);

}
int main() {
    int canarios[N][N] {
      {G,3, 7, 2,2,7},
        {5, G, 3, 1, 5, 3},
        {7,7,3,6,6,3},
        {7,4,G,7,2,4},
        {5,1,2,5,1,2},
        {6,G,7,4,7,4},
    };
    ordenamatriz( canarios);
    muestra(canarios);
    verificasolo(canarios);
    return 0;
}