#include <stdio.h>
#include <math.h>
float formulaDeLeibniz(int n){
    float p=0;
    int i=n-1;
    if(i!=0){

       p=(4* (pow(-1,i)/((2*i)+1)))+formulaDeLeibniz(i);

    }else{
        p=4;
    }
    return p;
}
int main(){
    int n=0;
    float r=0;
    scanf("%d",&n);
    r=formulaDeLeibniz(n);
    printf(" resultado:%f",r);
}