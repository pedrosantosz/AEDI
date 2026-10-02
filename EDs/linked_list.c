#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[40];
	int idade;
} SDado;

typedef struct SNodo {
	SDado info;
	struct SNodo *pNext;
} SNodo;

typedef struct {
	SNodo *pFirst;
} SLista;

SDado LeDado();

SLista *CriaLista();
int Adiciona(SLista *Lista, SDado dado);
void Listar(SLista *Lista);

int main() {
	SLista *Alunos;
	Alunos = CriaLista();

	SDado novo_dado = LeDado();
	Adiciona(Alunos, novo_dado);

	novo_dado = LeDado();
	Adiciona(Alunos, novo_dado);

	novo_dado = LeDado();
	Adiciona(Alunos, novo_dado);

	Listar(Alunos);
	
	return 0;
}

SDado LeDado() {
	SDado novo_dado;

	printf("Nome: ");
	scanf("%[^\n]s", novo_dado.nome);
	getchar();
	
	printf("Idade: ");
	scanf("%d", &novo_dado.idade);
	getchar();

	return novo_dado;
}

SLista *CriaLista() {
	SLista *Lista;
	Lista = (SLista *) malloc(sizeof(SLista));
	Lista->pFirst = NULL;

	return Lista;
}

int Adiciona(SLista *Lista, SDado dado) {
	SNodo *novo_no = (SNodo *) malloc(sizeof(SNodo));
	
	if (novo_no == NULL) {
		return 0;	
	}
	novo_no->info = dado;
	novo_no->pNext = Lista->pFirst;

	Lista->pFirst = novo_no;

	return 1;
}

void Listar(SLista *Lista) {
	printf("\nLista: \n");
	for(SNodo *atual = Lista->pFirst; atual != NULL; atual = atual->pNext) {
		printf("%s, ", atual->info.nome);
		printf("%d\n", atual->info.idade);
	}
}