/*
===============================================================================

	LeetCode 5 - Maior Substring Palindroma ( Longest Palindromic Substring )
	GABARITO - expansao a partir do centro

	Dada uma string s, retorne a maior substring palindroma de s.

	Exemplo 1:

		Entrada: s = "babad"
		Saida: "bab"
		Explicacao: "aba" tambem e uma resposta valida.

	Exemplo 2:

		Entrada: s = "cbbd"
		Saida: "bb"

	Restricoes:

		1 <= s.length <= 1000
		s consiste apenas de digitos e letras

	Solucao: todo palindromo tem um centro a partir do qual os
	caracteres se espelham. Ha 2n - 1 centros possiveis: n em
	caracteres ( palindromos de comprimento IMPAR ) e n - 1 entre
	caracteres ( comprimento PAR ). Para cada centro, dois indices
	expandem enquanto s[e] == s[d]; o maior alcance global e a
	resposta. Esquecer os centros pares e o erro classico: "cbbd"
	responderia "c" em vez de "bb".

	Como o enunciado aceita qualquer resposta empatada, os testes
	verificam tres propriedades em vez da string exata: comprimento
	esperado, ser palindromo e ser substring de s. Assim qualquer
	implementacao correta passa, independente de qual empate devolve.

	Complexidade: O( n^2 ) tempo, O( 1 ) espaco extra ( fora a saida ).

===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
====================
longestPalindrome

	Assinatura exigida pelo LeetCode.
	Percorre os 2n - 1 centros, guarda o melhor intervalo e devolve
	uma copia alocada da substring vencedora.
====================
*/
char *longestPalindrome( char *s ) {

	// ESSA É A FUNÇÃO QUE VOCÊ DEVE IMPLEMENTAR PARA O LEETCODE
	// Retorne uma string alocada dinamicamente com a maior substring palindroma.

	char *substring = (char *) malloc(sizeof(char));
	substring = NULL;

	int tamanho = strlen(s);
	int maior_palindromo = 0;
	int e, d;

	if (tamanho == 1)
		return s;

	// palindromo par


	// palindromo impar
	for (int i = 1; i < tamanho - 1; i++) {
		e = i - 1;
		d = i + 1;
		while (e >= 0 && d < tamanho) {
			if (s[e] == s[d]) {
				int tamanho_palindromo = (d - e) + 1;
				
				if (tamanho_palindromo > maior_palindromo) {
					maior_palindromo = tamanho_palindromo;
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

	return substring;
}

/*
====================
RodarTeste

	Verifica tres propriedades do retorno: comprimento esperado
	( hard-coded ), ser palindromo e ser substring da entrada.
====================
*/
static int RodarTeste( int num, const char *entrada, int lenEsperado ) {
	char *	copia;
	char *	res;
	int		lenObtido;
	int		ok;

	/* copia defensiva: a funcao recebe char* nao-const */
	copia = malloc( strlen( entrada ) + 1 );
	strcpy( copia, entrada );

	res = longestPalindrome( copia );
	lenObtido = strlen( res );

	ok = ( lenObtido == lenEsperado )
		 && EhPalindromo( res )
		 && ( strstr( entrada, res ) != NULL );

	printf( "Teste %2d: s = \"%s\"\n", num, entrada );
	printf( "  obtido = \"%s\" ( len %d, esperado len %d )  ->  %s\n\n",
			res, lenObtido, lenEsperado, ok ? "OK" : "FALHOU" );

	free( res );
	free( copia );
	return ok;
}

/*
====================
main
====================
*/
int main( void ) {
	int		passou;

	passou = 0;

	/* Teste 1: exemplo 1 do enunciado - empate "bab" / "aba"           */
	passou += RodarTeste(  1, "babad", 3 );

	/* Teste 2: exemplo 2 do enunciado - palindromo PAR; quem esquece   */
	/* os centros entre caracteres responde "c" e falha aqui            */
	passou += RodarTeste(  2, "cbbd", 2 );

	/* Teste 3: um unico caractere */
	passou += RodarTeste(  3, "a", 1 );

	/* Teste 4: sem palindromo maior que 1 */
	passou += RodarTeste(  4, "ac", 1 );

	/* Teste 5: todos iguais - a string inteira, via centro par ou impar */
	passou += RodarTeste(  5, "aaaa", 4 );

	/* Teste 6: a string inteira e palindroma ( impar ) */
	passou += RodarTeste(  6, "abcba", 5 );

	/* Teste 7: palindromos pequenos nas duas pontas */
	passou += RodarTeste(  7, "abacdfgdcaba", 3 );

	/* Teste 8: palindromo par longo no meio ( "geeksskeeg" ) */
	passou += RodarTeste(  8, "forgeeksskeegfor", 10 );

	/* Teste 9: palindromo par encostado no fim da string */
	passou += RodarTeste(  9, "abb", 2 );

	/* Teste 10: palindromo impar no interior ( "anana" ) */
	passou += RodarTeste( 10, "bananas", 5 );

	printf( "Resultado final: %d/10 testes passaram\n", passou );
	return passou == 10 ? 0 : 1;
}
