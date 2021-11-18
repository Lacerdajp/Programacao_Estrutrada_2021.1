#include<stdio.h>
int main(){
    int n=0, numbers[100], var1=0, var2=0;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&numbers[i]);
    }
    var1=numbers[n-1];
    for (int i = 0; i < n; i++)
    {
        if (i%2==0)
        {
            var2=numbers[i];
            numbers[i]=var1; 
        }
        else if (i%2!=0)
        {
            var1=numbers[i];
            numbers[i]=var2; 
        }
        printf("%d ", numbers[i]);
           }

    return 0;
}