#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char s[1] = "a";
	// char s[10] = "acadhkdacj";

	char *substring = (char *) malloc(0);
	substring = NULL;

	int tamanho = strlen(s);
	int maior_palindromo = 0;
	int e, d;

	if (tamanho == 1) {
		printf("%s\n", s);
		return 0;
	}

	// palindromo impar
	for (int i = 1; tamanho > 1 && i < tamanho - 1; i++) {
		e = i - 1;
		d = i + 1;
		while (e >= 0 && d < tamanho) {
			if (s[e] == s[d]) {
				int tamanho_palindromo = (d - e) + 1;
				
				if (tamanho_palindromo > maior_palindromo) {
					substring = (char *) realloc(substring, sizeof(char) * (tamanho_palindromo + 1));
					int j;
					for (j = e; j <= d; j++) {
						substring[j - e] = s[j];
					}
					substring[j - e] = '\0';
				}
			}
			e--;
			d++;
		}
	}

	printf("%s\n", substring);
}