#include<stdio.h>
#include <stdint.h>
int main(){

    char name[100];
    float n1=0,n2=0;
    int ent=0;
    FILE*a;
    a=fopen("mediaAluno.txt","r");
    fscanf(a,"%d",&ent);
    for (int i = 0; fgets(name,100,a); i++)
    {
        fscanf(a,"%f %f",&n1,&n2);

        if (((n1+n2)/2.0)>7)
        {
            printf("%s",name);
        }
        
    }
    fclose(a);
    return 0;
}