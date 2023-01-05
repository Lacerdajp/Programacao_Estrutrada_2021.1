#include <stdio.h>
int casos(int *pn);
int inputValues(int *pn);
int soma(int v[], int n);
int main(){

    int t=0;
    scanf("%d",&t);
    casos(&t);
    return 0;
}
int casos(int *pn){
    int n=0,soma=0;
    for (int i = 0; i < *pn; i++)
    {
        scanf("%d",&n);
        soma= inputValues(&n);
        printf("%d \n",soma);
    }
}
int inputValues(int *pn){
    int vetor[*pn],result=0;
    for (int i = 1; i <= *pn; i++)
    {
        scanf("%d",&vetor[i]);
    
    } 
    result = soma(vetor,*pn);
    return result;
}
int soma (int v[], int n){

    if (n==1)
    {
        return v[n];
    }else
    return v[n]+soma(v,n-1);
    
}