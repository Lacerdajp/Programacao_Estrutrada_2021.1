#include <stdio.h>
int main()
{
    int num1 = 999, num2 = 999, num[6], result = 0, result1 = 0, maiorPan = 0;
    while (num1 > 100 && num2 > 100)
    {
        result = num1 * num2;

        for (int i = 0; result / 10 != 0; i++)
        {
            num[i] = result % 10;
            result = result / 10;
        }
        num[5] = result;
        if (num[5] == num[0] && num[4] == num[1] && num[3] == num[2])
        {
            result1 = num1 * num2;
            if (maiorPan < result1)
            {
                maiorPan = result1;
            }
        }
        if (num1 == 101)
        {
            num2--;
            num1 = num2;
        }
        else
            num1--;
    }
    printf("%d\n", maiorPan);

    return 0;
}