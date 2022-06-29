#include <stdio.h>
float celsiusForFahrenheit(float temp){
    float result=0;
    result=(temp*1.8)+32.0;
    return result;
} 
int main(){ 
    float temp1=0,temp2=0;
    scanf("%f",&temp1);
    temp2=celsiusForFahrenheit(temp1);
    printf(" O valor  em Farhrenheit e %.2f",temp2);
}
