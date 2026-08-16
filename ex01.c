#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int op = 0;
	int qtd_nomes = 0;

	char *nomes = NULL;

	while (op != 4) {
		printf("\n1. Adicionar Nome\n2. Remover Nome\n3. Listar\n4. Sair\nOperacao: ");
		scanf("%d", &op);

		switch(op) {
			case 1: {
				char nome[20];
				printf("Nome: ");
				scanf("%s", nome);

				if (qtd_nomes == 0) {
					nomes = (char *) malloc((strlen(nome) + 2) * sizeof(char)); // +2 (separador e terminador)
					strcpy(nomes, nome); // preciso do cpy pra limpar a "sujeira"
				} else {
					nomes = (char *) realloc(nomes, (strlen(nomes) + strlen(nome) + 2) * sizeof(char)); 
					strcat(nomes, nome);
				}

				strcat(nomes, ";");
				qtd_nomes++;
				break;
			}
			case 2: {
				if (nomes == NULL)
					break;

				int nomes_buscados = 0, encontrado = 0;
				char nome[20], *busca, *aux;
				printf("Nome: ");
				scanf("%s", nome);

				aux = (char *) malloc((strlen(nomes) + 1) * sizeof(char)); // solucao temporaria
				strcpy(aux, nomes);

				busca = strtok(aux, ";");

				while (busca != NULL) {
					if (strcmp(nome, busca) != 0) {
						if (nomes_buscados == 0) // se for o primeiro nome, preciso copiar, nao concatenar (diminui a string)
							strcpy(nomes, busca);
						else
							strcat(nomes, busca);
						strcat(nomes, ";");
						nomes_buscados++;
					} else {
						encontrado = 1;
					}

					busca = strtok(NULL, ";");
				}

				if (encontrado) {
					qtd_nomes--;
					if (nomes_buscados == 0) // nomes tinha um unico nome que foi excluido
						nomes[0] = '\0';
					nomes = (char *) realloc(nomes, (strlen(nomes) + 1) * sizeof(char));
				}
				free(aux);
				break;
			}
			case 3: {
				for (int i = 0; nomes != NULL && nomes[i] != '\0'; i++){
					if (nomes[i] != ';')
						printf("%c", nomes[i]);
					else
						printf(" ");
				}
				break;
			} 
			default: {
				break;	
			}
		}
	}

	return 0;
}