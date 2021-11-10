#include <stdio.h>
#define MAX 1000
int main()
{
    int n = 0, menor = 100, posicao = MAX;
    int x[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
        if (menor >= x[i])
        {
            menor = x[i];
            posicao = i;
        };
    }
    printf("Menor valor: %d\nPosicao: %d", menor, posicao);

    return 0;
}