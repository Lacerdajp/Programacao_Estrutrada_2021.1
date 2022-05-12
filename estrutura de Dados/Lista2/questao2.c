#include<stdio.h>
int incluir_vetorNumber(int *v, int n){
    for (int i = 0; i < n; i++)
    {
        scanf("%d",v[i]);
    }
    return *v;
} 
int testa_PA_sem_return(int n, int *v, int *a){
    int k =0, x=0;
     for (int i = 1; i < n; i++)
    {
        k=(v[i]-v[0])/i; 

        if (i==1)
        {
            x=k;
        
         
        } if (x!=k)
        {
            *a=0;
            break;
        }
        *a=x;
    }
     return 0;
}

int main(){
    int n =0,k=0;
    int v[1000];
    scanf("%d",&n);
    *v=incluir_vetorNumber(n,*v);
    testa_PA_sem_return(n,*v,&k);
    printf("%d",k);
    return 0;

}