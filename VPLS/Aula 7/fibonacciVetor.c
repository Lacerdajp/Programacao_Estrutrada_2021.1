#include <stdio.h>
int main()
{
    int casos, fibonacci[60], n = 0;
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    scanf("%d", &casos);
    for (int i = 0; i < casos; i++)
    {
        scanf("%d", &n);
        for (int i = 2; i <= n; i++)
        {
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }
        printf("Fib(%d)= %d\n", n, fibonacci[n]);
    }
    return 0;
}