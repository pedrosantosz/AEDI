#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 3

typedef struct {
	char nome[50];
	int idade;
} Aluno;

typedef struct {
	Aluno alunos[MAX];
	int topo;
	int base;
	int limite;
} Pilha;

void Reset ( Pilha *pilha );
bool Push ( Pilha *pilha, Aluno aluno );
bool Pop ( Pilha *pilha, Aluno *aluno );
void Clear( Pilha *pilha );
void List ( Pilha *pilha );
void List2 ( Pilha *pilha );

int main() {
	Pilha s_alunos;

	Reset( &s_alunos );

	int op;

	do {
		printf("\n1. Inserir\n2. Deletar\n3. Limpar\n4. Listar\n5. Sair");
		printf("\nOperacao: ");
		scanf("%d", &op);
		getchar();


		switch (op) {
			case 1: {
				Aluno novo_aluno;
				
				printf("\nNome: ");
				scanf("%s", novo_aluno.nome);
				
				printf("Idade: ");
				scanf("%d", &novo_aluno.idade);

				if (!Push(&s_alunos, novo_aluno)) {
					printf("\nPilha Cheia!\n");
				}
				break;
			}
			case 2: {
				Aluno aluno_atual;
				
				if (Pop(&s_alunos, &aluno_atual)) {
					printf("\n%s\n", aluno_atual.nome);
					printf("%d\n", aluno_atual.idade);
				} else {
					printf("\nPilha Vazia!\n");
				}
				
				break;
			}
			case 3:
				Clear(&s_alunos);
				break;
			case 4: 
				List2(&s_alunos);
				break;
			case 5: 
				break;
			default: 
				break;
		}

	} while (op != 5);
	
	return 0;
}

void Reset ( Pilha *pilha ) {
	pilha->topo = 0;
	pilha->base = 0;
	pilha->limite = MAX;
}

bool Push ( Pilha *pilha, Aluno aluno ) {
	if ( pilha->topo != pilha->limite ) {
		pilha->alunos[pilha->topo] = aluno;
		pilha->topo++;

		return true;
	}

	return false;
}

bool Pop ( Pilha *pilha, Aluno *aluno ) {
	if ( pilha->topo != 0 ) {
		pilha->topo--;

		*aluno = pilha->alunos[pilha->topo];

		return true;
	}

	return false;
}

void Clear( Pilha *pilha ) {
	Aluno removido;
	while ( pilha->topo  != pilha->base) {
		Pop(pilha, &removido);
	}
}

void List ( Pilha *pilha ) {
	for (int i = pilha->topo - 1; i >= pilha->base; i--) {
		printf("\nAluno %d:\n", i + 1);
		printf("\tNome: %s\n", pilha->alunos[i].nome);
		printf("\tIdade: %d\n", pilha->alunos[i].idade);
	}
}

void List2 ( Pilha *pilha ) {
	Pilha pilha_aux;

	Reset(&pilha_aux);

	while ( pilha->topo != pilha->base ) {
		Aluno aluno_aux;

		printf("\nAluno: %d\n", pilha->topo - 1);

		Pop(pilha, &aluno_aux);

		printf("\tNome: %s\n", aluno_aux.nome);
		printf("\tIdade: %d\n", aluno_aux.idade);

		Push(&pilha_aux, aluno_aux);
	}

	while ( pilha_aux.topo != pilha_aux.base ) {
		Aluno aluno_aux;

		Pop(&pilha_aux, &aluno_aux);

		Push(pilha, aluno_aux);
	}
}