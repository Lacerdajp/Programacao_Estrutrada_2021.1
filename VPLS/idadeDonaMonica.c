#include <stdio.h>
int main()
{
    int M = 0, A = 0, B = 0, C = 0;

    printf("Digite a idade de Dona Monica:\n");
    scanf("%d", &M);
    printf("Digite de um de seus filhos:\n");
    scanf("%d", &A);
    printf("Digite do outro filho:\n");
    scanf("%d", &B);
    40 <= M <= 110;
    1 <= A < M;
    1 <= B < M;
    A != B;
    C = M - A - B;
    printf("A idade do filho mais velho e : %d", C);
    return 0;
}