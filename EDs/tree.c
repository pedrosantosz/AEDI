#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
	char info;
	struct Tree *esq;
	struct Tree *dir;
} Tree;

Tree *inicializa();
Tree *cria(char c, Tree *e, Tree *d);
Tree *libera(Tree *raiz);
void preOrder(Tree *raiz);
void inOrder(Tree *raiz);
void postOrder(Tree *raiz);

int main() {
	Tree *raiz;

	Tree *d = cria('d', inicializa(), inicializa());
	Tree *e = cria('e', inicializa(), inicializa());
	Tree *b = cria('b', d, e);
	Tree *f = cria('f', inicializa(), inicializa());
	Tree *g = cria('g', inicializa(), inicializa());
	Tree *c = cria('c', f, g);

	raiz = cria('a', b, c);

	preOrder(raiz);
	printf("\n");
	inOrder(raiz);
	printf("\n");
	postOrder(raiz);

	return 0;
}

Tree *inicializa() {
	return NULL;
}

Tree *cria(char c, Tree *e, Tree *d) {
	Tree *t = (Tree *) malloc(sizeof(Tree));

	t->info = c;
	t->esq = e;
	t->dir = d;

	return t;
}

Tree *libera(Tree *raiz) {
	if (raiz != NULL) {
		libera(raiz->esq);
		libera(raiz->dir);
		free(raiz);
	}

	return NULL;
}

void preOrder(Tree *raiz) {
	if (raiz == NULL) {
		return;
	}

	printf("%c", raiz->info);
	preOrder(raiz->esq);
	preOrder(raiz->dir);
}

void inOrder(Tree *raiz) {
	if (raiz == NULL) {
		return;
	}

	inOrder(raiz->esq);
	printf("%c", raiz->info);
	inOrder(raiz->dir);
}

void postOrder(Tree *raiz) {
	if (raiz == NULL) {
		return;
	}

	postOrder(raiz->esq);
	postOrder(raiz->dir);
	printf("%c", raiz->info);
}