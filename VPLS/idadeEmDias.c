#include <stdio.h>
int main()
{
    int idade = 0;
    int dias = 0, meses = 0, anos = 0;
    printf("Quantos dias voce tem de vida?\n");
    scanf("%d", &idade);
    anos = idade / 365;
    meses = (idade % 365) / 30;
    dias = (idade % 365) % 30;
    printf("sua idade em dias : %d\nVoce viveu por: %d ano(s), %d mes(es), %d dia(s)", idade, anos, meses, dias);
    return 0;
}