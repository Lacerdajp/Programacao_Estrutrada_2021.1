#include<stdio.h>
#include<string.h>
int main(){
    int x=0,pos=1;
    char senha[1000],var[50];
    scanf("%d",&x);
    for (int i = 0; i < x; i++)
    {
        
        scanf("%s",senha);
        for (int z = 0; z < strlen(senha); z++)
        {
            if ((senha[z]>='a'&&senha[z]<='z')||(senha[z]<='Z'&& senha[z]>='A'))
            {
                senha[z]=senha[z]+3;
            }
        }
       pos=1;
        for (int z = 0,str=strlen(senha); z < str-pos; z++)
        {
            var[0+pos]=senha[str-pos];
            senha[str-pos]=senha[z];
            senha[z]=var[0+pos];
            pos++;
            
        }

         for (int z = (strlen(senha))/2; z < strlen(senha) ; z++)
        {
            senha[z]=senha[z]-1;
        }
        
       printf("%s\n",senha);
    }
    
    return 0;
}