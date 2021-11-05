#include <stdio.h>
int main()
{
    int x = 0, soma = 0;
    printf("Digite um numero\n");
    scanf("%d", &x);
    for (int i = 3; i < x; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            soma = soma + i;
        }
    }
    printf("soma e %d", soma);

    return 0;
}