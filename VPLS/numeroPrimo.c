#include <stdio.h>
int main()
{
    int num = 0, res = 0;
    printf("Digite um numero \n");
    scanf("%d", &num);
    for (int i = 2; i <= num; i++)
    {
        if (num % i == 0)
        {
            res++;
        }
    }
    if (res == 1)
    {
        printf("primo");
    }
    else
    {
        printf("nao");
    }

    return 0;
}