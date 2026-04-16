#include <iostream>
#include <iomanip>
#define N 6
#define M 6
using namespace std;

void recorre(int terreno[6][6], int x,int y, int n, int m) {
    if (x>=n or y >=m) return;
    if (x==n-1 and y==m-1)
        cout<<terreno[x][y]<<" ";
    for (int i=y;i<m-1;i++) {
        cout << terreno[x][i] << " ";
    }
    for (int i=x;i<n-1;i++) {
        cout << terreno[i][m-1]<< " ";
    }
    for (int i=m-1; i>y;i--) {
        cout<<terreno[n-1][i] <<" ";
    }
    for (int i=n-1;i>x;i--) {
        cout<<terreno[i][y]<<" ";
    }
    recorre(terreno, x+1, y+1, n-1, m-1);
}

int main() {
    int terreno[N][M], cont=1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            terreno[i][j] = cont++;
    recorre(terreno,0, 0, 6, 6);
    return 0;
}