#include<stdio.h>
#include "../../../LibsJPLS/progressao.h"
#include "../../../LibsJPLS/vetores.h"
int main(){
    int n =0,k=0;
    int v[1000];
    scanf("%d",&n);
    *v=incluir_vetorNumber(n,*v);
    testa_PA_sem_return(n,*v,&k);
    printf("%d",k);
    return 0;

}