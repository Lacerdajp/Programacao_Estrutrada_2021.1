#include <stdio.h>
#include <string.h>
int main()
{
    int n = 0, notas[100], freq[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &notas[i]);
    }
    for (int i = 0; i <= 10; i++)
    {

        freq[i] = 0;
        for (int z = 0; z < n; z++)
        {

            if (i == notas[z])
            {
                freq[i] = freq[i] + 1;
            }
        }
        printf("%d ", freq[i]);
    }

    return 0;
}