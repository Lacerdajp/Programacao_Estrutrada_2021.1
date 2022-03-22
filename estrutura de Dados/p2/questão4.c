#include<stdio.h>

struct lista //cria a struct lista
{   
    int val; //cria a variavel valor onde sera armazenado o valor do elemento da lista
    struct lista* ant;  //cria o alemento antecessor
    struct lista* prox; //cria o proximo elemento

};
typedef struct lista Lista; //define o nome da struct lista como Lista
Lista* new_lst(){   //cria a função de nova lista que retorna um valor do tipo lista
    return NULL;    //retorna nulo
}
Lista* insert_lst(Lista* lst, int val){ //cria uma função parainserir valores na lista, onde recebe como parametro uma variavel Lista e uma variavel in, e sera retornado uma Lista
     Lista* new=(Lista*) malloc(sizeof(Lista)); //cria um novo elemento do tipo que será alocada na memoria
    new->val=val;   // o valor int passado por parametro é armazenado no valor do elemento
    new->ant=NULL;  //o elemento anterior armazena nulo
    new->prox=lst;  //armazena a lst no proximo elemento
    if (lst!=NULL)  // verifica se lst é nula
    {
        lst->ant=new;     //o anterior a lst passada no parametro  é o novo elemento
    }
    return new;    //retorna a lista com o novo elemento
}
Lista* print_lst(Lista* lst){
    Lista* pont;
    for ( pont = lst; pont!= NULL; pont=pont->prox)
    {
        printf("valor: %d\n", pont->val);
    }
    
}
Lista* remove_lst(Lista*lst,int val ){
    Lista* p;
    for ( p = lst; p!=NULL; p=p->prox)
    {
        if (p->val==val)
        {
            if (lst==p)
            {
                lst=p->prox;
            }
            else
            {
                p->ant->prox=p->prox;
            }
            if (p->prox!=NULL)
            {
                p->prox->ant=p->ant;
            }
        }
        
    }
    free(p);
    return lst;
    
}

int main(){
    Lista* lst;
    lst=new_lst();
    lst=insert_lst(lst,60);
    lst=insert_lst(lst,50);
    lst=insert_lst(lst,20);
    lst=insert_lst(lst,60);
    lst=insert_lst(lst,30);
    lst=insert_lst(lst,60);
    print_lst(lst);
    lst=remove_lst(lst,60);
    print_lst(lst);
    free(lst);
    return 0;
}
