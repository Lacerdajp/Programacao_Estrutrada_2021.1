#include <stdio.h>
#include <string.h>
int main()
{
    int n = 0, x[1000], var = 0;
    int v = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
        var = 0;
        for (int z = 0; z < i; z++)
        {
            if (x[i] == x[z])
            {
                var++;
            }
        }
        if (var != 0)
        {
            i--;
        }
        else
        {
            printf("%d ", x[i]);
        }
    }

    return 0;
}