#include <stdio.h>
int main(){
    //1900 é bissexto somar 4 anos
    //
    int  n=0, somadia=0,somames=0,somatotal=0;; 
    int d1=0,d2=0, m1=0,m2=0, ano=0;
    char c[10];
    do
    {
        printf("Digite o valor de entradas: ");
        scanf("%d",&n);
    } while (n<=0||n>10);
    for (int i = 0; i < n; i++)
    {
        d1=0,d2=0, m1=0,m2=0, ano=0;
        do
        {printf("Digite os valores solicitados: ");
        scanf("%d %d%c %d %d %d",&d1,&m1,&c[i],&d2,&m2,&ano);
        } while ((ano>2099||ano<1900)&&(m1>12||m1<=0)&&(m2>12||m2<=0)&&(d2>31||d2<=0)&&(d1>31||d1<=0));
        
       
            somadia=d1-d2;
           
        
        if (m2==4||m2==6||m2==9||m2==11 )
        { 
            somames=(m1-m2)*30;
              
        }else if ( m2==1||m2==3||m2==5||m2==7||m2==8||m2==10||m2==12)
        {
            somames=(m1-m2)*31;
        }else if (m2==2)
        {
            if (ano%4==0)
            {
                somames= (m1-m2)*29;
            }else{
                somames= (m1-m2)*28;
            }
            
        }
     

      
        if ((somadia+somames)<0)
        {
             if (ano%4==0)
            {
               somatotal=somadia+somames+366;
            }else{
                somatotal=somadia+somames+365;
            }
           
        }
        else{
            somatotal=somadia+somames;
        }
        
    
       printf("%d\n",somatotal);

        
    }
    

    return 0;
}