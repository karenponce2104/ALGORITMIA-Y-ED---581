/*
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 26 de agosto de 2024, 10:40 AM
 */

#include <iostream>
#include <cmath>
#define MAX 20


using namespace std;

void cargabin(int num,int n,int uni,int cromo[]){
    int res,i=0;
    for(int j=0;j<n;j++) cromo[j]=0;
    while(num>0){
        res = num%uni;
        num = num/uni;
        cromo[i] = res;
        i++;
    }
}
void calculamaxmin(int m,int *camaux,int &min,int &max){
    for(int i=0;i<m;i++){
        if(camaux[i]<min)min=camaux[i];
        if(camaux[i]>max)max=camaux[i];
    }
}

int main(int argc, char** argv) {
    int paq[]={50,20,30,50,20};
    int cam[]={25,50,100,100};
    int n=5,m=4,uni=m+1,min,max,dif=9999999;
    int cromo[n],camaux[m];
    int opcion=(int)pow(uni,n);
    int flag,mcomb;
    int solu[MAX];
    int cont=0;

    for(int i=0;i<opcion;i++){
        flag=0;
        min=999999;
        max=0;
        cargabin(i,n,uni,cromo);
        for(int k=0;k<m;k++)
            camaux[k]=cam[k];
        for(int j=0;j<n;j++){
            camaux[cromo[j]-1]-=paq[j];
            if(cromo[j]==0 or camaux[cromo[j]-1]<0){
                flag=1;
                break;
            }
        }
        calculamaxmin(m,camaux,min,max);
        if(flag==0 and dif>max-min and min>=0){
            mcomb=i;
            dif=max-min;
        }
    }
    cargabin(mcomb,n,uni,cromo);
    cout <<"Mejor solucion:"<<endl;
    for(int i=0;i<n;i++)
        cout<< cromo[i] << " ";
    cout << endl << "Diferencia maxima: "<< dif;
    
    return 0;
}
