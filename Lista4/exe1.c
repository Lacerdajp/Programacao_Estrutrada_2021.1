#include <stdio.h>
int main()
{
    char firstname[30];
    char completename[61];
    printf("Digite seu primeiro nome:\n");
    scanf("%s", &firstname);
    getchar();
    printf("Digite seu nome completo: \n");
    fgets(completename, 60, stdin);
    printf("Primeiro Nome: ");
    puts(firstname);
    printf("Nome Completo: %s", completename);

    return 0;
}