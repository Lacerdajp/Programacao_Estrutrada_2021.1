#include<stdio.h>
#include<string.h>
#define TAMANHO 12
struct string
{
    char nome[100];
};typedef struct string String;

void inserirMes(String mes[]){
    
    strcpy(mes[0].nome,"Janeiro"); 
    strcpy(mes[1].nome,"Fevereiro");
    strcpy(mes[2].nome,"Marco");
    strcpy(mes[3].nome,"Abril");
    strcpy(mes[4].nome,"Maio");
    strcpy(mes[5].nome,"Junho");
   strcpy( mes[6].nome,"Julho");
    strcpy(mes[7].nome,"Agosto");
    strcpy(mes[8].nome,"Setembro");
    strcpy(mes[9].nome,"Outubro");
    strcpy(mes[10].nome,"Novembro");
    strcpy(mes[11].nome,"Dezembro");   
}
void inserirSalario(double salario[],String mes[]){
    printf("Insira os valores: \n");
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%s = ",mes[i].nome);
        scanf("%lf",&salario[i]);
    }
    
}
double calculoAnual(double salario[]){
    double soma=0;
    for (int i = 0; i < TAMANHO; i++)
    {
        soma=soma+salario[i];
    }
    return soma;
    
}
void imprimir(String mes[],double salario[],double salarioAnual){
    printf("Mes     Valor- R$\n");
    for (int i = 0; i < TAMANHO; i++)
    {
         printf("%s = %.2lf \n",mes[i].nome,salario[i]);
    }
    printf("Salario Anual= %.2lf",salarioAnual);
    
}

int main(){
    String mes[TAMANHO];
    double salario[TAMANHO];
    double salarioAnual=0;
    inserirMes(mes);
    inserirSalario(salario,mes);
    salarioAnual=calculoAnual(salario);
    imprimir(mes,salario,salarioAnual);
    
}