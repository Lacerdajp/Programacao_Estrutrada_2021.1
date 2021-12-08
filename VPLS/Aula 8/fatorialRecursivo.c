#include<stdio.h>
int fatorial(int num);
int main(){
    int n=0,fat=0;
    scanf("%d",&n);
    fat= fatorial(n);
    printf("%d\n",fat);
    return 0;
}
int fatorial(int num){
    
    if (num==0)
    {
        return num+1;
    }else{
    return num * fatorial(num-1);
    }
}