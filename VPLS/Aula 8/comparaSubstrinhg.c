#include<stdio.h>
int comparador(char v1[],char v2[], int tam1, int tam2);
int limitador(char v[]);
char zerando(char v[]);
int main(){
    char string1[50];
    char string2[50];
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
    int count=0,somaMaior=0;
    for (int i = 0; i < tam1; i++)
    {
        for (int z = 0; z < tam2; z++)
        {
            if (v1[z]==v2[i+count])
            {
                count++;
            }
            else{
                i=i+count;
                if(count>somaMaior){
                    somaMaior=count;
                    count=0;
                }
            }
        }
        
    }
    printf("%d",somaMaior);
    

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