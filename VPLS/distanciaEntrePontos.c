#include <stdio.h>
#include <math.h>
int main()
{
    float x1 = 0, x2 = 0, y1 = 0, y2 = 0, distancia = 0;
    printf(" digite o ponto A:");
    scanf("%f %f", &x1, &y1);
    printf(" digite o ponto B:");
    scanf("%f %f", &x2, &y2);
    distancia = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
    printf("A distancia entre os dois pontos e: %.4lf", distancia);
    return 0;
}