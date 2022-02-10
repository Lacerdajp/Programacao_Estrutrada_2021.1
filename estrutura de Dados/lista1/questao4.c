#include"../../../LibsJPLS/formulas.h"
int main(){
    int n=0,k=0,r=0;
    scanf("%d %d", &n,&k);
    r=CoeficienteBinomial(n,k);
    printf("o resultado e %d",r);
    return 0;

}