#include<stdio.h>
#include <math.h>
int CoeficienteBinomial(int n, int k){
    int r=0;
    if ((k==0||n==k)&& n>=0)
    {
        r=1;
    }else if(n>k>0){
        r=CoeficienteBinomial(n-1,k)+CoeficienteBinomial(n-1,k-1);
    }else{
        printf("esse Binomio nao e valido");
    }
    return r;
} 
int main(){
    int n=0,k=0,r=0;
    scanf("%d %d", &n,&k);
    r=CoeficienteBinomial(n,k);
    printf("o resultado e %d",r);
    return 0;

}