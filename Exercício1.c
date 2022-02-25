#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/* Escrever um algoritmo que lê um valor em reais e calcula qual o menor número possível de notas
de 200, 100, 50, 10, 5 e 1 em que o valor lido pode ser decomposto. Escrever o valor lido e a
relação de notas necessárias.
 */

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL,"Portuguese");
	
	float valor;
	char confirmacao;
	int nota_200=0, resto=0, nota_100=0, nota_50=0, nota_10=0, nota_5=0, nota_1=0;
	
	inicio:
	printf("Insira o um valor em reais para descobrir seu menor número possivel de notas: ");
	scanf("%f", &valor);
	printf("\n\nO valor inserido foi R$%.2f?", valor);
	printf("\n(S) para sim ou (N) para não: ");
	scanf(" %c", &confirmacao);
	if (confirmacao=='N'){
		printf("\nInsira novamente");
		printf("\n\n");
		goto inicio;
	}
	printf ("\n\nO menor número de notas possiveis para R$%.2f foi:", valor);
	
	nota_200=valor / 200;
	resto = (int) valor % 200;
	nota_100=resto / 100;
	resto=resto % 100;
	nota_50=resto / 50;
	resto=resto % 50;
	nota_10=resto / 10;
	resto=resto % 10;
	nota_5=resto / 5;
	resto=resto % 5;
	nota_1=resto / 1;
	resto=resto % 1;
	
	
	printf("\nFoi utilizado um total de %d notas de R$200;", nota_200);
	printf("\nFoi utilizado um total de %d notas de R$100;", nota_100);
	printf("\nFoi utilizado um total de %d notas de R$50;", nota_50);
	printf("\nFoi utilizado um total de %d notas de R$10;", nota_10);
	printf("\nFoi utilizado um total de %d notas de R$5;", nota_5);
	printf("\nFoi utilizado um total de %d notas de R$1.", nota_1);
	
	return 0;
}
