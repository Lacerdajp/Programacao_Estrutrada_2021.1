#include <stdio.h>
int main()
{
    int a = 0, b = 0;
    int soma=0;
    printf("Digite o primeiro numero:\n");
    scanf("%d",&a);
    printf("Digite o segundo numero:\n");
    scanf("%d", &b);
    while (b!=a)
    {
        if (b>=a)
        {
            b--;
        }else if (b<=a)
        {
             b++;
        }
        if (a!=b)
        {
             if (b%2!=0)
        {
            soma=soma+b;
        };
        }
        
        
        
    }
    printf("a soma e : %d",soma);
    
    

    return 0;
}