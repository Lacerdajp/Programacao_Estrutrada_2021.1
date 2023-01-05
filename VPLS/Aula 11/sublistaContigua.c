#include <stdio.h>
#define MAX 1000

typedef struct
{
    int vetor[MAX];
    int n;

} ARRAY;
int sublista(int v[]);
int main(){
   ARRAY array;
	array.n = 0;
    return 0;
}
int elemento(ARRAY *array, int posicao)
{
	return array->vetor[posicao];
}

int tamanho(ARRAY *array)
{
	return array->n;
}

void insere(ARRAY *array, int elemento)
{
    array->vetor[tamanho(array)] = elemento;
    array->n += 1;
}

void remove_posicao(ARRAY *array, int posicao)
{
	if(tamanho(array) == 0)
	{
		return;
	}
	else if(tamanho(array) == 1)
	{
		array->n -= 1;
		return;
	}
	else
	{
		array->n -= 1;
		array->vetor[posicao] = array->vetor[tamanho(array)];
	}
}

void remove_elemento(ARRAY *array, int valor)
{
	int i;

	for(i = 0; i < tamanho(array); i++)
	{
		if(elemento(array, i) == valor)
		{
			remove_posicao(array, i);
		}
	}
}

void imprime(ARRAY *array)
{
	int i;

	printf("Vetor: ");

	for(i = 0; i < tamanho(array); i++)
	{
		if(i != tamanho(array) - 1)
			printf("%d, ", elemento(array, i));
		else
			printf("%d", elemento(array, i));
	}

	printf("\n");
}

int sublista(int v[]){
}