/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: flavio
 *
 * Created on 10 de Novembro de 2018, 15:21
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct noArvore_ noArvore;

struct noArvore_ {
	int valor;
	noArvore * esq;
	noArvore * dir;
};

/**
 * funcao pre ordem recursiva.
 * @param raiz = ponteiro para a raiz da arvore.
 */
void pre_ordem(noArvore * raiz) {
	if (raiz) {
		printf("%d ", raiz->valor);
		pre_ordem(raiz->esq);
		pre_ordem(raiz->dir);
	}
}

/**
 * funcao em ordem recursiva.
 * @param raiz = ponteiro para a raiz da arvore.
 */
void em_ordem(noArvore * raiz) {
	if (raiz) {
		em_ordem(raiz->esq);
		printf("%d ", raiz->valor);
		em_ordem(raiz->dir);
	}
}

/**
 * funcao pos ordem recursiva.
 * @param raiz = ponteiro para a raiz da arvore.
 */
void pos_ordem(noArvore * raiz) {
	if (raiz) {
		pos_ordem(raiz->esq);
		pos_ordem(raiz->dir);
		printf("%d ", raiz->valor);
	}
}

/**
 * funcao que desaloca a arvore.
 * @param arvore = ponteiro para a raiz da arvore.
 */
void desaloca(noArvore * arvore) {
	noArvore * n = arvore;
	if (n != NULL) {
		desaloca(n->esq);
		desaloca(n->dir);
		free(n);
	}
}

/**
 * funcao que insere valores na arvore.
 * @return = ponteiro para a raiz da arvore.
 */
noArvore * insere(noArvore * raiz, noArvore * n) {
	if (raiz == NULL) return n;
	if (raiz->valor > n->valor)
		raiz->esq = insere(raiz->esq, n);
	else
		raiz->dir = insere(raiz->dir, n);
	return raiz;
}

/**
 * 
 * @param r = raiz da arvore
 * @param k = valor a ser buscado
 * @return no contendo o valor, ou null caso nao encontre
 */
noArvore * busca(noArvore * raiz, int k) {
	if (raiz == NULL || raiz->valor == k)
		return raiz;
	if (raiz->valor > k)
		return busca(raiz->esq, k);
	else
		return busca(raiz->dir, k);
}

noArvore * removeRaiz(noArvore * r) {
	noArvore *p, *q;
	if (r->esq == NULL) {
		q = r->dir;
		free(r);
		return q;
	}
	p = r;
	q = r->esq;
	while (q->dir != NULL) {
		p = q;
		q = q->dir;
	}
	// q é nó anterior a r na ordem e-r-d, p é pai de q
	if (p != r) {
		p->dir = q->esq;
		q->esq = r->esq;
	}
	q->dir = r->dir;
	free(r);
	return q;
}

noArvore * buscaPai(noArvore * raiz, noArvore * n) {
	if (raiz == n)
		return NULL;

	if (raiz->esq == n || raiz->dir == n)
		return raiz;
	else {
		if (raiz->valor > n->valor)
			return buscaPai(raiz->esq, n);
		else
			return buscaPai(raiz->dir, n);
	}
}

noArvore * removeNo(noArvore * raiz, int valor) {
	noArvore * n = busca(raiz, valor);
	if (n) {
		noArvore * pai = buscaPai(raiz, n);
		if (pai) {
			if (pai->dir == n)
				pai->dir = removeRaiz(n);
			else
				pai->esq = removeRaiz(n);
		} else {
			raiz = removeRaiz(n);
		}
	}
	return raiz;
}

int main() {
	noArvore * arvore = NULL;

	char ans = 's';

	while (ans != 'n') {
		noArvore * n = malloc(sizeof (noArvore));
		printf("Valor: ");
		scanf("%d", &(n->valor));
		getchar();
		arvore = insere(arvore, n);

		printf("Inserir mais (s/n): ");
		scanf("%c", &ans);
	}

	printf("pre_ordem: ");
	pre_ordem(arvore);
	printf("\n");

	printf("em_ordem: ");
	em_ordem(arvore);
	printf("\n");

	printf("pos_ordem: ");
	pos_ordem(arvore);
	printf("\n");

	/*printf("Remove Raiz: \n");
	arvore = removeRaiz(arvore);*/

	printf("Remove no: \n");
	arvore = removeNo(arvore, 15);

	printf("em_ordem: ");
	em_ordem(arvore);
	printf("\n");

	printf("pre_ordem: ");
	pre_ordem(arvore);
	printf("\n");

	desaloca(arvore);
	return (EXIT_SUCCESS);
}

