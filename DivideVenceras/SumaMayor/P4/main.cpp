#include <iostream>
#include <climits>

using namespace std;

int mimax(int a,int b) {
    if (a<b) return b;
    else return a;
}


int sumamedios(int *arr,int ini,int med,int fin) {
    int sum=0;
    int maxizq=INT_MIN;
    for (int i=med;i>=ini;i--) {
        sum+=arr[i];
        if (sum>maxizq)
            maxizq=sum;
    }
    sum=0;
    int maxder=INT_MIN;
    for (int i=med+1;i<=fin;i++) {
        sum+=arr[i];
        if (sum>maxder)
            maxder=sum;
    }
    return mimax(mimax(maxizq,maxder),maxizq+maxder);
}

int sumamax(int *arr,int ini,int fin) {

    if (ini == fin) return arr[ini];
    int med=(ini+fin)/2;
    int izq=sumamax(arr,ini,med);
    int der=sumamax(arr,med+1,fin);
    int smed=sumamedios(arr,ini,med,fin);

    return mimax(mimax(izq,der),smed);
}


int main() {

    int arr[]={-2,-5,6,-2,-3,1,5,-6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << sumamax(arr,0,n-1) << endl;

    return 0;
}