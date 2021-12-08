#include<stdio.h>
int fatorial(int *pnum);
int qtMenor(int *pnum);
int somaFat(int *pnumber);
int main(){
    int n=0,quantidade=0;
    scanf("%d",&n);
    quantidade= qtMenor(&n);
    printf("%d\n",quantidade);
    return 0;
}
int fatorial(int *pnum){
    int result=1;
    for (int i = 1; i <= *pnum; i++)
    {
        result=result*i;
    }
    return result;
}
int qtMenor(int *pnum){
    int maiorNum=0, q2=0,q1=1;
    for (int i = 1; fatorial(&i) <= *pnum; i++)
    {
        maiorNum=i;
    }
    if (*pnum-fatorial(&maiorNum)!=0)
    {
        *pnum=*pnum-fatorial(&maiorNum);
        q2 =qtMenor(&*pnum);
    }
    else{
        q1=1;
    }
   q1=q1+q2;
    
    return q1;
}