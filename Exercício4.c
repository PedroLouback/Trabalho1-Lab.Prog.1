#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop 

Em um prédio, com N moradores (onde N é fornecido pelo usuário), há três elevadores 
denominados A, B e C. Para otimizar o sistema de controle dos elevadores, foi realizado um 
levantamento no qual cada usuário respondia: 
a) o elevador que utilizava com mais frequência
b) o período que utilizava o elevador, entre: 
i) “M” = matutino; 
ii) “V” = vespertino; 
iii) “N” = noturno. 
Construa um algoritmo que calcule e imprima: 
• qual é o elevador mais frequentado e em que período se concentra o maior fluxo; 
• qual o período mais usado de todos e qual elevador foi mais utilizado nesse período;
• qual a diferença percentual entre o mais usado dos horários e o menos usado; 
• qual a percentagem sobre o total de serviços prestados do elevador de média utilização
*/

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	int i, j, elevA = 0, elevB=0, elevC=0, hora_diaM=0, hora_diaV=0, hora_diaN=0, inicioElev, inicioHora;
	int frequenciaA=0, frequenciaB=0, frequenciaC=0, frequenciaM=0, frequenciaN=0, frequenciaV=0;
	float contador_matutino = 0,contador_noturno, contador_vespertino, cont_fluxo_vespertinoA = 0, cont_fluxo_vespertinoB = 0, cont_fluxo_vespertinoC = 0, cont_fluxo_noturnoA = 0, cont_fluxo_noturnoB = 0 , cont_fluxo_noturnoC = 0 , cont_fluxo_matutinoA = 0 , cont_fluxo_matutinoB = 0, cont_fluxo_matutinoC = 0;
	int nmorador=0, fluxo_matutino=0, fluxo_maior=0, frequencia_maior=0, fluxo_vespertino=0, fluxo_noturno=0;  
	char hora_dia, elev;
	float porcentagem_medio, elevador_medio, diferenca, diferenca_percentual;
	
	printf("            --- Levantamento sobre a utilização dos elevadores A, B e C do prédio ---            ");
	printf("\nResponda as perguntas abaixo conforme o pedido. ");
	printf("\n\nHá quantos moradores no prédio? ");
	scanf("%d", &nmorador);
	
	for (i=0; i<nmorador; i++) {
		printf("\n\n          -- MORADOR %d --          ", i+1);
		inicioElev:
		printf("\n\nPergunta 1 - Qual elevador você utlizado com mais frequência?\n('A' para elevador A, 'B' para elevador B e 'C' para elevador C ): ");
		scanf(" %c", &elev);
		if ((elev == 'A') ||  (elev == 'a')){
			elevA++;
			frequenciaA++;
		}  else if ((elev == 'B') ||  (elev == 'b')) {
			elevB++;
			frequenciaB++;
		} else if ((elev == 'C') ||  (elev == 'c')) {
			elevC++;
			frequenciaC++;
		} else {
			printf ("\n\nVocê informou uma letra indisponivel para resposta! Informe novamente conforme o informado.\n");
			goto inicioElev;
		}
		inicioHora:
		printf("\nPergunta 2 - Qual hora do dia você mais utiliza o elevador?\n('M' para matutino, 'V' para vespertino e 'N' para noturno ): ");
		scanf(" %c", &hora_dia);
				
		if ((hora_dia == 'M') ||  (hora_dia == 'm')){		
			fluxo_matutino++;
			frequenciaM++;
			contador_matutino++;
		}  else if ((hora_dia == 'N') ||  (hora_dia == 'n')) {
			fluxo_noturno++;
			frequenciaN++;
			contador_noturno++;
		} else if ((hora_dia == 'V') ||  (hora_dia == 'v')) {
			fluxo_vespertino++;
			frequenciaV++;
			contador_vespertino++;
		} else {
			printf ("\n\nVocê informou uma letra indisponivel para resposta! Informe novamente conforme o informado.\n");
			goto inicioHora;
		}
		if (( frequenciaA > frequenciaB && frequenciaA > frequenciaC)){
			frequencia_maior = 'A';
		} else if ((frequenciaB>frequenciaA && frequenciaB>frequenciaC)){
			frequencia_maior = 'B';
		} else if ((frequenciaC>frequenciaA && frequenciaC>frequenciaB)){
			frequencia_maior = 'C';
		}
		if ((fluxo_matutino>fluxo_vespertino) && (fluxo_matutino>fluxo_noturno)){
			fluxo_maior='M';
		} else if(fluxo_vespertino > fluxo_matutino && fluxo_vespertino > fluxo_noturno){
			fluxo_maior='V';
		} else if(fluxo_noturno > fluxo_matutino && fluxo_noturno > fluxo_vespertino){
			fluxo_maior='N';
		}
		if (fluxo_maior == 'N' && elev== 'A'){
			cont_fluxo_noturnoA++;
		} else if (fluxo_maior=='N' && elev=='B'){
			cont_fluxo_noturnoB++;
		} else if (fluxo_maior=='N' && elev=='C'){
			cont_fluxo_noturnoC++;
		}	
			
		if (fluxo_maior=='V' && elev=='A'){
			cont_fluxo_vespertinoA++;
		} else if (fluxo_maior=='V' && elev=='B'){
			cont_fluxo_vespertinoB++;
		} else if (fluxo_maior=='V' && elev=='C'){
			cont_fluxo_vespertinoC++;
		}
		
		if (fluxo_maior=='M' && elev=='A'){
			cont_fluxo_matutinoA++;
		} else if (fluxo_maior=='M' && elev=='B'){
			cont_fluxo_matutinoB++;
		} else if (fluxo_maior=='M' && elev=='C'){
			cont_fluxo_matutinoC++;
		}	
	} 
	
	if (contador_noturno > contador_vespertino && contador_noturno > contador_noturno && contador_noturno <= contador_vespertino){
		diferenca = ((contador_noturno/nmorador)-(contador_noturno/nmorador));
	} 
	if (contador_vespertino > contador_noturno && contador_vespertino > contador_noturno && contador_noturno <= contador_noturno){
		diferenca = ((contador_vespertino/nmorador)-(contador_noturno/nmorador));
	}
	if (contador_vespertino > contador_noturno && contador_vespertino > contador_noturno && contador_noturno <= contador_noturno){
		diferenca = ((contador_vespertino/nmorador)-(contador_noturno/nmorador));
	}
	if (contador_noturno > contador_vespertino && contador_noturno > contador_noturno && contador_vespertino <= contador_noturno){
		diferenca = ((contador_noturno/nmorador)-(contador_vespertino/nmorador));
	} 
	if (contador_noturno > contador_noturno && contador_noturno > contador_vespertino && contador_vespertino <= contador_noturno){
		diferenca = ((contador_noturno/nmorador)-(contador_vespertino/nmorador));
	}
	if (contador_noturno > contador_noturno && contador_noturno > contador_vespertino && contador_noturno <= contador_vespertino){
		diferenca = ((contador_noturno/nmorador)-(contador_noturno/nmorador));
	}
	
	if (elevC > elevB && elevC < elevA){
		elevador_medio = elevC;
	}
	if (elevB > elevA && elevB < elevC){
		elevador_medio = elevB;
	}
	if (elevB > elevC && elevB < elevA){
		elevador_medio = elevB;
	}
	if (elevA > elevB && elevA < elevC){
		elevador_medio = elevA;
	}
	if (elevA > elevC && elevA < elevB){
		elevador_medio = elevA;
	}
	if (elevC > elevA && elevC < elevB){
		elevador_medio = elevC;
	}
	porcentagem_medio = (elevador_medio/nmorador)*100;
	diferenca_percentual = diferenca*100;
	printf("\n\n           --- Dados do levantamento feito em relação ao elevadores do prédio ---           \n\n");
	printf("\n1- O elevador que obteve a maior frequencia foi o elevador %c\n", frequencia_maior);
	if (cont_fluxo_matutinoA > cont_fluxo_matutinoB && cont_fluxo_matutinoA > cont_fluxo_matutinoC){
		printf("\n1.1- Sendo o A, seu periodo com mais fluxo de utilização foi o matutino\n");
	} else if (cont_fluxo_vespertinoA > cont_fluxo_vespertinoB && cont_fluxo_vespertinoA > cont_fluxo_vespertinoC){
		printf("\n1.1- Sendo o A, seu periodo com mais fluxo de utilização foi o vespertino\n");
	} else if (cont_fluxo_noturnoA > cont_fluxo_noturnoB && cont_fluxo_noturnoA > cont_fluxo_noturnoC){
		printf("\n1.1- Sendo o A, seu periodo com mais fluxo de utilização foi o noturno\n");
	} if (cont_fluxo_matutinoB > cont_fluxo_matutinoA && cont_fluxo_matutinoB > cont_fluxo_matutinoC){
		printf("\n1.1- Sendo o B, seu periodo com mais fluxo de utilização foi o matutino");
	} else if (cont_fluxo_vespertinoB > cont_fluxo_vespertinoA && cont_fluxo_vespertinoB > cont_fluxo_vespertinoC){
		printf("\n1.1- Sendo o B, seu periodo com mais fluxo de utilização foi o vespertino\n");
	} else if (cont_fluxo_noturnoB > cont_fluxo_noturnoA && cont_fluxo_noturnoB > cont_fluxo_noturnoC){
		printf("\n1.1- Sendo o B, seu periodo com mais fluxo de utilização foi o noturno\n");
	} if (cont_fluxo_matutinoC > cont_fluxo_matutinoA && cont_fluxo_matutinoC > cont_fluxo_matutinoB){
		printf("\n1.1- Sendo o C, seu periodo com mais fluxo de utilização foi o matutino");
	} else if (cont_fluxo_vespertinoC > cont_fluxo_vespertinoA && cont_fluxo_vespertinoC > cont_fluxo_vespertinoB){
		printf("\n1.1- Sendo o C, seu periodo com mais fluxo de utilização foi o vespertino\n");
	} else if (cont_fluxo_noturnoC > cont_fluxo_noturnoA && cont_fluxo_noturnoC > cont_fluxo_noturnoB){
		printf("\n1.1- Sendo o C, seu periodo com mais fluxo de utilização foi o noturno\n");
	}
	printf("\n2- O período que teve o maior uso do elevador foi o período %c ", fluxo_maior);
	printf("\n\n3- A diferença percentual, que foi obtida entre o horario mais usado e o menos usado, foi de %.2f%%\n", diferenca_percentual);
	
	if ((int)porcentagem_medio != 0){
		printf("O total de serviços do elevador de média utilização é: %.0f%%\n", porcentagem_medio);
	}else{
		printf("Elevadores de uso médio não encontrado.\n");
	}
	
	
	return 0;
}
