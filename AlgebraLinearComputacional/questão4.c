#include <stdio.h>
#include<math.h>
void zerarVetor(float vetor[], int n){

 for (int i = 1; i <= n; i++)
    {
        vetor[i]=0.0;
    }
}
void zerarmatriz(float matriz[31][4]){
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 31; j++)
        {
           
            matriz[j][i]=0.0;
                
        }
        
    }
    
}
void imprimirMatriz(float matriz[31][4]){
    printf("      GJ           GS         SOR         GR\nI     ");
        for (int i = 0; i < 31; i++)
        {
           if (i>=1)
           {
               printf("X%d    ",i);
           }
           for (int j = 0; j < 4; j++)
           {
               if (j==3)
               {
                   printf("%.4f\n",matriz[i][j]);
               }
               else{
                   printf("%.4f      ",matriz[i][j]);
               }
           }
           
        }
        
}
void passaVetor(float vetork[],float vetork1[],int n){
    for (int i = 1; i <= n; i++)
    {
       for (int i = 1; i <= n; i++)
       {
           vetork[i]=vetork1[i];
       }
    }
}
float buscaMaiorValor(float vetor[],int n){
    int maior=vetor[1];
    for (int i = 1; i < n; i++)
    {
        if (vetor[i]>maior)
        {
            maior=vetor[i];
        }
        
    }
    return maior;
}
int subtracaoVetor(float v1[],float v2[],int n){
    float result[n];
    float maior=0;
    for (int i = 1; i <= n; i++)
    {
        result[i]=v1[i]-v2[i];

        
    }
    maior=buscaMaiorValor(result,n);
    return maior;
    
}
int metodoGaussJacobi(float vetor[],int n,float calc){
    
    int interacao=0;
    float temp[n];
    float subtracao=1;
    zerarVetor(temp,n);
    while (subtracao>=0.0001)
    {
        
        passaVetor(vetor,temp,n);
        for (int i = 1; i <= n; i++){
            if (i==1)
            {
                temp[i]=(1.0-vetor[i+1])/calc;
                
                
            }else if (i==n)
            {
                
                temp[i]=(1.0-vetor[i-1])/calc;
            }else{
                temp[i]=(-vetor[i+1]-vetor[i-1])/calc; 
            }
        }
        subtracao=subtracaoVetor(temp,vetor,n);
        if (subtracao<pow(10,-4))
        {
            break;
        }
        
        interacao++;
    }
    return interacao;
 }
 int metodoGaussSeidel(float vetor[],int n,float calc){
        
    int interacao=0;
    float temp[n];
    float subtracao=1;
     zerarVetor(temp,n);
    while (subtracao>=0.0001)
    {
        
        passaVetor(vetor,temp,n);
        for (int i = 1; i <= n; i++){
            if (i==1)
            {
                temp[i]=(1.0-temp[i+1])/calc;
                
                
            }else if (i==n)
            {
                
                temp[i]=(1.0-temp[i-1])/calc;
                 
            }else{
                temp[i]=(-temp[i+1]-temp[i-1])/calc; 
            }
        }
        subtracao=subtracaoVetor(temp,vetor,n);
        if (subtracao<pow(10,-4))
        {
            break;
        }
        
        interacao++;
    }
    return interacao;

 };
 void metodoSOR(){

 };
 void metodoGradiente();
 int main(){
    int escolha;
    int f;
    float h=0.1;
    int n=30;
    float c=-(2*(1+pow(h,2)));
    float x[n];
    char estadoMetodo[4]={'o','o','o','0'};
    float matriz[31][4];
    zerarmatriz(matriz);

    do
    {

        printf("Escolha um metodo para ser resolvido: \n");
        if (estadoMetodo[0]=='o')
        {
            printf("1.Gauss Jacobi\n");
        }
         if (estadoMetodo[1]=='o')
        {
            printf("2.Gauss Siedel\n");
        }
         if (estadoMetodo[2]=='o')
        {
            printf("3.SOR\n");
        }
         if (estadoMetodo[2]=='o')
        {
            printf("4.Gradiente\n");
        }
        printf("5.Finalizar Testes\n");
        scanf("%d",&escolha);
        switch (escolha)
        {
        case 1:
            f=metodoGaussJacobi(x,n,c);
               for (int j = 0; j < 31; j++)
               {
                   if(j==0){
                   matriz[j][0]=(float)f;
                   }
                   else{
                    matriz[j][0]=x[j];
                   }
               }
            imprimirMatriz(matriz);
            estadoMetodo[0]='x';
            break;
        case 2:
             f=metodoGaussSeidel(x,n,c);
               for (int j = 0; j < 31; j++)
               {
                   if(j==0){
                   matriz[j][1]=(float)f;
                   }
                   else{
                    matriz[j][1]=x[j];
                   }
               }
            imprimirMatriz(matriz);
            estadoMetodo[0]='x';
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