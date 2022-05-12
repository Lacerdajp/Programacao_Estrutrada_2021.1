#include <stdio.h>
#define TAM 1000
char* rodar_string(char* str){
    int x=strlen(str);
    char *str2=(char*)malloc(sizeof(char));

    for (int i = x-2; i >=0; i--)
    {
        if (i==0)
        {
            str2[i]=str[x-2];
        }
        else{
            str2[i]=str[i-1];
        }
    }
        printf("%s\n", str2);
    return str2;
} 

int main(){
    char str[]={NULL};
    fgets(str, TAM,stdin );
    printf("%s", rodar_string(str));
    return 0;
}