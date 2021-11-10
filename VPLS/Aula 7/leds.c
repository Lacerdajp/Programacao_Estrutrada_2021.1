#include <stdio.h>
#include <string.h>
int main()
{
    int n[1000], leds[1000],nlinha=0 ;
    int v [100];
    scanf("%d", &nlinha);
    for (int i = 0; i < (nlinha-1); i++)
    {
        scanf("%d", v);
        n[i] = v;
        for (int z = 0; z< strlen(v); z++)
        {
            if (v[z]==0||v[z]==9||v[z]==6)
            {
                leds[i]=leds[i]+6;
            }
            else if (v[z]==2||v[z]==3||v[z]==5)
            {
                leds[i]=leds[i]+5;
            }else if (v[z]==1)
            {
                leds[i]=leds[i]+2;
            }else if (v[z]==7)
            {
                leds[i]=leds[i]+3;
            }else if (v[z]==4)
            {
                leds[i]=leds[i]+4;  
            }else
            {
                leds[i]=leds[i]+7;
            }

        }
        
        
    }
    printf("%d",leds);

    return 0;
}