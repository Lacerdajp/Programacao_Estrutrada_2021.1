#include <stdio.h>
int main()
{
    char name1[11];
    char name2[11];
    char name3[11];
    printf("Digite o nome 1: \n");
    scanf("%s", &name1);
    printf("Digite o nome 2: \n");
    scanf("%s", &name2);
    printf("Digite o nome 3: \n");
    scanf("%s", &name3);
    printf("%20s\n%20s\n%20s", name1, name2, name3);

    return 0;
}