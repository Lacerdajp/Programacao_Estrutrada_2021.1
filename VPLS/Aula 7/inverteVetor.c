#include <stdio.h>
#include <string.h>
int main()
{
    int n = 0, v = 0, var = 0;
    int x[100];
    scanf("%d\n", &n);
    var = n;
    while (n != 0)
    {
        scanf("%d", &v);
        x[n] = v;
        n--;
    }
    for (int i = 1; i <= var; i++)
    {
        printf("%d ", x[i]);
    }

    return 0;
}