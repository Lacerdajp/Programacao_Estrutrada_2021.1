#include <stdio.h>
int main()
{
    int nvar = 0, n = 0, n_cem = 0, n_cinq = 0, n_vint = 0, n_dez = 0, n_cinco = 0, n_dois = 0, n_um = 0;
    const int cem = 100, cinq = 50, vint = 20, dez = 10, cinco = 5, dois = 2;
    printf("Digite o valor: \n");
    scanf("%d", &n);
    n_cem = n / cem;
    nvar = n % cem;
    n_cinq = nvar / cinq;
    nvar = nvar % cinq;
    n_vint = nvar / vint;
    nvar = nvar % vint;
    n_dez = nvar / dez;
    nvar = nvar % dez;
    n_cinco = nvar / cinco;
    nvar = nvar % cinco;
    n_dois = nvar / dois;
    n_um = (nvar % dois);
    printf("%d\n%d nota(s)de R$ 100,00\n%d nota(s)de R$ 50,00\n%d nota(s)de R$ 20,00\n%d nota(s)de R$ 10,00\n%d nota(s)de R$ 5,00\n%d nota(s)de R$ 2,00\n%d nota(s)de R$ 1,00", n, n_cem, n_cinq, n_vint, n_dez, n_cinco, n_dois, n_um);
    return 0;
}
