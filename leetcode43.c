/*
===============================================================================

	LeetCode 43 - Multiplicar Strings ( Multiply Strings )

	-------------------------------------------------------------------
	ENUNCIADO ORIGINAL
	-------------------------------------------------------------------

	Dados dois numeros nao-negativos num1 e num2 representados como
	string, retorne o produto de num1 e num2, tambem representado
	como string.

	Observacao: voce nao deve usar nenhuma biblioteca de BigInteger
	nem converter as entradas diretamente para inteiro.

	Exemplo 1:

		Entrada: num1 = "2", num2 = "3"
		Saida: "6"

	Exemplo 2:

		Entrada: num1 = "123", num2 = "456"
		Saida: "56088"

	Restricoes:

		1 <= num1.length, num2.length <= 200
		num1 e num2 consistem apenas de digitos
		num1 e num2 nao tem zeros a esquerda, exceto o proprio "0"

	-------------------------------------------------------------------
	A PARTIR DAQUI NAO FAZ PARTE DO ENUNCIADO ORIGINAL

	O texto abaixo e material de apoio com exemplos que podem nao
	cobrir tudo que o enunciado acima dita.
	-------------------------------------------------------------------

	POR ONDE COMECAR

	Escreva sua solucao dentro da funcao multiply, mais abaixo neste
	arquivo. E a funcao exigida pelo LeetCode.

	O CABECALHO DA FUNCAO multiply NAO PODE SER ALTERADO: nome,
	tipo de retorno e parametros devem permanecer exatamente como
	estao. O RESTO DO ARQUIVO PODE SER MODIFICADO a vontade: crie
	funcoes auxiliares, structs, variaveis globais ou o que mais
	precisar.

	AVISO SOBRE OS TESTES

	Os 10 testes deste arquivo NAO SAO EXAUSTIVOS. Passar em todos
	eles nao significa que a solucao esta correta. Para ser
	considerada correta, a solucao precisa ser submetida ao LeetCode
	e passar em TODOS os testes da plataforma.

	Voce pode ( e deve ) adicionar mais casos de teste no main para
	cobrir situacoes que os 10 daqui nao cobrem.

	EXEMPLOS DO QUE A OBSERVACAO DO ENUNCIADO PROIBE

	Com ate 200 digitos o valor nao cabe em nenhum tipo nativo do C
	( long long guarda no maximo 19 digitos ).

	PROIBIDO - converter a entrada para um tipo nativo:

		long long a = atoll( num1 );
		long long b = atoll( num2 );
		sprintf( res, "%lld", a * b );

	PROIBIDO - a mesma coisa com strtoll, sscanf ou laco manual:

		long long a = strtoll( num1, NULL, 10 );
		sscanf( num1, "%lld", &a );
		for ( i = 0; num1[i]; i++ ) { a = a * 10 + ( num1[i] - '0' ); }

	PROIBIDO - usar ponto flutuante como atalho:

		double a = atof( num1 );        // perde precisao alem de 2^53

	PROIBIDO - usar biblioteca de precisao arbitraria:

		#include <gmp.h>                // GMP, BigInt e similares

	Por que falha: "98765432109876543210" tem 20 digitos e ja estoura
	long long antes mesmo da multiplicacao. O teste 10 deste arquivo
	usa exatamente esse caso; qualquer atalho acima quebra nele.

===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
====================
multiply

	>>> ESCREVA SUA SOLUCAO AQUI DENTRO <<<

	Assinatura exigida pelo LeetCode: NAO ALTERE o cabecalho abaixo
	( nome, tipo de retorno e parametros ). Funcoes auxiliares podem
	ser criadas livremente fora dela.

	Devolve uma string alocada com malloc contendo o produto.
====================
*/
char *multiply( char *num1, char *num2 ) {

	// teste
	// printf("%d\n", ch1 - '0');
	// printf("%d\n", ch2 - '0');
	// printf("%c\n", (ch1 - '0') * (ch2 - '0') + '0');

	int sizeNum1 = strlen(num1);
	int sizeNum2 = strlen(num2);

	int maxSize = sizeNum1 + sizeNum2; // maior tamanho possivel da multiplicacao
	int size = maxSize;

	// int greater = sizeNum1 > sizeNum2 ? sizeNum1 : sizeNum2;
	int sum = 0;

	char *res = (char *) malloc(sizeof(char) * (maxSize + 1));
	res[size] = '\0';
	size--;

	for (int i = 0; i < maxSize; i++) {
		res[i] = '0';
	}

	for (int i = sizeNum1 - 1; i >= 0; i--) {
		for (int j = sizeNum2 - 1; j >= 0; j--) {
			int n1 = num1[i] - '0';
			int n2 = num2[j] - '0';

			int mult = n1 * n2;

			sum = mult + res[size];

			if (sum > '9') {
				// pegar o resto e somar na casa anterior
			} else {
				res[size] = sum;
			}

			size--;
		}
	}

	// ajustar tamanho de res
	if (maxSize ) {

	}
	
	return res;
}

