#include <stdio.h>
int main()
{
    long long int x = 0, maiorpri = 2, primo = 2;
    printf("Digite um valor x\n");
    scanf("%lld", &x);
    while (x != 1)
    {
        if (x % primo == 0)
        {
            while (x % primo == 0)
            {
                x = x / primo;
            }
            maiorpri = primo;
        }
        primo++;
    }

    printf("%lld", maiorpri);

    return 0;
}