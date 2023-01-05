#include <stdio.h>
int main()
{
    double temp;
    printf("Digite uma temperatura: ");
    scanf("%lf", &temp);
    printf("A temperatura e :\n%08.3lf", temp);

    return 0;
}