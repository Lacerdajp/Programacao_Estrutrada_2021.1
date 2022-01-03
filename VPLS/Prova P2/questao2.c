#include<stdio.h>

struct DATA {
    int dia;
    int mes;
    int ano;
};

struct FUNCIONARIO {
    int matricula;
    struct DATA contratacao;
    float salario;
};
int difAnos(int diaContrat,int mesContrat,int anoContrat,int diaAtual,int mesAtual,int anoAtual){
    int anos;
    anos=anoAtual-anoContrat;
    if ((mesAtual==mesContrat&&diaAtual<diaContrat)||(mesAtual<mesContrat)){
        anos--;
    }
    return anos;
}
float aumentoSalario(float salarioMin,float salario,int nAnos){
        
          
        if (salarioMin<=salario&&salario<(salarioMin*3))
        {
            salario=((salario*15)/100)+salario;
 
        }else if ((salarioMin*3)<=salario&&salario<=(salarioMin*5))
        {
            salario=((salario*12.5)/100)+salario;
        }else if ((salarioMin*5)<salario&&salario<=(salarioMin*10))
        {
             salario=((salario*10)/100)+salario;
        }else if ((salarioMin*10)<salario)
        {
            salario=((salario*5)/100)+salario;
        }for (int i = 0; i < nAnos/10; i++)
        {
            salario=((salario*10)/100)+salario;
        }   
    return salario;

}
float porcentagem(float salarioMin,float salario,int nAnos){
     float porcentagem=0;
     nAnos=nAnos/10;
       
        if (salarioMin<=salario&&salario<(3.0*salarioMin))
        {
            porcentagem=porcentagem+15.0;
        }else if ((salarioMin*3.0)<=salario&&salario<=(5.0*salarioMin))
        {
            porcentagem=porcentagem+12.5;
        }else if ((salarioMin*5.00)<salario&&salario<(10.0*salarioMin))
        {
            porcentagem=porcentagem+10.00;
        }else if ((salarioMin*10.00)<=salario)
        {
            porcentagem=porcentagem+5;
        } for (int i = 0; i < nAnos; i++)
        {
        
        porcentagem=((porcentagem*10)/100)+porcentagem +10;
        
        }
    return porcentagem;
}

int main(void) {
    char nomeArquivo[15];
    int nAnos;
    float aumento,salarioNovo;
    float salarioMin;
    struct DATA atual;
    struct FUNCIONARIO funcionario;
    FILE*arquivo;
    scanf("%s %d %d %d %f", nomeArquivo,&atual.dia,&atual.mes,&atual.ano,&salarioMin);
    arquivo=fopen(nomeArquivo,"rb");
    if (arquivo == NULL)
    perror("Erro ao abrir o arquivo.\n");
    else
     printf("Arquivo aberto para leitura.\n");
     for (int i = 0; !feof(arquivo); i++){
   fscanf(arquivo,"%d %d %d %d %f",&funcionario.matricula, &funcionario.contratacao.dia,&funcionario.contratacao.mes,&funcionario.contratacao.ano,&funcionario.salario);
     nAnos=difAnos(funcionario.contratacao.dia,funcionario.contratacao.mes,funcionario.contratacao.ano,atual.dia,atual.mes,atual.ano);
     salarioNovo=aumentoSalario(salarioMin,funcionario.salario,nAnos);
     aumento= porcentagem(salarioMin,funcionario.salario,nAnos);
     printf("%d R$ %.2f R$ %.2f %.1f%%\n",funcionario.matricula,funcionario.salario,salarioNovo,aumento);
     }
     fclose(arquivo);
	return 0;
}