#include <stdio.h>
#include <string.h>
int main()
{
    int n = 0, x = 0, notas[100], freq[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        notas[i] = x;
    }
    for (int i = 0; i <= 10; i++)
    {
        int z = 0;
        freq[i] = 0;
        for (; z < n; z++)
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