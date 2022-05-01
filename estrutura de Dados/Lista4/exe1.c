#include <stdio.h>
#include<stdlib.h>

struct arv
{
    float val;
    struct arv* esq;
    struct arv* dir;
};
typedef struct arv Arv;
Arv* criar_arv(){
    return NULL;
}
Arv* inserir_arv(Arv* a, float v){
    if (a== NULL)
    {
        a=(Arv*) malloc(sizeof(Arv));
        a->val=v;
        a->esq=a->dir=NULL;
    }
    else if(v<a->val){
        a->esq=inserir_arv(a->esq,v);
    }
    else if (v>a->val)
    {
        a->dir=inserir_arv(a->dir,v);
    }
    
    

}


int main(){


    return 0;
}