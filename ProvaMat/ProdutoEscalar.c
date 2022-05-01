#include<stdio.h>
void inserirValores(int v1[],int v2[]){
    printf("Inserir o vetor 1: ");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d",&v1[i]);
    }
    printf("Inserir o vetor 2: ");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d",&v2[i]);
    }
}
int produtoEscalar(int v1[], int v2[]){
    
    return ((v1[0]*v2[0])+(v1[1]*v2[1])+ (v1[2]*v2[2]));
}
 
int main(){
    int v1[3]={0,0,0};
    int v2[3]={0,0,0};
    int produto=0;
    inserirValores(v1,v2);
    produto=produtoEscalar(v1,v2);
    printf("(%d,%d,%d) x (%d,%d,%d)= (%d x %d)+ (%d x %d)+(%d x %d)= %d",
    v1[0],v1[1],v1[2],v2[0],v2[1],v2[2], v1[0],v2[0],v1[1],v2[1],v1[2],v2[2],produto);

}