#include<stdio.h>
#include <stdlib.h>
struct lista
{
    char* nome;
    float nota;
    struct lista *prox;
};
typedef struct lista Lista;
Lista* new_lst(){
    return NULL;
}
Lista* inserir_lst(Lista* lst, char* nome, float nota){
    Lista* novoAluno= (Lista*) malloc(sizeof(Lista));
    novoAluno->nome=nome;
    novoAluno->nota=nota;  
    novoAluno->prox=lst;
    return novoAluno;
}
void imprimir_total(Lista*lst){
    Lista*p;
    printf("Alunos:\nNome    |  Nota\n");
    for ( p = lst; p!=NULL; p=p->prox)
    {
        printf("%s  | %.2f\n",p->nome,p->nota);
    }
}
Lista* lst_aprovados(Lista*lst){
    Lista* ant =NULL;
    Lista* p=lst;
    while (p!=NULL && p->nota>=5)
     {
        ant =p;
        p=p->prox;
    }
    if (p==NULL){
        return lst;
    }
    if(ant==NULL){

        lst =lst_aprovados(p->prox);
    }
    else
    {
        ant->prox=lst_aprovados(p->prox);
    }
    free(p);
    return lst;
    
}
int aprovados(Lista*l){
    Lista* p;
    int num=0;
    for ( p = l; p!=NULL;p=p->prox)
    {
        if (p->nota>=5)
        {
            num++;
        }
        
    }
    return num;
    
}
int main(){
    Lista* lstAlunos;
    Lista *lstAprovados;
    int numeroAprovados=0;
    lstAlunos=new_lst();
    lstAprovados=new_lst();

    //Inserir Total de Alunos;
    lstAlunos=inserir_lst(lstAlunos,"Alice Almeida",9.5);
    lstAlunos=inserir_lst(lstAlunos,"Bianca Santana",5.1);
     lstAlunos=inserir_lst(lstAlunos,"Dirceu Silvestre",4.0);
     lstAlunos=inserir_lst(lstAlunos,"Douglas Schereer",3.0);
     lstAlunos=inserir_lst(lstAlunos,"Joao Pedro Lacerda",10.0);
     lstAlunos=inserir_lst(lstAlunos,"Jorge Durte",5.0);
     lstAlunos=inserir_lst(lstAlunos,"Thiago Medeiros",4.9);

    imprimir_total(lstAlunos);

    lstAprovados=lst_aprovados(lstAlunos);
    imprimir_total(lstAprovados);

    numeroAprovados=aprovados(lstAlunos);
    printf("Quantidade de Aprovados: %d",numeroAprovados);
}