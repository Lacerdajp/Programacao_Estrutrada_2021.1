#include <stdio.h>
int main()
{
    int n = 0, minutos = 0, segundos = 0, horas = 0;
    const int temph = 3600, tempm = 60;
    printf("diga um tempo em segundos:\n");
    scanf("%d", &n);
    horas = n / temph;
    minutos = (n % temph) / tempm;
    segundos = (n % temph) % tempm;
    printf("tempo total : %d:%d:%d", horas, minutos, segundos);

    return 0;
}