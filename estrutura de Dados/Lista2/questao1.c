#include<stdio.h>
#include<../../libsJPLS/progressao.h>
#include<../../libsJPLS/vetores.h>
int main(){
    int n =0,k=0;
    int v[1000];
    scanf("%d",&n);
    *v=incluir_vetorNumber(*v,n);
    k=testa_PA(n,*v);
    printf("%d",k);
    return 0;

}