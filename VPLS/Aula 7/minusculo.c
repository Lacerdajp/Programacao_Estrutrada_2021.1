#include <stdio.h>
#include <string.h>
int main()
{
    char nome[200];
    scanf("%s", nome);
    for (int i = 0; i < strlen(nome); i++)
    {
        if (nome[i] >= 'A' && nome[i] <= 'Z')
        {
            nome[i] = (nome[i] - 'A') + 'a';
        }
    }
    printf("%s", nome);

    return 0;
}