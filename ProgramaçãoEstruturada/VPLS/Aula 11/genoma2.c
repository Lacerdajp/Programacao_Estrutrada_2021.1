#include<stdio.h>
int comparador(char v1[],char v2[], int tam1, int tam2);
int limitador(char v[]);
char zerando(char v[]);
int main(){
    char string1[100];
    char string2[100];
    int tam1,tam2;
    zerando(string1);
    zerando(string2);
    fgets(string1,50,stdin);
    tam1=limitador(string1);
    fgets(string2,50,stdin);
    tam2=limitador(string2);
    comparador(string1,string2,tam1,tam2);

    return 0;
}
int comparador(char v1[],char v2[],int tam1,int tam2){
    int count=0,quantidade=0;
    for (int i = 0; i < tam1; i++)
    {
        for (int z = 0; z < tam2; z++)
        {
            if (v2[z]==v1[i+count])
            {
                count++; 
            }
            else{
               z=tam2;
                if(count<tam2-1){
                    count=0;
                   
                }else{
                    quantidade++;
                    count=0;
                }
            }
        }
        
    }
    printf("%d",quantidade);
    

}
char zerando (char v[]){
    for (int i = 0; i < 50 ; i++)
    {
        v[i]=0;
    }
}
int limitador (char v[]){
    int tam=0;
    for (int i = 0; i < 50 ; i++)
    {
        if (v[i]==0)
        {
            tam=i;
            break;
        }
    }
    return tam;
}