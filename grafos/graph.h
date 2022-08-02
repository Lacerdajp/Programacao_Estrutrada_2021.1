/*
 * graph.h
 *
 *  Created on: 4 de jul de 2022
 *      Author: correa
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdint.h>

typedef uint64_t NODETYPE; //!< bitmap node's type
#define BSIZE 64
#define WSIZE 8
#define LOGB 6LL
#define NODEMAX 0xFFFFFFFFFFFFFFFF

// Macros para criar tabela de quantidade de bits em 1 byte
#define B2(n) n, n + 1, n + 1, n + 2
#define B4(n) B2(n), B2(n + 1), B2(n + 1), B2(n + 2)
#define B6(n) B4(n), B4(n + 1), B4(n + 1), B4(n + 2)
#define QUANT_BITS B6(0), B6(1), B6(1), B6(2)

// tabela de quantidade de bits em 1 em um byte.
const unsigned int __qbits_tab[256] = { QUANT_BITS };

#define D2(n) ((NODETYPE) n) << 1, ((NODETYPE) n) << 2, ((NODETYPE) n) << 3, ((NODETYPE) n) << 4

static const NODETYPE __mascarab[BSIZE+1] = {
	0x00000000000000FF,
	0x000000000000FF00,
	0x0000000000FF0000,
	0x00000000FF000000,
	0x000000FF00000000,
	0x0000FF0000000000,
	0x00FF000000000000,
	0xFF00000000000000
};

static const NODETYPE __mascara1[BSIZE+1] = {
	(NODETYPE) 0x0000000000000001,
	D2(0x0000000000000001),
	D2(0x0000000000000010),
	D2(0x0000000000000100),
	D2(0x0000000000001000),
	D2(0x0000000000010000),
	D2(0x0000000000100000),
	D2(0x0000000001000000),
	D2(0x0000000010000000),
	D2(0x0000000100000000),
	D2(0x0000001000000000),
	D2(0x0000010000000000),
	D2(0x0000100000000000),
	D2(0x0001000000000000),
	D2(0x0010000000000000),
	D2(0x0100000000000000),
	D2(0x1000000000000000)
};

#define TAML(n) ((n >> LOGB) + 1)

typedef NODETYPE MAdj;

/*!
 * \struct Graph
 * \brief Bitmap implementation of a graph adjacency matrix.
 *
 * In order to optimize indexing, the number of nodes in a row is augmented up to a power of 2.
 */
typedef struct {
	int			n;
	char ** 	leg;
	MAdj *		E;
	int			tamL;
} Graph;

/*!
 * \fn size_t card(const NODETYPE * a, int nb)
 * \brief Determina cardinalidade de um conjunto representado por mapa de bits.
 *
 * \param a Mapa de bits
 * \param nb Quantidade de nacos no mapa de bits
 *
 * \return Quantidade de bits em 1 em \c a[0 ... nb-1].
 */
static inline size_t card(const NODETYPE * a, int nb)
{
    size_t ret = 0;
    // percorre bytes do mapa de bits
    for (int w = 0; w < nb; w++)
    for (int i = 0; i < LOGB; i++)
        ret += (size_t) __qbits_tab[(a[w] & __mascarab[i]) >> (i << 3)];    // i-esimo byte
    return ret;
}

/*!
 * \fn NODETYPE const * vizinhanca(Graph * g, unsigned int i)
 * \brief Obtém vizinhança de um vértice em um grafo.
 *
 * \param g Grafo
 * \param i Vértice
 *
 * \return Bitmap corresponding to the neigborhood of \c i in \c g.
 */
static inline NODETYPE * vizinhanca(Graph * g, unsigned int i) {
	return g->E + i * g->tamL;
}

/*!
 * \fn int grau(Graph * g, unsigned int i)
 * \brief Obtém grau de um vértice em um grafo.
 *
 * \param g Grafo
 * \param i Vértice
 *
 * \return Valor do grau de \c i em \c g.
 */
static inline size_t grau(Graph * g, unsigned int i) {
	NODETYPE const * N = vizinhanca(g, i);
	return card(N, g->tamL);
}

/*!
 * \fn void adic_aresta(Graph * g, unsigned int i, unsigned int j)
 * \brief Adiciona aresta especificada pelas suas extremidades a um grafo. Caso alguma das
 * extremidades não seja um vértice do grafo, o resultado da operação é indeterminado.
 *
 * \param g Grafo
 * \param i Uma extremidade da aresta
 * \param j Outra extremidade da aresta
 *
 */
static inline void adic_aresta(Graph * g, unsigned int i, unsigned int j) {
	unsigned int l = j >> LOGB;
	unsigned int k = j - (l << LOGB);
	g->E[l + i * g->tamL] |= __mascara1[k];
	l = i >> LOGB;
	k = i - (l << LOGB);
	g->E[l + j * g->tamL] |= __mascara1[k];
}

/*!
 * \fn void viz_comum(Graph * g, unsigned int i, unsigned int j)
 * \brief Determina vizinhança comum a dois vértices em um grafo. Caso algum dos
 * vértices não esteja no grafo, o resultado da operação é indeterminado.
 *
 * \param g Grafo
 * \param i Um vértice
 * \param j Outro vértice
 * \param N Mapa de bits a preencher com a vizinhaça comum a \c i e \c j
 *
 */
static inline NODETYPE * reter(NODETYPE* s,NODETYPE * r,int nb ){
	
	int i=0;
	for ( i = 0; i < nb ; i++)
	{
		s[i]=s[i] & r[i];
	}
	return s;
}
static inline void  viz_comum(Graph * g, unsigned int i, unsigned int j, NODETYPE* N) {
	NODETYPE * s = vizinhanca(g,i);
	NODETYPE * r=vizinhanca(g,j);
	N=reter(s,r,g->tamL);
}


unsigned int maior_context(Graph* context){
	size_t maior=0;
	NODETYPE* n;
	size_t  k;
	size_t maiorI;
	size_t maiorJ;
	for (int i = 0; i < context->n; i++)
	{
		for (int j = 0; j < context->n; j++)
		{
		   if (i!=j)
		   {
				viz_comum(context,i,j,n);
				k=card(n,context->n);
				if (k>maior){
					maior=k;
					maiorI=i;
					maiorJ=j;
				}
		   }
		}
	}
	printf("Maior contexto comum: \n%s \n%s",context->leg[maiorI],context->leg[maiorJ]);
	
}


#endif /* GRAPH_H_ */
