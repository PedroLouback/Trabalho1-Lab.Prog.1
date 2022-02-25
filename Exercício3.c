#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>


/*  O valor aproximado do número (Pi) pode ser calculado usando-se a série:
Faça um algoritmo em C que calcule e imprima o valor de PI usando os n
primeiros termos da séria acima, sendo n fornecido pelo usuário.
 */

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL,"Portuguese");
	
	double soma_interna=0, somatorio_pi = 0, denominador=1, s = 0;
	int i, serie;
	
	
	printf ("Informe o total de termos para a série: ");
	scanf ("%d", &serie);
	
	for (i=0;i<serie;i++){
		s = s + pow(-1, i) * (1/pow(denominador, 3));
		denominador = denominador + 2;
		
	}
	 
	printf("\n\n        .:RESULTADOS:.       \n\n");
	printf("O somatorio de todos os termos informados foi: %lf", s);
	
	soma_interna = (s*32);
	somatorio_pi = cbrt(soma_interna);
	
	printf("\n\nResultado de (PI) de acordo com a soma é: %lf", somatorio_pi);

	
	return 0;
}
