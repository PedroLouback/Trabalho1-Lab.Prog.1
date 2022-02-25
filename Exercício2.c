#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/*  Sendo, um somat�rio de N termos (definido pelo usu�rio),
escreva algoritmo em C para calcular S para um n�mero N.
 */

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "Portuguese");
	
	int i=1, termos=0;
	double n = 0, somatorio = 0;
	
	printf("Defina o total de termos para o somatorio: ");
	scanf("%d", &termos);
	
	while (i<=termos) {
		n = pow(i,i);
		somatorio = somatorio + (1/n);
		i++;
	}
	printf("\n\nO resultado do somat�rio de %d termos foi: %lf", termos, somatorio);

	return 0;
}
