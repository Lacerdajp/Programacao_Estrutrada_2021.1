#include <stdio.h>
int han(int discos,int torreInicial,int torreFinal,int torreMeio);
int main(){
    int discos=0,t=0;
    scanf("%d",&discos);
    han(discos,1,3,2);
    return 0;
}
int han(int discos, int torreInicio,int torreFinal,int torreMeio){
    if (discos==1){
        printf("\n%d %d",torreInicio ,torreFinal);
        return 0;
    }
    han(discos-1,torreInicio,torreMeio,torreFinal);
    printf("\n %d %d",torreInicio,torreFinal);
    han(discos-1,torreMeio,torreFinal,torreInicio);
}
