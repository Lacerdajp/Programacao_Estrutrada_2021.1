#include<stdio.h>
#include<string.h>
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
    for (int i = 0; i < 12; i++)
    {
        printf("%s = ",mes[i].nome);
        scanf("%lf",salario[i]);
    }
    
}

int main(){
    String mes[12];
    double salario[12];
    inserirMes(mes);
    inserirSalario(salario,mes);

    
    
}