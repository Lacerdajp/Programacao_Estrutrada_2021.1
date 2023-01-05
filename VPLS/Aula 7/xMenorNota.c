#include <stdio.h>
#include <string.h>
int main()
{
    int n = 0, notas[100], posicao[100], x = 0, f = 0;
    scanf("%d %d" , &n,&x);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &notas[i]);
        for (int z = 0; z < i; z++)
        {
            if (notas[z]==notas[i])
            {
               notas[i]=11;
            }
            
        }
        if (notas[i]==11)
        {
            i--;
            n--;
        }
    }  
    for (int i = 0; i <= 10; i++)
    {
         posicao[i]= 11;
         for (int z = 0; z < n; z++)
          {
             if (notas[z] ==i )
             {
                 posicao[f]=notas[z];
             }
          }
          if (posicao[f]!=11)
          {
              f++;
          }
          
         
    }
    
     printf("%d ",posicao[x-1]);
    
    
    
   

   

    return 0;
}