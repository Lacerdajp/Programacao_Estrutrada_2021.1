#include<stdio.h>
void inserirValor(int v[]){
    printf("Insira 20 numero inteiros:\n");
    for (int i = 0; i < 20; i++)
    {
        scanf("%d",&v[i]);
    }
}
void Verifica(int v[],int ver[]){
    int nulo=0,par=0,impar=0;
    for (int i = 0; i < 20; i++)
    {
        if (v[i]==0)
        {
            nulo++;
            ver[0]=nulo; 
            // printf("nulo :%d ",ver[0]);
        }
        if ((v[i]%2)==0)
        {
            par++;
            ver[1]=par;
            // printf("par:%d ",ver[1]);
        }else{
            impar++;
            ver[2]=impar;
            // printf("Impar:%d ",ver[2]);
        }
        
    }
    
}
void imprimirValor(int v[]){
    for (int i = 0; i < 20; i++)
    {
        printf("%d ",v[i]);
    }
}
void imprimirQuantidades(int ver[]){
    printf("Numeros Nulos: %d\nNumeros Pares: %d\nNumeros Impares: %d\n",ver[0],ver[1],ver[2]);
}
int main(){
    int v[20],ver[3]={0,0,0};
    inserirValor(v);
    Verifica(v,ver);
    imprimirQuantidades(ver);

}