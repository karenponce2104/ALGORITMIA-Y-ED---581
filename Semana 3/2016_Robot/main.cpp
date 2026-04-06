#include <iostream>
#define N 3
#define M 4 //el segundo siempre es necesario para definir las matrices
using namespace std;
int robot(int x, int y, int matriz[][M]) {
    int derecha=-9999, abajo=-99999;
    //cout<<"Coordenadas: "<< x<<" "<<y <<endl;
    if (x==N-1 and y == M-1) return matriz[x][y];
    if (y+1<M)derecha = robot(x,y+1,matriz);
    if (x+1<N)abajo = robot(x+1,y,matriz);

    //cout<<derecha<<" "<<abajo<<endl;
        if (derecha> abajo) return derecha + matriz[x][y];//derecha es el valor
        return abajo + matriz[x][y];
}
int main() {
    int matriz[][M] {
            {5, 6, 4, 3},
          {2,1,10,5},
          {100,5,2,7}
        };

    cout<<"El valor es: "<<robot(0,0,matriz);
    return 0;
}
