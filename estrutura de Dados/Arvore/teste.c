#include<stdio.h>
#include<stdlib.h>

// funcoes:criarvazia, imprimir, pertencer, liberar, inserir(criar), vazia

struct arvore{

    int valor;
    struct arvore* dir; // aponta para o lado esquerdo
    struct arvore* esq; // aponta para o lado direito
};

typedef struct arvore Arvore;

 Arvore* arv_cria(){ // cria uma arvore vazia
     return NULL;
 }
 
 Arvore* arv_insere(int valor, Arvore* sae, Arvore* sad){
    Arvore* aux = (Arvore*) malloc(sizeof(Arvore));
    aux->valor = valor;
    aux->esq = sae;
    aux->dir = sad;
    return aux;
 }

 Arvore* arv_vazia(Arvore*a){ // função para verificar se a arvore esta vazia
    return a==NULL;
}

 Arvore* arv_libera(Arvore* a){  // a é o nó raiz da arvore
     if (a!=NULL){
         arv_libera(a->esq);
         arv_libera(a->dir);
         free(a); // libera a raiz
     }
 }
 
 void arv_imprime(Arvore* a){  //  função void nao retorna nada
    if (!arv_vazia(a)){
        printf("%d", a -> valor); // mostra raiz
        arv_imprime(a->esq); // mostra esquerda
        arv_imprime(a->dir); // mostra direita
    }
 }
 
 int arv_pertence(Arvore* a, int c){ // verificar se o elemento pertence a tal arvore
     if(!arv_vazia(a)){
         return 0;
     }
     else
        return a -> valor == c||  arv_pertence(a->esq,c)|| arv_pertence(a->dir,c);
 }
 
int main(){
    Arvore* arv1 = arv_insere(2,arv_cria(),arv_cria());
    Arvore* arv2 = arv_insere(3,arv_cria(),arv_cria());
    Arvore* arv3 = arv_insere(1,arv1, arv2);
    arv_imprime(arv3);

    return 0;

}