#include <stdio.h>
int fat(int n) {
    if (n==0)
    {
        return n+1;
    }else{
        return n * fat(n-1);
    }
}

int comb(int n, int p){
    int x;
    int soma=n-p;
    x=fat(n)/(fat(p)*fat(soma));
    return x;
}
int main(){

    int p,n;
    scanf("%d %d",&n,&p);
    printf("%d",comb(n,p));
    return 0;
}