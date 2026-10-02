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
	SNodo *topo;
	int total;
} SPilha;

SDado LeDado();

SPilha *CriaPilha();
int Push(SPilha *Pilha, SDado dado);
int Pop(SPilha *Pilha, SDado *dado);
void Top(SPilha *Pilha);
void Clear(SPilha *Pilha);
int StackSize(SPilha *Pilha);
void Listar(SPilha *Pilha);

int main() {
	SPilha *Alunos;
	Alunos = CriaPilha();

	int op;
	do {
		printf("\n1.Adicionar\n2.Remover\n3.Listar\n4.Topo\n5.Limpar\n0.Sair\n");
		printf("Escolha: ");
		scanf("%d", &op);
		getchar();

		switch (op) {
			case 1: {
				SDado novo_dado = LeDado();
				Push(Alunos, novo_dado);
				break;
			}
			case 2: {
				SDado dado_excluido;
				Pop(Alunos, &dado_excluido);
				printf("\n%s\n", dado_excluido.nome);
				break;
			}

			case 3:
				Listar(Alunos);
				break;
			case 4:
				Top(Alunos);
				break;
			case 5:
				Clear(Alunos);
				break;
			default:
				break;
		}
	} while (op != 0);
	return 0;
}

SDado LeDado() {
	SDado novo_dado;

	printf("\nNome: ");
	scanf("%[^\n]s", novo_dado.nome);
	getchar();
	
	// printf("Idade: ");
	// scanf("%d", &novo_dado.idade);
	// getchar();

	return novo_dado;
}

SPilha *CriaPilha() {
	SPilha *Pilha;
	Pilha = (SPilha *) malloc(sizeof(SPilha));
	
	Pilha->topo = NULL;
	Pilha->total = 0;

	return Pilha;
}

int Push(SPilha *Pilha, SDado dado) {
	SNodo *novo_no = (SNodo *) malloc(sizeof(SNodo));
	
	if (novo_no == NULL) {
		return 0;	
	}

	novo_no->info = dado;
	novo_no->pNext = Pilha->topo;
	Pilha->topo = novo_no;
	
	Pilha->total++;

	return 1;
}

int Pop(SPilha *Pilha, SDado *dado) {
	if (Pilha->topo == NULL) {
		return 0;
	}
	
	SNodo *no_descartado;
	no_descartado = Pilha->topo;
	
	*dado = no_descartado->info;

	Pilha->topo = no_descartado->pNext;
	Pilha->total--;

	free(no_descartado);

	return 1;
}

void Top(SPilha *Pilha) {
	if (Pilha->topo == NULL) {
		printf("\nPilha Vazia!\n");
		return;
	}
	
	printf("\n%s\n", Pilha->topo->info.nome);
}

void Clear(SPilha *Pilha) {
	if (Pilha->topo == NULL)
		return;
	
	SDado aux;
	while (Pop(Pilha, &aux));
}

int StackSize(SPilha *Pilha) {
	return Pilha->total;
}

void Listar(SPilha *Pilha) {
	printf("\nLista: \n");
	for(SNodo *atual = Pilha->topo; atual != NULL; atual = atual->pNext) {
		printf("%s\n", atual->info.nome);
		// printf("%d\n", atual->info.idade);
	}
}