#include <stdio.h>
#include "../../../LibsJPLS/cadeiaDeCarcteres.h"
#define TAM 1000

int main(){
    char str[]={0};
    fgets(str, TAM,stdin );
    printf("%s", rodar_string(str));
    return 0;
}