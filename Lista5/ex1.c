#include <stdio.h>
#include <math.h>
int main(){
    double  x1=0,y1=0,x2=0,y2=0;
    double de=0;
    printf("Digite as coordenadas do ponto 1:\n");
    scanf("%lf %lf",&x1,&y1);
    printf("Digite as coordenadas do ponto 2:\n");
    scanf("%lf %lf",&x2,&y2);
    de= sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
    printf("A distancia Euclidiana e: %lf",de);
    return 0;
}