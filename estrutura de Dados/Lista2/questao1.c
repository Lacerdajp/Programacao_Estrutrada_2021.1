#include<stdio.h>
#include "../../../LibsJPLS/vetores.h"
int testa_PA(int n, int *v) {
    int k=0,x=0;
        
    for (int i = 1; i < n; i++)
    {
        k=(v[i]-v[0])/i; 

        if (i==1)
        {
            x=k;
        
         
        } if (x!=k)
        {
            return 0;
            break;
        }
    }
    return x;
}
int main(){
    int n =0,k=0;
    int v[1000];
    scanf("%d",&n);
    *v=incluir_vetorNumber(n,*v);
    k=testa_PA(n,*v);
    printf("%d",k);
    return 0;

}