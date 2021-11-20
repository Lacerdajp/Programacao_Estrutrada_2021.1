#include<stdio.h>
int main(){
    int n=0, t=0;
    double x=0, num=0,prox=0,soma=100;
    do
    {
        printf("Digite o numero de entradas: ");
        scanf("%d",&n);
    } while (n<=0||n>10);
    for (int i = 0; i < n; i++)
    {
        soma=100;
        prox=0;
        do
        {
       
        scanf("%d ",&t);
        } while (t<=0||t>=100);

        scanf("%lf ",&x);
        for (int z = 1; z<= t; z++)
        {
            scanf("%lf",&num);
            if (num==x)
            {
                prox =num;
                break;
            }else if (num>x&& (num - x)< soma)
            {
                soma=num-x;
                prox=num;   
            }else if (num<x &&(x-num)<soma)
            {
                soma=x-num;
                prox=num;
            }  
        }
         printf("o numero mais proximo e o %.1lf\n", prox);
        
    }
    return 0;
}