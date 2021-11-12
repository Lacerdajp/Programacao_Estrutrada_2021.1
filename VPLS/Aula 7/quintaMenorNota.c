#include <stdio.h>
#include <string.h>
int main()
{
    int n = 0, notas[100], posicao[100], x = 0, pos = 0, f = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &notas[i]);
    }
    for (int i = 0; i <= 10; i++)
    {
        posicao[i] = 0;
        pos = 0;
        for (int z = 0; z < n; z++)
        {
            if (notas[z] == i)
            {
                x = notas[z];
            }
        }
        for (int y = 0; y < x; y++)
        {
            if (notas[y] == f)
            {
                pos--;
            }

            if (x > notas[y])
            {
                f = notas[y];
                pos++;
            }
        }

        printf("%d ", pos);
        posicao[pos] = x;
    }

    return 0;
}