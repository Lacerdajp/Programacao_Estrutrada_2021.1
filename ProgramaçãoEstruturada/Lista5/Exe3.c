#include <stdio.h>
int main()
{
    int p, q, r;
    printf("%s\t%s\t%s\t%s\t%s\t%s\n", "p", "q", "r", "p->q", "q->r", "(p->q)^(q->r)");
    p = 0, q = 0, r = 0;
    printf("%d\t%d\t%d\t%d\t%d\t%d\n", p, q, r, !p || q, !q || r, (!p || q) && (!q || r));
    p = 0, q = 0, r = 1;
    printf("%d\t%d\t%d\t%d\t%d\t%d\n", p, q, r, !p || q, !q || r, (!p || q) && (!q || r));
    p = 0, q = 1, r = 0;
    printf("%d\t%d\t%d\t%d\t%d\t%d\n", p, q, r, !p || q, !q || r, (!p || q) && (!q || r));
    p = 0, q = 1, r = 1;
    printf("%d\t%d\t%d\t%d\t%d\t%d\n", p, q, r, !p || q, !q || r, (!p || q) && (!q || r));
    p = 1, q = 0, r = 0;
    printf("%d\t%d\t%d\t%d\t%d\t%d\n", p, q, r, !p || q, !q || r, (!p || q) && (!q || r));
    p = 1, q = 0, r = 1;
    printf("%d\t%d\t%d\t%d\t%d\t%d\n", p, q, r, !p || q, !q || r, (!p || q) && (!q || r));
    p = 1, q = 1, r = 0;
    printf("%d\t%d\t%d\t%d\t%d\t%d\n", p, q, r, !p || q, !q || r, (!p || q) && (!q || r));
    p = 1, q = 1, r = 1;
    printf("%d\t%d\t%d\t%d\t%d\t%d\n", p, q, r, !p || q, !q || r, (!p || q) && (!q || r));
    return 0;
}