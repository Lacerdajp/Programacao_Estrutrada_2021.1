#include<stdio.h>
#include<math.h>
float formulaBinet(int n);
int main(){
    int n=0;
    float x;
    scanf("%d",&n);
    x=formulaBinet(n);
    printf("%.1f",x);
    return 0;
}
float formulaBinet(int n){
    float f;
    f=(pow((1+sqrt(5))/2,(float)n)-pow((1-sqrt(5))/2,(float)n))/sqrt(5);
    return f;
}