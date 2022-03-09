#include <stdio.h>
int inserir(int *v, int n);
int bolha(int *v, int n) int main()
{
    int v[6];
    inserirvetor(&v);
}
int inserir(int *v, int n);
int bolha(int *v, int n)
{
    int tempo = 0;
    for (n = n - 1; n > 0; n--)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i] > v[i + 1])
            {
                tempo = v[i];
                v[i] = v[i + 1];
                v[i + 1] = tempo;
            }
        }
    }
    return v;
}