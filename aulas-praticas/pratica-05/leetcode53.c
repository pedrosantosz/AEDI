/*
===============================================================================

	LeetCode 53 - Maior Soma de Subarray ( Maximum Subarray )

	-------------------------------------------------------------------
	ENUNCIADO ORIGINAL
	-------------------------------------------------------------------

	Dado um array de inteiros nums, encontre a subarray com a maior
	soma e retorne essa soma.

	Uma subarray é uma sequência de elementos contíguos e não vazia
	dentro de um array.

	Exemplo 1:

		Entrada: nums = [-2,1,-3,4,-1,2,1,-5,4]
		Saída: 6
		Explicação: a subarray [4,-1,2,1] tem a maior soma, que é 6.

	Exemplo 2:

		Entrada: nums = [1]
		Saída: 1
		Explicação: a subarray [1] tem a maior soma, que é 1.

	Exemplo 3:

		Entrada: nums = [5,4,-1,7,8]
		Saída: 23
		Explicação: a subarray [5,4,-1,7,8] tem a maior soma, que é 23.

	Restrições:

		1 <= nums.length <= 10^5
		-10^4 <= nums[i] <= 10^4


	-------------------------------------------------------------------
	A PARTIR DAQUI NÃO FAZ PARTE DO ENUNCIADO ORIGINAL

	O texto abaixo é material de apoio com exemplos que podem não
	cobrir tudo que o enunciado acima dita.
	-------------------------------------------------------------------

	ESTE PROBLEMA NÃO TEM EDITORIAL, ENTÃO EM CASA USE O SEGUINTE COMO EDITORIAL: https://leetcode.com/problems/maximum-subarray/solutions/7592706/maximum-subarray-kadanes-algorithm-with-tcw2m/

	POR ONDE COMEÇAR

	Escreva sua solução dentro da função maxSubArray, mais abaixo
	neste arquivo. É a função exigida pelo LeetCode.

	O CABEÇALHO DA FUNÇÃO maxSubArray NÃO PODE SER ALTERADO: nome,
	tipo de retorno e parâmetros devem permanecer exatamente como
	estão. O RESTO DO ARQUIVO PODE SER MODIFICADO a vontade: crie
	funções auxiliares, structs, variáveis globais ou o que mais
	precisar.

	AVISO SOBRE OS TESTES

	Os 10 testes deste arquivo NÃO SÃO EXAUSTIVOS. Passar em todos
	eles não significa que a solução está correta. Para ser
	considerada correta, a solução precisa ser submetida ao LeetCode
	e passar em TODOS os testes da plataforma.

	Você pode ( e deve ) adicionar mais casos de teste no main para
	cobrir situações que os 10 daqui não cobrem.

	OBSERVAÇÕES SOBRE O ENUNCIADO

	A subarray precisa ser CONTÍGUA: os elementos escolhidos são
	vizinhos no array, não podem ser salteados.

	A subarray precisa ser NÃO VAZIA. Quando todos os valores são
	negativos, a resposta é o MAIOR elemento ( o menos negativo ),
	nunca 0. O teste 5 cobre esse caso.

	O que se retorna é a SOMA, não a subarray nem seus índices.

	Pelas restrições, a maior soma possível em módulo é
	10^5 * 10^4 = 10^9, que cabe em int ( o limite é 2147483647 ).

===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

/*
====================
maxSubArray

	Assinatura exigida pelo LeetCode: NÃO ALTERE o cabeçalho abaixo
	( nome, tipo de retorno e parâmetros ). Funções auxiliares podem
	ser criadas livremente fora dela.
====================
*/
int maxSubArray( int *nums, int numsSize ) {
	if (numsSize == 1) {
		return nums[0];
	}

	int maior = nums[0];

	for (int i = 0; i < numsSize; i++) {
		int sum = 0;

		for (int j = i; j < numsSize; j++) {
			sum += nums[j];

			if (sum > maior) {
				maior = sum;
			}
		}
	}

	return maior;
}

/*
====================
ImprimirArray
====================
*/
static void ImprimirArray( const int *a, int n ) {
	int		i;

	printf( "[" );
	for ( i = 0; i < n; i++ ) {
		printf( "%d%s", a[i], i + 1 < n ? "," : "" );
	}
	printf( "]" );
}

/*
====================
RodarTeste

	Compara o retorno de maxSubArray com o resultado esperado
	hard-coded.
====================
*/
static int RodarTeste( int num, int *nums, int n, int esperado ) {
	int		obtido;
	int		ok;

	obtido = maxSubArray( nums, n );
	ok = ( obtido == esperado );

	printf( "Teste %2d: nums = ", num );
	ImprimirArray( nums, n );
	printf( "\n  esperado = %d | obtido = %d  ->  %s\n\n",
			esperado, obtido, ok ? "OK" : "FALHOU" );
	return ok;
}

/*
====================
main
====================
*/
int main( void ) {
	int		passou;

	/* Teste 1: exemplo 1 do enunciado - melhor subarray [4,-1,2,1] */
	int		t1[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

	/* Teste 2: exemplo 2 do enunciado - um único elemento */
	int		t2[] = { 1 };

	/* Teste 3: exemplo 3 do enunciado - o array inteiro */
	int		t3[] = { 5, 4, -1, 7, 8 };

	/* Teste 4: um único elemento negativo */
	int		t4[] = { -1 };

	/* Teste 5: TODOS negativos - resposta é o maior elemento, não 0 */
	int		t5[] = { -2, -3, -1, -5 };

	/* Teste 6: todos positivos - o array inteiro */
	int		t6[] = { 1, 2, 3, 4, 5 };

	/* Teste 7: melhor subarray é só o último elemento */
	int		t7[] = { -1, -2, -3, 4 };

	/* Teste 8: negativo no meio compensa ser atravessado */
	int		t8[] = { 2, -1, 2, 3, -9 };

	/* Teste 9: dois elementos, ambos negativos */
	int		t9[] = { -2, -1 };

	/* Teste 10: valores no limite das restrições ( +-10^4 ) */
	int		t10[] = { 10000, -10000, 10000 };

	passou = 0;
	passou += RodarTeste(  1, t1,  9, 6 );
	passou += RodarTeste(  2, t2,  1, 1 );
	passou += RodarTeste(  3, t3,  5, 23 );
	passou += RodarTeste(  4, t4,  1, -1 );
	passou += RodarTeste(  5, t5,  4, -1 );
	passou += RodarTeste(  6, t6,  5, 15 );
	passou += RodarTeste(  7, t7,  4, 4 );
	passou += RodarTeste(  8, t8,  5, 6 );
	passou += RodarTeste(  9, t9,  2, -1 );
	passou += RodarTeste( 10, t10, 3, 10000 );

	/* Adicione aqui seus próprios casos de teste, no mesmo formato:
	   passou += RodarTeste( 11, arrayNums, tamanho, resultadoEsperado );
	   Lembre de ajustar o total impresso e a condição do return. */

	printf( "Resultado final: %d/10 testes passaram\n", passou );
	printf( "Lembrete: estes 10 testes NAO sao exaustivos. Submeta ao\n" );
	printf( "LeetCode e passe em todos os testes da plataforma.\n" );
	return passou == 10 ? 0 : 1;
}
