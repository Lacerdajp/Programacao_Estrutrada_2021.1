#include <stdio.h>
int main()
{
    int a = 0, b = 0, c = 0, z = 0;
    printf("Digite 3 numeros inteiros\n");
    scanf("%d %d %d", &a, &b, &c);
    z = (a <= b < c);
    printf("%d<=%d<=%d?\n %d", a, b, c, z);
    return 0;
}