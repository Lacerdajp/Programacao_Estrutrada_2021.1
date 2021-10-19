#include <stdio.h>
int main()
{
    const int kmL = 12;
    int tempo = 0;
    int velocidade = 0;
    double litros = 0;
    printf("Quanto tempo a viagem vai durar? (em horas)\n");
    scanf("%d", &tempo);
    printf("Qual e a velocidade media durante a viagem? (em Km/h)\n");
    scanf("%d", &velocidade);
    litros = (double)(velocidade * tempo) / kmL;
    printf("Voce vai gastar: %.3lf", litros);
    return 0;
}