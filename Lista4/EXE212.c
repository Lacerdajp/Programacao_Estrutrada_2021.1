#include <stdio.h>
int main()
{
    char cadeia1[21];
    char cadeia2[21];
    printf("Digite algo: \n");
    gets(cadeia1);
    printf("Digite algo: \n");
    gets(cadeia2);
    printf("%s,%s", cadeia1, cadeia2);

    return 0;
}