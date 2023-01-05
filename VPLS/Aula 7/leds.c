#include <stdio.h>
#include <string.h>
int main()
{
    int n[1000], nlinha = 0;
    char v[100];
    scanf("%d", &nlinha);
    for (int i = 0; i <= (nlinha - 1); i++)
    {
        scanf("%s", v);
        n[i] = 0;

        for (int z = 0; z <= strlen(v); z++)
        {
            if (v[z] == '0' || v[z] == '9' || v[z] == '6')
            {
                n[i] = n[i] + 6;
            }
            else if (v[z] == '2' || v[z] == '3' || v[z] == '5')
            {
                n[i] = n[i] + 5;
            }
            else if (v[z] == '1')
            {
                n[i] = n[i] + 2;
            }
            else if (v[z] == '7')
            {
                n[i] = n[i] + 3;
            }
            else if (v[z] == '4')
            {
                n[i] = n[i] + 4;
            }
            else if (v[z] == '8')
            {
                n[i] = n[i] + 7;
            }
        }
        printf("%d leds\n", n[i]);
    }

    return 0;
}