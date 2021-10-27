#include <stdio.h>
int main()
{
    double a = 0, b = 0, c = 0, num = 0;

    printf("Digite os 3 lados do triangulo:\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (c >= a)
    {
        num = a;
        a = c;
        c = num;
    }
    if (b >= a)
    {
        num = a;
        a = b;
        b = num;
    }

    if (c >= b)
    {
        num = b;
        b = c;
        c = num;
    }

    if (a >= (b + c))
    {
        printf("NAO FORMA TRIANGULO\n");
    }
    else
    {

        if ((a * a) == ((b * b) + (c * c)))
        {
            printf("TRIANGULO RETANGULO\n");
        }
        else if ((a * a) > ((b * b) + (c * c)))
        {
            printf("TRIANGULO OBTUSANGULO\n");
        }
        else if ((a * a) < ((b * b) + (c * c)))
        {
            printf("TRIANGULO ACUTANGULO\n");
        }

        if (a == b && b == c)
        {
            printf("TRIANGULO EQUILATERO\n");
        }
        else if (a == b || b == c || c == a)
        {
            printf("TRIANGULO ISOSCELES\n");
        }
    }

    return 0;
}