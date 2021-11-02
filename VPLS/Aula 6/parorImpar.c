#include <stdio.h>
int main()
{
    int number = 0;
    printf("Digite um numero:\n");
    scanf("%d", &number);
    if (number % 2 == 0)
    {
        printf("par");
    }
    else
    {
        printf("impar");
    };

    return 0;
}