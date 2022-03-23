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
Fila *criar_fila()
{
    Fila *fil = (Fila *)malloc(sizeof(Fila));
    fil->pa = criar_pilha();
    fil->pb = criar_pilha();
    return fil;
}
Fila* push_fila()

int main()
{
    /* code */
    return 0;
}
