#include <stdio.h>
#include <math.h>
int decBin(int n);
int decHex(int n);
int binHex(int n);
int binDec(int n);
int main()
{
    int n,z,j;
    long int vetor[30];
    char number[30], base[30];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        vetor[i] = 0;
        scanf("%s", number);
        scanf("%s", &base[i]);
        if(base[i] == 'h')
        {
            for( z = 0; number[z] != '\0'; z++){}
            for( j = 0; number[j] != '\0'; j++)
            {
                if(number[j] >= 'A' && number[j] <= 'Z')
                {
                    vetor[i] += (number[j] - 'A' + 10) * pow(16, z - 1);
                    z--;
                }
                else if(number[j] >= 'a' && number[j] <= 'z')
                {
                    vetor[i] += (number[j] - 'a' + 10) * pow(16, z - 1);
                    z--;
                }
                else
                {
                    vetor[i] += (number[j] - '0') * pow(16, z - 1);
                    z--;
                }
            }
        }
        else
        {
            for(z = 0; number[z] != '\0'; z++){}
            for( j = 0; number[j] != '\0'; j++)
            {
                vetor[i] += (number[j] - '0') * pow(10, z - 1);
                z--;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        switch(base[i])
        {
            case 'b':
                printf("Case %d\n", i + 1);
                binDec(vetor[i]);
                binHex(vetor[i]);
                break;
                
            case 'd':
                printf("Case %d\n", i + 1);
                decHex(vetor[i]);
                decBin(vetor[i]);
                break;
                
            case 'h':
                printf("Case %d\n", i + 1);
                printf("%ld dec\n", vetor[i]);
                decBin(vetor[i]);
                break;
        }
    }
    return 0;
}
int decBin(int n){
    int count = 0;
    int vetor[30];
    while(n  > 1)
    {
        vetor[count] = n%2;
        n /= 2;
        count++;
    }
    vetor[count] = n;
    for(int i= count; i >= 0; i--)
    {
        printf("%d", vetor[i]);
        if(i==0)
        {
            printf(" bin");
        }
    }
    printf("\n");
}

int decHex(int n)
{
    int count = 0;
    char vetor[30];
    while(n > 15)
    {
        if(n%16 > 9)
        {
            vetor[count] = (n%16) % 10 + 'a';  
            n = n/16;
            count++;
        }
        else
        {
            vetor[count] = n%16 + '0';
            n = n/16;
            count++;
        }
    }
    if(n > 9)
    {
        vetor[count] = (n % 10) + 'a';
        count++;
    }
    else
    {
        vetor[count] = n + '0';
        count++;
    }
    for(int i = count - 1; i >= 0; i--)
    {
        printf("%c", vetor[i]);
        if(i==0)
        {
            printf(" hex");
        }
    }
    printf("\n");
}

int binHex(int n)
{
    int decimal = 0, i = 0;
    while(n > 1)
    {
        decimal += (n%10) * pow(2, i);
        n = n/10;
        i++;
    }
    decimal += n * pow(2, i);
    decHex(decimal);
}

int binDec(int n)
{
    int decimal = 0, i = 0;
    while(n > 1)
    {
        decimal += (n%10) * pow(2, i);
        n = n/10;
        i++;
    }
    decimal += n * pow(2, i);
    printf("%d dec\n", decimal);
}