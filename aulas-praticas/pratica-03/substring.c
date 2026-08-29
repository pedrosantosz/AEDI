#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int EhPalindromo(char *s);
char *Substring(char *s);

int main () {
	// char *s1 = "sbabbabs";
	char s1[40] = "";

	do {
		
		printf("Palavra: ");
		scanf("%s", s1);

		char *s2 = Substring(s1);
		printf("\n%s\n", s2);
	} while (strcmp(s1, "sair"));
	
	return 0;
}

int EhPalindromo(char *s) {
	char *palavra = (char *) malloc(sizeof(char) * (strlen(s) + 1));

	int i,j;
	j = strlen(s) - 1;

	for (i = 0; i < strlen(s); i++) {
		palavra[i] = s[j];
		j--;
	}
	palavra[i] = '\0';

	if (strcmp(s, palavra) == 0) {
		free(palavra);
		return 1;
	} else {
		free(palavra);
		return 0;
	}
}

char *Substring(char *s) {
	int tamanho_palindromo = 0;

	char *substring = (char *) malloc(0);
	substring = NULL;

	char *aux = (char *) malloc(0);
	aux = NULL;

	int i, j, k;
	
	for (i = 0; i < strlen(s); i++) {
		for (j = i; j < strlen(s); j++) {
			aux = (char *) realloc(aux, sizeof(char) * (j - i + 2));
			for (k = 0; k <= (j-i); k++) {
				aux[k] = s[k + i];
			}
			aux[k] = '\0';

			if (EhPalindromo(aux) && strlen(aux) > tamanho_palindromo) {
				tamanho_palindromo = strlen(aux);
				substring = (char *) realloc(substring, sizeof(char) * (tamanho_palindromo + 1));
				strcpy(substring, aux);
			}
		}
	}

	free(aux);
	return substring;
}