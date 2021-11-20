#include <stdio.h>
int main(){
    //4 == a,  4==A  A==a  3==E  3==e E==e 1==I 1==i I==i o==0 O==0 O==o  2=Z 2=z z=Z
    int n=0,tc=0;
    int test =0 ,erro=0;
    int var=0;
    char string1[11],string2[11];
    do
    {
        scanf("%d",&n);
    } while (n<=0||n>10);
   
    for (int i = 0; i < n; i++)
    {
       tc=0;
        erro=0;
        do
        {
            scanf("%d",&tc);
           
        } while (tc<=0||tc>10); 
       
        for (int z = 0; z < 4; z++)
        {
           
            if (z==0)
            {
               
                    for (int f = 0; f < 11; f++)
                    {
                        string1[f]=0;
                    }
                    scanf("%s",string1);
                    for (int f = 0; f < 11; f++)
                    {   
                        if ((f>tc-1)&& (string1[f]!=0))
                        {
                            printf("Voce nao cumpriu os termos.Digite novamentes \n"); 
                            z--;
                
                        }
                        
                       
                    }
            }else{ 
                    test=0;                    
                    for (int f = 0; f < 11; f++)
                    {
                        string2[f]=0;
                    }
                     scanf("%s",string2);
                    for (int f = 0; f < 11; f++)
                    {   
                        if ((f>tc-1)&& (string2[f]!=0))
                        {
                            printf("Voce nao cumpriu os termos.Digite novamentes \n"); 
                            z--;
                        }
                        
                       
                    }
                      for (int f = 0; f < tc; f++)
                    {   
                        if (string1[f]==string2[f])
                        {
                            test++;
                        }
                        else if ((string1[f ]=='a'||string1[f]=='4'||string1[f]=='A')&&(string2[f]=='a'||string2[f]=='4'||string2[f]=='A'))
                        {
                            test++;
                        }else if ((string1[f]=='e'||string1[f]=='3'||string1[f]=='E')&&(string2[f]=='e'||string2[f]=='3'||string2[f]=='E'))
                        {
                            test++;
                        }else if ((string1[f]=='i'||string1[f]=='1'||string1[f]=='I')&&(string2[f]=='i'||string2[f]=='1'||string2[f]=='I'))
                        {
                            test++;
                        }else if ((string1[f]=='o'||string1[f]=='0'||string1[f]=='O')&&(string2[f]=='o'||string2[f]=='0'||string2[f]=='O'))
                        {
                            test++;
                        }else if ((string1[f]=='z'||string1[f]=='2'||string1[f]=='Z')&&(string2[f]=='z'||string2[f]=='2'||string2[f]=='Z'))
                        {
                            test++;
                        }  
                    }
                
                    if (test!=(tc))
                    {
                        erro++;
                    }   
                }
            }   
            if (erro==0)
                {
                    printf("S\n");
                }
                else{
                    printf("N\n");
                }
    }
    return 0;
}