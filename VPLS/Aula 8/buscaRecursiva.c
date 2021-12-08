#include <stdio.h>
int inputValues(int *pn,int *pt);
int buscar(int v[], int n,int t,int max);
int main(){
    int n=0, t=0,result;
    scanf("%d",&t); 
    scanf("%d",&n);
    result =inputValues(&n,&t);
    printf("%d", result);
    return 0;
}

    
int inputValues(int *pn, int *pt){
    int vetor[*pn],result=0;
    for (int i = 0; i < *pn; i++)
    {
        scanf("%d",&vetor[i]);
    
    } 
    result = buscar(vetor,0,*pt,*pn);
    return result;
}
int buscar (int v[], int n, int t,int max){

    if (v[n]==t)
    {
        return n;
    }else if (n>max)
    {
        return -1;
    }
    else{
    return buscar(v,n+1,t,max);
    }
}