#include <stdio.h>
#include<math.h>
void zerarVetor(float vetor[], int n){

 for (int i = 1; i <= n; i++)
    {
        vetor[i]=0;
    }
}
 float metodoGaussJacobi(float vetor[],int interacao,float calc ){
    zerarVetor(vetor )
 }
 void metodoGaussSeidel();
 void metodoSOR();
 void metodoGradiente();
 int main(){
    int escolha;
    float h=0.1;
    int n=30;
    float c=-(2*(1-pow(h,2)))
    float x[n];
    int interacoes[4]={0,0,0,0};
    char estadoMetodo[4]={'o','o','o','0'};
    int matriz[3][4];
    do
    {

        printf("Escolha um metodo para ser resolvido: \n");
        if (estadoMetodo[0]!='o')
        {
            printf("1.Gauss Jacobi\n");
        }
         if (estadoMetodo[1]!='o')
        {
            printf("2.Gauss Siedel\n");
        }
         if (estadoMetodo[2]!='o')
        {
            printf("3.SOR\n");
        }
         if (estadoMetodo[2]!='o')
        {
            printf("4.Gradiente\n");
        }
        printf("5.Finalizar Testes\n");
        switch (escolha)
        {
        case 1:
            /* code */
            break;
        case 2:

            break;
        case 3:

            break;
        case 4: 

            break;
        default:
            escolha=0;

            break;
        }

    } while (escolha!=0);
    
    
    return 0;
 }