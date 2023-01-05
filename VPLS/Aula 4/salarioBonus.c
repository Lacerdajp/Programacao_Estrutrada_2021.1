#include <stdio.h>
int main()
{
    char nome[61];
    double salarioFixo = 0;
    double vendas = 0;
    double total = 0;
    printf("Digite o nome do vendedor: \n");
    scanf("%s", nome);
    printf("Digite o salario fixo do vendedor: \n");
    scanf("%lf", &salarioFixo);
    printf("Digite o numero de vendas: \n");
    scanf("%lf", &vendas);

    total = salarioFixo + ((vendas * 15) / 100);
    printf("%s \n %.2lf   \n %.2lf  \n TOTAL = R$  %.2lf", nome, salarioFixo, vendas, total);

    return 0;
}