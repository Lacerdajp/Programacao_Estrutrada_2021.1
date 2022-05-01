#include <stdio.h>
int fib(int x);
int main(){
    int n=0,fibo=0;
    scanf("%d",&n);
    fibo= fib(n);
    printf("%d",fibo);
    return 0;
}int fib(int x){
    int soma=0;
    if (x<2)
    {
        return x;
        

    }else{
        return fib(x-1)+fib(x-2);
    }
    
}