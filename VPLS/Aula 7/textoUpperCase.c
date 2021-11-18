#include <stdio.h>
#include <string.h>
int main(){

char  palavra[50], frase[50];
int x=0;

for (int i = 0; i < 10; i++)
{
    
    scanf("%s",palavra);
    if (x==strlen(palavra))
    {
        break;
    }
    else{
        x=strlen(palavra);
    }
    
     if (palavra[0]>='a')
        {
            palavra[0]=palavra[0]-'a'+'A';
        }
       for (int i = 1; i < strlen(palavra); i++)
       {
           if (palavra[i]<'a'){
              palavra[i]=palavra[i]-'A'+'a';
           }
       }  
        printf("%s ",palavra);
}
     
 



return 0;
}