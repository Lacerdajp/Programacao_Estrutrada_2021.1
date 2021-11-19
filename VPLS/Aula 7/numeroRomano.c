#include <stdio.h>
#include <string.h>
int main()
{
    char n[4],x;
    scanf("%s", n);
        x=n[0];
        n[0]=n[strlen(n)-1];
        n[strlen(n)-1]=x;

    
    
    for (int i = 2; i >= 0; i--)
    {
        if ('1'<=n[i]&&n[i]<='3')
        {
            if(i==0) for (char z = '0'; z < n[i]; z++) printf("I");
            if(i==1) for (char z = '0'; z < n[i]; z++) printf("X");
            if(i==2) for (char z = '0'; z < n[i]; z++) printf("C");
        }
        else if ('4'==n[i])
        {
            if(i==0)  printf("IV");
            if(i==1)  printf("XL");
            if(i==2)  printf("CD");
        }
        else if('5'<=n[i]&&n[i]<='8'){
            if(i==0)  {
                printf("V");
                for(char z = '5'; z < n[i]; z++) {
                        printf("I");
                    }; 
            }
            if(i==1)  {
                printf("L");
                    for(char z = '5'; z < n[i]; z++) {
                        printf("X");
                    }
            }
            if(i==2) {
                printf("D");
                 for(char z = '5'; z < n[i]; z++) {
                        printf("C");
                    }
            
            }
        }else if ('9'==n[i])
        {
            if(i==0)  printf("IX");
            if(i==1)  printf("XC");
            if(i==2)  printf("CM");
        }

        
    
    }
    
    
    return 0;
}