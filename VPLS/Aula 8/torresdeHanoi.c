#include <stdio.h>
int movimentos(int disc);
int main(){
    int discos=0,t=0;
    scanf("%d",&discos);

    t= movimentos(discos);

    return 0;
}
int movimentos(int disc){
    if(disc<2){
        return disc;
    }else{
        return (2*movimentos(disc-1))+1;
    }
}
