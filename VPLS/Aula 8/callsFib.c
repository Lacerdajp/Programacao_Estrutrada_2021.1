#include <stdio.h>
int casos(int *pn);
int calls(int z);
int fib(int x);
int main(){
    int n=0;
    scanf("%d",&n);
    casos(&n);
    return 0;
}
int casos(int *pn){
    int x=0,fibo=0,q=0;
    for (int i = 0; i < *pn; i++)
    {
        scanf("%d",&x);
        fibo= fib(x);
        q= calls(1);
        calls(2);
        printf("fib(%d)= %d calls = %d\n",x,q,fibo);

    }
    

}
int fib(int x){
    int soma=0;
    if (x<2)
    {
        
        calls(0);
        return x;
        

    }else{
        calls(0);
        return fib(x-1)+fib(x-2);
    }
    
}
int calls(int z){
    static int q=0;
    if (z==1)
    {
        q--;
        return q;
    }else if(z==0){
         q++; 
    }
    else{
        q=0;
    }
}
