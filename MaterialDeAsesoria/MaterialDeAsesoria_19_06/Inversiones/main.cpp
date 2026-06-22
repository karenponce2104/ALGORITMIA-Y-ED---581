#include <iostream>
// Desarrollado por Madison Obregon
using namespace std;

int merge(int *arr,int ini,int med,int fin) {
    int arrder[fin-med];
    int arrizq[med-ini+1];
    for (int i=ini;i<=med;i++) arrizq[i-ini]=arr[i];
    for (int i=med+1;i<=fin;i++) arrder[i-med-1]=arr[i];
    int nder=fin-med;
    int nizq=med-ini+1;
    int inv=0;
    int j=0,i=0,k=ini;
    while (i<nizq and j<nder) {
        if (arrizq[i]<arrder[j]) {
            arr[k++]=arrizq[i++];
        }
        else {
            arr[k++]=arrder[j++];
            inv+=nizq-i;
        }
    }
    while (i<nizq) arr[k++]=arrizq[i++];
    while (j<nder) arr[k++]=arrder[j++];
    return inv;
}

int calcularInversiones(int ini, int fin, int * arr) {
    int cont=0;
    if (ini>=fin) return cont;
    int med=(ini+fin)/2;
    int inv=0;
    //derecha
    inv+=calcularInversiones(med+1,fin,arr);
    //izquierda
    inv+=calcularInversiones(ini,med,arr);
    inv+=merge(arr,ini,med,fin);
    return inv;
}

int main() {
    int arr[] = {1, 4, 2, 5};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout << "Inversiones= "<< calcularInversiones( 0, n - 1,arr)<< endl;

    return 0;
}