#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	char nome[50];
	int idade;
} Aluno;

typedef struct {
	Aluno *alunos;
	int *topo;
	int *base;
	int tamanho;
} Pilha;

void Reset ( );
bool Push (  );
bool Pop (  );
void List (  );

int main() {
	Pilha *s_alunos;

	Reset( s_alunos );

	int op;

	do {
		printf("\n1. Inserir\n2. Deletar\n3. Limpar\n4. Listar\n5. Sair");
		printf("\nOperacao: ");
		scanf("%d", &op);
		getchar();


		switch (op) {
			case 1:
				break;
			case 2: 
				break;
			case 3: 
				break;
			case 4:
				break;
			case 5: 
				break;
			default: 
				break;
		}

	} while (op != 5);
	
	return 0;
}

void Reset (  ) {

}

bool Push (  ) {

}

bool Pop (  ) {

}

void Listar (  ) {

}