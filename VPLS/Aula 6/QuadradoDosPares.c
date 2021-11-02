#include <stdio.h>
int main(){
    int n=0;
    while (n<5||n>2000)
    {
        printf("Digite um valor: \n");
        scanf("%d",&n);
    }
    for (int i = 2; i <= n; i=i+2)
    {
        if (n%2!=0)
        { 
           n--;
        }
        
           int c=i*i;
           printf("%d ^ 2= %d \n",i,c);
    }
        
    
    
    


    return 0;
}