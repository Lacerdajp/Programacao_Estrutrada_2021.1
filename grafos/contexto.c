/*
 * palavras.c
 *
 *  Created on: 4 de jul de 2022
 *      Author: correa
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "graph.h"

unsigned int maior_semantico(Graph * g) {
	size_t ret = 0;
	unsigned int iret;
	for (int i = 0; i < g->n; i++) {
		size_t d = grau(g, i);
		if (d > ret) {
			ret = d;
			iret = i;
		}
	}
	return ret;
}

void ordem_semantica_cresc(Graph * g, unsigned int * o) {
	size_t d[g->n];

	int cd(const void *a, const void *b) {
		return d[*((const unsigned int *) a)]-d[*((const unsigned int *) b)];
	}

	for (int i = 0; i < g->n; i++) {
		o[i] = i;
		d[i] = grau(g, i);
	}
	qsort(o, g->n, sizeof(unsigned int), cd);
}

void ordem_semantica_decresc(Graph * g, unsigned int * o) {
	size_t d[g->n];

	int cd(const void *a, const void *b) {
		return d[*((const unsigned int *) b)]-d[*((const unsigned int *) a)];
	}

	for (int i = 0; i < g->n; i++) {
		o[i] = i;
		d[i] = grau(g, i);
	}
	qsort(o, g->n, sizeof(unsigned int), cd);
}

int main(int argc, char *argv[])
{
	// Leitura do conjunto de vértices
	FILE* vertFile = fopen(argv[1], "r");
	char linestr[200];

	char * v = fgets(linestr, 20, vertFile);//lê de vl antes
	
	char * e;
	size_t n = strtol(v, &e, 10);//transforma em int
	if (v == e)
		return 0;//caso de merda

	char * legenda[n];
	int i = 0;

	v = fgets(linestr, 200, vertFile);//le de vl pos
	
	while (v != NULL) {
		size_t l = strlen(linestr);//pega o tamanho  v
		legenda[i] = calloc(l, sizeof(char));//armazena
		strncpy(legenda[i++], linestr, l);//muda de line str emanda pra legenda
		v = fgets(linestr, 200, vertFile);
	}
	fclose(vertFile);

	// Leitura do conjunto de arestas
	FILE* edgeFile = fopen(argv[2], "r");

	MAdj E[n * TAML(n)];
	memset(E, 0, WSIZE * n * TAML(n));
	Graph g_contexto = { n, legenda, E, TAML(n) };
	int j = 0;

	v = fgets(linestr, 200, edgeFile);//pega o valor de el
	
	while (v != NULL) {
		i = atoi(strtok(linestr, " "));//separa valores da linha
		j = atoi(strtok(NULL, " "));	  
	    adic_aresta(&g_contexto, i, j);//
		v = fgets(linestr, 200, edgeFile);
	}
	fclose(edgeFile);

    printf("Termo de maior valor semântico: %s", g_contexto.leg[maior_semantico(&g_contexto)]);
    printf("\nOrdem semântica crescente:\n");
    unsigned int ord[g_contexto.n];
    ordem_semantica_cresc(&g_contexto, ord);
    for (i = 0; i < g_contexto.n; i++)
    	printf("%s",g_contexto.leg[ord[i]]);
    printf("\nOrdem semântica decrescente:\n");
    ordem_semantica_decresc(&g_contexto, ord);
    for (i = 0; i < g_contexto.n; i++)
    	printf("%s",g_contexto.leg[ord[i]]);
	maior_context(&g_contexto); 

    return 0;
}
