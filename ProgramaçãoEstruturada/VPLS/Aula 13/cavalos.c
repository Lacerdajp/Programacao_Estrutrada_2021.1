#include<stdio.h>

int main(){

    int baias[16]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43 , 47};
    int c,somaMaior = 0, prancha, primeira;
	for(int i = 0; baias[i] != '\0'; i++)
	{	
		c = 0;
		prancha = baias[i] + 19;
		for(int j = i; baias[j] != '\0'; j++)
		{
			if(baias[j] <= prancha &&  baias[j] >= baias[i])
			{
				c++;
			}
		}
		if(c > somaMaior)
		{
			somaMaior = c;
			primeira= i;
		}
	}
	printf("maior = %d inicio %d\n", somaMaior, primeira);
	return 0;
}
