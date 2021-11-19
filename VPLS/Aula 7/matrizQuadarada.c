#include <stdio.h>

int main(void) {
    int n=0, col=0, lin=0, v1=0, v2=0;
    while (1)
    {
        scanf("%d", &n);
        if (n==0)
        {
            break;
        }
        
        for (lin = 0; lin < n; lin++) {
            for (col = 0; col < n; col++) {
                if (lin >col ) {
                    v1 = col + 1;
                    v2 = n-lin;
                }
                else {
                    v1 = lin + 1;
                    v2 = n-col;
                }
                if (v1 > v2) {
                    printf("%d ", v2);
                } 
                else {
                   printf("%d ", v1);
                }
            }
            printf("\n");
        }
    }
    return 0;
}