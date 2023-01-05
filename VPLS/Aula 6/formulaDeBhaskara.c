#include <stdio.h>
#include <math.h>
int main()
{
    double a = 0, b = 0, c = 0, delta = 0, x1 = 0, x2 = 0;
    printf("Digite,respectivamente, a,b,c\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    delta = (b * b) - (4 * a * c);
    if (delta < 0 || a == 0)
    {
        printf("impossivel calcular");
    }
    else
    {
        x1 = ((-b) - sqrt(delta)) / (2 * a);
        x2 = ((-b) + sqrt(delta)) / (2 * a);
        printf("R1 = %.5lf\nR2 = %.5lf", x2, x1);
    };

    return 0;
}