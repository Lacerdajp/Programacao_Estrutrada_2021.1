#include <stdio.h>
int main(){
    int  n=0, x=-1,num1=0,num2=0;
    int fib[46];
    fib[0]=0;
    fib[1]=1;
    for (int i = 2; i<46; i++)
        {
            fib[i]=fib[i-1]+fib[i-2];
        }
            
    do{
        printf("Digite o valor de entradas: ");
        scanf("%d",&n);
    }   while (n<=0||n>10);
    for (int z = 0; z < n; z++)
    {
        printf("Digite o valor a ser analisado: ");
        do {scanf("%d",&x);}
        while (x<0||x>=1073741824);
       num1=0,num2=0;
       if (fib[num1]+fib[num2]==x)
            {
                printf("S\n");
            }
        while (fib[num1]+fib[num2]!=x)
        {
            if (fib[num2]>x)
            {
                printf("N\n");
                break;
            }
            if (fib[num1]>x)
            {
                num2++;
                num1=num2;
            }else{
                num1++;
            }
            if (fib[num1]+fib[num2]==x)
            {
                printf("S\n");
                break;
            }
        }
        }
        
    return 0;
}