#include <stdio.h>
int main()
{
    int x = 0, y = 0, soma = 0;
    printf("Digite o valor de x: \n ");
    scanf("%d", &x);
    printf("Digite o valor de y:\n");
    scanf("%d", &y);
    while (x != y)
    {
        if (x % 13 != 0)
        {
            soma = soma + x;
        }
        if (y > x)
        {
            x++;
        }
        else if (y < x)
        {
            x--;
        }
    }
    if (x % 13 != 0)
    {
        soma = soma + x;
    }
    printf("o valor da soma e %d", soma);

    return 0;
}