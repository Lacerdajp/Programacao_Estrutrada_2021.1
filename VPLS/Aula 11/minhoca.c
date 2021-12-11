#include<stdio.h>
#include<stdlib.h>
int insertPilha(char matriz[100][100], int d);
int caminho(int d );                             
int main(){
    int d=0,f=0;
    scanf("%d",&d);
    f=caminho(d);
    printf("%d",f);
    return 0;
}
int caminho(int d){
    char matriz[100][100];
    int z;
    for (int i = 0; i < d; i++)//linhas
    {
        for (int z = 0; z < d; z++)//colunas
        {
            scanf("%1s",&matriz[i][z]);
        }
    }
    z=insertPilha(matriz, d);
    return z ;
}
int insertPilha(char matriz[100][100], int d){
    int t=0, i=0,a=d,count=0;
    char x=0,z=0;
    while (count!=d*d){ 
       
        for (i=t,a=d-t; i < a; i++)
        {
            
            x=matriz[t][i];
            
            count++;
            if(x=='o'){
                break;
            }
        }
        if(x=='o'){
                break;
            }
            
        for (i=t+1 , a=d-t; i < a; i++)
        {
            x=matriz[i][a-1];
           count++;
            if(x=='o'){
                break;
            }
        }
        if(x=='o'){
                break;
            }
            
        for (i=t, a=d-t-1-1; i <= a; a--)
        { 
            x=matriz[a][i];
           count++;
            if(x=='o'){
                break;
            }
        }
         
          if(x=='o'){
                break;
            }
            
        for (i=t+1, a=d-t-1-1; i <= a; a--)
        { 
            x=matriz[t][a];
           count++;
            if(x=='o'){
                break;
            }
        }
        if(x=='o'){
                break;
            }
        t++;
    }
    
    return  count-1;
}