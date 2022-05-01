// Lista de brinquedos com (nome, preço, estoque ) geral
//função de comprar brinquedos
//promoção de 20% se for vendido 50% do produto
//Lista de brinquedos disponiveis em estoque
#include<stdio.h>
#include<stdlib.h>
struct brinquedo
{
    char* nome;
    float preco;
    int estoque;
    struct brinquedo* prox;
};
typedef struct brinquedo Brinquedo;

Brinquedo* criarBrinquedo(){
    return NULL;
}
Brinquedo* inseriBrinquedo(Brinquedo* brinc, char* nome, float preco,int estoque){
    Brinquedo* novo=(Brinquedo*) malloc(sizeof(Brinquedo));
    novo->nome=nome;
    novo->preco=preco;
    novo->estoque=estoque;
    novo->prox=brinc;
    return novo;
}
Brinquedo* removerBrinquedo(Brinquedo*brinc,char*nome){
    Brinquedo* ant=NULL;
    Brinquedo* elem=brinc;  
    while (elem!=NULL && elem->nome!=nome)
    {
       printf("oi");
        ant=elem;
        elem=elem->prox;
    }
    
    if (elem==NULL)
    {
        return brinc;
    }
    
    if (ant==NULL)
    {
         brinc=elem->prox;
    }else
    {
        ant->prox=elem->prox;
    }
    return brinc;
}
Brinquedo* busca(Brinquedo* brinc, char*nome){
    for (Brinquedo* b = brinc; b!=NULL;b=b->prox)
    {
        if (b->nome==nome)
        {
            return b;
        }
        
    }
    
}
Brinquedo* comprarBrinquedo(Brinquedo*atual,char*nome){
    Brinquedo* ant=NULL;
    Brinquedo* p=atual;
    atual->estoque--;
    return atual;

}
void imprimirLista(Brinquedo*brinc){
    Brinquedo* b=brinc;
    for ( b ; b!=NULL; b=b->prox)
    {
        printf("%s | %.2f | %d\n",b->nome,b->preco,b->estoque);
    }
    
}



int main(){
    Brinquedo* brincInicioVendas;
    Brinquedo* brincFinal;
    //inserir brinquedos no inicio do mes
    
    brincInicioVendas=criarBrinquedo(); 
    brincFinal=criarBrinquedo();
    brincFinal=brincInicioVendas=inseriBrinquedo(brincInicioVendas,"Boneco Batman",21.5,2);
    brincFinal=brincInicioVendas=inseriBrinquedo(brincInicioVendas,"Boneco Homem Aranha",25.5,4);
    brincFinal=brincInicioVendas=inseriBrinquedo(brincInicioVendas,"Hotwhels",10,3); 
    
 
    //Compras no mes
   
    // brincFinal=brincInicioVendas;
    brincFinal=comprarBrinquedo(brincFinal,"Hotwhels");
    // brincFinal=comprarBrinquedo(brincInicioVendas,brincFinal,"Hotwhels");
    // brincFinal=comprarBrinquedo(brincInicioVendas,brincFinal,"Boneco Homem Aranha");
    // brincFinal=comprarBrinquedo(brincInicioVendas,brincFinal,"Boneco Homem Aranha");
    // brincFinal=comprarBrinquedo(brincInicioVendas,brincFinal,"Boneco Batman");
    // brincFinal=comprarBrinquedo(brincInicioVendas,brincFinal,"Boneco Batman");
      printf("Estoque INICIAL\n");
    printf("Nome  |  Preco  | Estoque\n");
    imprimirLista(brincInicioVendas);
    printf("Estoque Final\n");
    printf("Nome  |  Preco  | Estoque\n");
    imprimirLista(brincFinal);
    return 0;
}
