#include<stdio.h>
float mediaAritfor3(float n1,float n2,float n3){
    float r=0;
    r=(n1+n2+n3)/3;
    return r;
}
int main(){
    float n1=0.0,n2=0.0,n3=0.0,r=0;
    scanf("%f\n %f \n%f",&n1, &n2, &n3);
    r=mediaAritfor3(n1,n2,n3);
    if ((n1>=3||n2>=3||n3>=3)&&r>=5)
    {
        printf("O aluno esta Aprovado");
    }else
    {
       printf("O aluno precisa fazer a prova final");
    }
    
    
    

}