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
					strcpy(nomes, nome); 										// preciso do cpy pra limpar a "sujeira"
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

				char nome[20];
				printf("Nome: ");
				scanf("%s", nome);

				int i, j = 0, comeco = 0, fim = 0;
			    int encontrado = 0;

			    for (i = 0; nomes[i] != '\0'; i++) {
			        if (nomes[i] == nome[j]) {                        // se as letras forem iguais
			            if (j == 0)                                   // salvo onde comeca
			                comeco = i;
			            j++;                                          // passo pra proxima letra
			        }  else if (nomes[i] == ';' && nome[j] == '\0'){  // se as letras forem diferentes, mas o nome ja tiver chegado no final
			            encontrado = 1;
			            fim = i;
			            break;
			        } else {                                          // caso sejam diferentes, mas o nome nao chegou no final ainda
			            j = 0;                                        // os nomes sao diferentes, e entao recomeca a checagem
			        }
			    }

				if (encontrado) {
					for (i = comeco; nomes[fim + 1] != '\0'; i++) { // (fim sempre vai ser um ';') -- deslocamento da string
			            nomes[i] = nomes[fim + 1];
			            fim++;
			        }
			        nomes[i] = '\0';								// finalizador da string quando terminar de deslocar

					qtd_nomes--;
					
					nomes = (char *) realloc(nomes, ((strlen(nomes) + 1) * sizeof(char)));
				}
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