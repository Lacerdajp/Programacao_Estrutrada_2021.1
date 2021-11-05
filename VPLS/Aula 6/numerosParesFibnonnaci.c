#include <stdio.h>
int main()
{
    int x = 0, termo2 = 2, termo1 = 1, soma = 0, var = 0;
    printf("Digite um numero ");
    scanf("%d", &x);
    while (termo2 <= x)
    {
        if (termo2 % 2 == 0)
        {
            soma = soma + termo2;
        }
        var = termo1;
        termo1 = termo2;
        termo2 = var + termo2;
    }

    printf("%d", soma);

    return 0;
}