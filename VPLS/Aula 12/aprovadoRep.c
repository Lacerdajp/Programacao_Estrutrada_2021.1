#include<stdio.h>
#include <stdint.h>
int main(){

    char name[50],lastName[50];
    float n1=0,n2=0,media=0;
    FILE*a;
    a=fopen("mediaAluno.txt","r");
    for (int i = 0; fscanf(a, "%s %s;", name, lastName)!=EOF ; i++)

    {
        for (int i = 0; i < 50; i++)
        {
            if (lastName[i]==';')
            {
                lastName[i]=0;
            }
            
        }
        fscanf(a,"%f ;%f;",&n1,&n2);
        media=(n1+n2)/2.0;
        printf("%s %s %.1f %.1f %.1f ",name,lastName,n1,n2,media);
        printf(media>=5 ? "aprovado\n":"reprovado\n");
    }
    fclose(a);
    return 0;
}