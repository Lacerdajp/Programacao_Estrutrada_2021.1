#include <stdio.h>
int main(){
    int dec=0,casa[11], x=0, i=0,count=0;
    char hexa[11];
    for (int i = 0; i < 11; i++)
    {
        hexa[i]=0;
    }
    
    scanf("%d", &dec);
    
    for (;dec!=0;i++)
    {
    
        casa[i]=dec%16;
        for (int z = 0; z < i; z++)
        {
            x=casa[z];
            casa[z]=casa[i];
            casa[i]=x;
        }
        
        dec=dec/16;    
        
    }
    
    for (int z = 0; z < i; z++)
    {
        switch (casa[z])
        {
        case 0: hexa[z]='0';break;
        case 1:hexa[z]='1';break;
        case 2:hexa[z]='2';break;
        case 3: hexa[z]='3';break;
        case 4: hexa[z]='4';break;
        case 5: hexa[z]='5';break;
        case 6: hexa[z]='6';break;
        case 7: hexa[z]='7';break;
        case 8: hexa[z]='8';break;
        case 9: hexa[z]='9';break;
        case 10: hexa[z]='A';break;
        case 11: hexa[z]='B';break;
        case 12: hexa[z]='C';break;
        case 13: hexa[z]='D';break;
        case 14: hexa[z]='E';break;
        case 15: hexa[z]='F';break;
        default: hexa[z]='0';break;
        }
       
    }
    printf("%s",hexa);
    

    return 0;
}