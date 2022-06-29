#include <stdio.h>
#define TAM 1000
void rodar_string(char *str){
    int x=strlen(str);
    int ultimo=str[x-2];
    for (int i = x-2; i >=0; i--)
    {
        if (i==0)
        {
            str[i]=ultimo;
        }
        else{ 
            str[i]=str[i-1];
        }
    }
}
int main(){
    char str[]={0};
    fgets(str, TAM,stdin );
    rodar_string(str);
    printf("%s", str);
    return 0;
}