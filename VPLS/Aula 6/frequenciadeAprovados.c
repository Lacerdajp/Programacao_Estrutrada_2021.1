#include <stdio.h>
int main()
{
    int nalun = 0, notaluno = 0, frquencia = 0;
    scanf("%d", &nalun);
    for (int i = 0; i < nalun; i++)
    {
        scanf("%d", &notaluno);
        if (notaluno >= 0 && notaluno <= 10)
        {
            if (notaluno >= 5)
            {
                frquencia++;
            }
        }
    }
    printf("%d", frquencia);

    return 0;
}