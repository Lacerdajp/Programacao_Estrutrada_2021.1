#include <stdio.h>
int casos(int *px);
int sequencia(int *pn);
int posicao(int *ppos, int *pn);
int main(){
    int x=0;
    printf("digite o Numero de casos: ");
    scanf("%d",&x);
    casos(&x);
    return 0;
}
int casos(int *px){
    int n=0,pos=1;
    for (int i = 1; i <= *px; i++)
    {
        scanf("%d",&n);
        pos = posicao(&pos,&n);
        pos==1 ? printf("Caso %d: %d numero\n",i,pos):printf("Caso %d: %d numeros\n",i,pos);
        sequencia(&n);
    }
}
int posicao(int *ppos,int *pn){
    *ppos=1;
    for (int i = 0; i <= *pn; i++)
        {
            *ppos=*ppos+i;
        }
        return *ppos;
}
int sequencia (int *pn){
    int number=0, count=1;
    for (int i = 0; i <= *pn; i++)
    {
        printf("%d ",i);
        if (i>=2&& count!=i)
        {
            count++;
            i--;
        }else if (i>=2&& count==i)
        {
            count=1; 
        }
    }
    printf("\n");
}