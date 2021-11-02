#include<stdio.h>
int main(){
    // int n1=0,n2=0,n3=0,n4=0,n5=0;
    int n=0,nmaior=0,posicao=0;
    printf("Digite 5 numeros\n");
    for (int i = 0; i < 5; i++)
    { 
      
        scanf("%d",&n);
        if (n>nmaior)
        {
            nmaior=n;
            posicao=i+1;
        }
        
    }
    printf("O maior numero e %d e a posicao %d ",nmaior,posicao);
    return 0;
}