#include<stdio.h>
#include<stdlib.h>

struct arv
{
    float info;
    struct arv* esq;
    struct arv* dir;
};
typedef struct arv Arv;
Arv* criar_arvore(){
    return NULL;
}
Arv* inserir_arv(Arv*a, float val){
    if (a==NULL)
    {
        a=(Arv*) malloc(sizeof(Arv));
        a->info=val;
        a->dir=a->esq=NULL;
    }
    else if (val>a->info)
    {
        a->dir=inserir_arv(a->dir,val);
    }
    
    else if (val<a->info)
    {
        a->esq=inserir_arv(a->esq,val);
    }
}
Arv* buscar_arv
int main(){
    Arv* arvore;

    return 0;
}