/*
====================
RodarTeste

	Compara o retorno de multiply com o resultado esperado hard-coded.
====================
*/
static int RodarTeste( int num, const char *n1, const char *n2,
					   const char *esperado ) {
	char *	c1;
	char *	c2;
	char *	res;
	int		ok;

	/* copias defensivas: a funcao recebe char* nao-const */
	c1 = malloc( strlen( n1 ) + 1 );
	c2 = malloc( strlen( n2 ) + 1 );
	strcpy( c1, n1 );
	strcpy( c2, n2 );

	res = multiply( c1, c2 );
	ok = ( strcmp( res, esperado ) == 0 );

	printf( "Teste %2d: \"%s\" * \"%s\"\n", num, n1, n2 );
	printf( "  esperado = \"%s\"\n  obtido   = \"%s\"  ->  %s\n\n",
			esperado, res, ok ? "OK" : "FALHOU" );

	free( res );
	free( c1 );
	free( c2 );
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

	/* Teste 1: exemplo 1 do enunciado */
	passou += RodarTeste(  1, "2", "3", "6" );

	/* Teste 2: exemplo 2 do enunciado */
	passou += RodarTeste(  2, "123", "456", "56088" );

	/* Teste 3: zero a esquerda - resposta e "0", nao "000" */
	passou += RodarTeste(  3, "0", "52", "0" );

	/* Teste 4: zero vezes zero */
	passou += RodarTeste(  4, "0", "0", "0" );

	/* Teste 5: um digito com carry */
	passou += RodarTeste(  5, "9", "9", "81" );

	/* Teste 6: carry propagando por todas as posicoes */
	passou += RodarTeste(  6, "99", "99", "9801" );

	/* Teste 7: produto de 18 digitos - ainda caberia em long long, */
	/* entao NAO detecta atalho sozinho                              */
	passou += RodarTeste(  7, "123456789", "987654321",
						   "121932631112635269" );

	/* Teste 8: multiplicacao por 1 com operando longo */
	passou += RodarTeste(  8, "1", "999999999999", "999999999999" );

	/* Teste 9: zeros internos e finais */
	passou += RodarTeste(  9, "100", "100", "10000" );

	/* Teste 10: 20 x 20 digitos - as ENTRADAS ja estouram long long; */
	/* qualquer conversao para tipo nativo falha aqui                  */
	passou += RodarTeste( 10, "98765432109876543210", "12345678901234567890",
						   "1219326311370217952237463801111263526900" );

	/* Adicione aqui seus proprios casos de teste, no mesmo formato:
	   passou += RodarTeste( 11, "num1", "num2", "resultado esperado" );
	   Lembre de ajustar o total impresso e a condicao do return. */

	printf( "Resultado final: %d/10 testes passaram\n", passou );
	printf( "Lembrete: estes 10 testes NAO sao exaustivos. Submeta ao\n" );
	printf( "LeetCode e passe em todos os testes da plataforma.\n" );
	return passou == 10 ? 0 : 1;
}
