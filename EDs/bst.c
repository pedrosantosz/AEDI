#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int valor;
	struct No *esq;
	struct No *dir;
} No;

No *criarNo(int valor);
No *inserir(No *raiz, int valor);
No *buscar(No *raiz, int valor);
No *maximo(No *raiz);
No *remover(No *raiz, int valor);
void liberar(No *raiz);

void preOrdem(No *raiz);
void emOrdem(No *raiz);
void posOrdem(No *raiz);

int main() {
	No *raiz = NULL;

	raiz = inserir(raiz, 50);
	raiz = inserir(raiz, 30);
	raiz = inserir(raiz, 70);

	printf("Em ordem: ");
	emOrdem(raiz);

	No *teste = buscar(raiz, 7);
	if (teste)
		printf("\nachei: %d", teste->valor);
	else
		printf("\nn tem");

	raiz = remover(raiz, 2310);

	printf("\nEm ordem: ");
	emOrdem(raiz);
	
	liberar(raiz);

	return 0;
}

No *criarNo(int valor) {
	No *novo_no = (No *) malloc(sizeof(No));

	novo_no->valor = valor;
	novo_no->esq = NULL;
	novo_no->dir = NULL;

	return novo_no;
}

No *inserir(No *raiz, int valor) {
	if (raiz == NULL) {
		return criarNo(valor);
	}

	if (valor < raiz->valor) {
		raiz->esq = inserir(raiz->esq, valor);
	} else if (valor > raiz->valor) {
		raiz->dir = inserir(raiz->dir, valor);
	}

	return raiz;
}

No *buscar(No *raiz, int valor) {
	if (raiz == NULL) {
		return NULL;
	}

	if (valor == raiz->valor) {
		return raiz;
	} else if (valor < raiz->valor) {
		return buscar(raiz->esq, valor);
	}
	
	return buscar(raiz->dir, valor);
}

No *maximo(No *raiz) {
	while (raiz->dir != NULL) {
		raiz = raiz->dir;
	}
	return raiz;
}

No *remover(No *raiz, int valor) {
	if (raiz == NULL) {
		return NULL;
	}

	if (valor < raiz->valor) {
		raiz->esq = remover(raiz->esq, valor);
	} else if (valor > raiz->valor) {
		raiz->dir = remover(raiz->dir, valor);
	} else {
		// encontrei e:

		// se não tiver filhos à esquerda, pode ter filho à direita ou não, 
		// se não tiver à direita, vai retornar null, senão, retorna o que tiver na direita mesmo)
		if (raiz->esq == NULL) {
			No *filho = raiz->dir;
			free(raiz);
			return filho;
		}

		// se não tiver filhos à direita, já viu que não tem na esquerda
		if (raiz->dir == NULL) {
			No *filho = raiz->esq;
			free(raiz);
			return filho;
		}

		// se não cair em nenhum desses casos, tem os dois filhos

		No *sucessor = maximo(raiz->esq);
		raiz->valor = sucessor->valor;
		raiz->esq = remover(raiz->esq, sucessor->valor);
	}

	return raiz;
}

void liberar(No *raiz) {
	if (raiz != NULL) {
		liberar(raiz->esq);
		liberar(raiz->dir);
		free(raiz);
	}
}

void preOrdem(No *raiz) {
	if (raiz == NULL) {
		return;
	}

	printf("%d ", raiz->valor);
	preOrdem(raiz->esq);
	preOrdem(raiz->dir);
}

void emOrdem(No *raiz) {
	if (raiz == NULL) {
		return;
	}

	emOrdem(raiz->esq);
	printf("%d ", raiz->valor);
	emOrdem(raiz->dir);
}

void posOrdem(No *raiz) {
	if (raiz == NULL) {
		return;
	}

	posOrdem(raiz->esq);
	posOrdem(raiz->dir);
	printf("%d ", raiz->valor);
}