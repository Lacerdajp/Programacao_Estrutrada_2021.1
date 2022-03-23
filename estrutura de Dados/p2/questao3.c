// incomplete

#include <stdio.h>
#include <stdlib.h>
struct pilha
{
    int valor;
    struct pilha *penultimo;
};
typedef struct pilha Pilha;
struct fila
{
    struct pilha *pa;
    struct pilha *pb;
};
typedef struct fila Fila;

Pilha *criar_pilha()
{
    return NULL;
}
Pilha *push_pilha(Pilha *p, int val)
{
    Pilha *pil = (Pilha *)malloc(sizeof(Pilha));
    pil->valor = val;
    pil->penultimo = p;
    return pil;
}
Pilha *pop_pilha(Pilha *p, int val)
{
}
Pilha* passagem_pilha(Pilha*coloca,Pilha*tira){
    Pilha*j;
    for (  j= tira; j!=NULL; j=j->penultimo)
    {
        coloca=push_pilha(coloca,j->valor);
    }
    return coloca;
}
Fila *criar_fila()
{
    Fila *fil = (Fila *)malloc(sizeof(Fila));
    fil->pa = criar_pilha();
    fil->pb = criar_pilha();
    return fil;
}
Fila* push_fila(Fila*p,int val){
    p->pa=passagem_pilha(p->pa,p->pb);
    Fila *fil = (Fila *)malloc(sizeof(Fila));
    fil->pa=push_pilha(p->pa,val);
    fil->pb=NULL;
    return fil;
}


int main()
{
    Fila*fil;
    fil=criar_fila();
    fil=push_fila(fil,10);
    fil=push_fila(fil,20);
    return 0;
}
