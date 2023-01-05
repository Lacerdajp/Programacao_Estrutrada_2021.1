#include <stdio.h>
int main(){

    int n=0,x=0,count=0;
    do
    {
        printf("Digite o valor de entradas: ");
        scanf("%d",&n);
    } while (n<=0&&n>10);
    for (int i = 0; i < n; i++)
    {
        do
        {
            printf("Digite o valor de : ");
            scanf("%d",&x);
        } while (x>=100||x<=0);
        while (x!=1)
        {
            if (x%2!=0)
            {
               x=(x*3)+1;
            }else{
                 x=x/2;
            }
            count++;
        
        }
         printf("O numero de vezes  que foi rodado e : %d\n",count);  
         count=0;    
    }
    
    
    
    return 0;
}