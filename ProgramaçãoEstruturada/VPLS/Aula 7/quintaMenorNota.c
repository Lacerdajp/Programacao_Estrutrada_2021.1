#include <stdio.h>
#include <string.h>
int main()
{
    int n = 0, notas[100], posicao[100], x = 0, f = 0;
    scanf("%d", &n);
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
                 posicao[x]=notas[z];
             }
          }
          if (posicao[x]!=11)
          {
              x++;
          }
          
         
    }
    
     printf("%d ",posicao[4]);
    
    
    
   

   

    return 0;
}