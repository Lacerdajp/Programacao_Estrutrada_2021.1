#include"../../LibsJPLS/convertTemperatura.h"
int main(){ 
    float temp1=0,temp2=0;
    scanf("%f",&temp1);
    temp2=celsiusForFahrenheit(temp1);
    printf(" O valor  em Farhrenheit e %.2f",temp2);
}
