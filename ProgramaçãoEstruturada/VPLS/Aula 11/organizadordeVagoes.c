#include<stdio.h>
#include<stdint.h>
int casos(int n);
int inputOrdem(int x);
int organizador (int v[],int x);
int main(){
    int n=0;
    scanf("%d",&n);
    casos(n);
    return 0;
}
int casos(int n){
    int x=0;
for (int i = 0; i < n; i++)
{
    scanf("%d",&x);
    inputOrdem(x);   
  
}
}
int inputOrdem(int x){
   int vetor[x];
    for (int i = 0; i < x; i++)
    {
        scanf("%d",&vetor[i]);
    }
    organizador(vetor,x);
}
int organizador(int v[], int x){
    int temp=0,count=0;

    for (int i = 0; i < x-1; i++){
    for (int i = 0; i < x-1; i++)
    {
        if (v[i]>v[i+1])
        {
           temp=v[i];
           v[i]=v[i+1];
           v[i+1]=temp;
           count++;
        }
        
    }}
    printf("Optimal train swapping takes %d swaps.\n",count);
}