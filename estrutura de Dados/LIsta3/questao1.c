#include<stdio.h>
struct lista
{
    char* str;
    struct lista* prox;
};
typedef struct lista Lista;
Lista* new_lst(){
    return NULL;
}
Lista* lst_insere(Lista* lst,char* str){
    Lista* novo=(Lista*) malloc(sizeof(Lista));
    novo->str=str;
    novo->prox=lst;
    return novo;
}
void lst_imprime(Lista* lst){
    Lista* p;
    for ( p = lst;p!=NULL;p=p->prox)
    {
        printf("string = %s\n",p->str);
    }
   
}
Lista* lst_retirar(Lista*lst,char* str){
    Lista* ant =NULL;
    Lista* p=lst;
    while (p!=NULL && p->str!=str)
     {
        ant =p;
        p=p->prox;
    }
    if (p==NULL){
        return lst;
    }
    if(ant==NULL){

        lst =lst_retirar(p->prox,str);
    }
    else
    {
        ant->prox=lst_retirar(p->prox,str);
    }
    free(p);
    return lst;
    
}
int main(){
    Lista* lst;
    lst=new_lst();
    lst= lst_insere(lst,"Acre");
    lst= lst_insere(lst,"Rio de Janeiro");
    lst=lst_insere(lst,"Sao Paulo");
    lst=lst_insere(lst,"Recife");
    lst= lst_insere(lst,"Rio de Janeiro");
    lst_imprime(lst);
    lst=lst_retirar(lst,"Rio de Janeiro");
    printf("\n");
    lst_imprime(lst);
    return 0;
}
