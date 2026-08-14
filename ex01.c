#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int op = 0;
	int qtd_nomes = 0;

	char *nomes;

	while (op != 4) {
		printf("1. Adicionar Nome\n2. Remover Nome\n3. Listar\n4. Sair\nOperacao: ");
		scanf("%d", &op);

		switch(op) {
			case 1:
				char nome[20];
				printf("Nome: ");
				scanf("%s", nome);
				if (qtd_nomes == 0)
					nomes = (char *) malloc((strlen(nome) + 1) * sizeof(char));
				else {
					realloc(nomes, (strlen(nomes) + strlen(nome) + 2) * sizeof(char));
					strcat(nomes, ";"); // separador
				}

				// adicionar nome
				strcat(nomes, nome);

				qtd_nomes++;
				break;
			case 2:
				// remover nome (strtok?)
				char nome[20];
				printf("Nome: ");
				scanf("%s", nome);

				int tamanho = strlen(nome);

				for (int i = 0; nomes[i] != '\0'; i++) {
					nome = strtok(nomes, ";");

					// fico salvando o strtok atual em nomes e dando realloc, se encontrar igual, nao da realloc naquela vez
					// no final ou eu vou refazer a string inteira, ou eu vou refazer ela pulando o nome

				}
				// se encontrado: qtd_nomes--;
				break;
			case 3:
				printf("%s\n", nomes);
				break;
			default:
				break;	
		}
	}

	return 0;
}
