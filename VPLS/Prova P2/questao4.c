#include<stdlib.h>
#include <stdio.h>
typedef struct
{
    int *lista;
    int size;
} VETOR;

VETOR * ordena(VETOR *a) {  
    VETOR * ordem;
    int temp = 0;
    ordem->lista= (int*)malloc(a->size*sizeof(int));
    ordem->size= a->size;
    for (int z = 0; z < a->size; z++)
    {
    for (int z = 0; z < a->size; z++)
    {
        if (a->lista[z]>a->lista[z+1])
        {
           temp=a->lista[z];
           a->lista[z]=a->lista[z+1];
           a->lista[z+1]=temp;
        }
                
    }
    }
    for (int i = 0; i < a->size; i++)
    {
    
        ordem->lista[i]=a->lista[i];
    }
    return ordem;
}