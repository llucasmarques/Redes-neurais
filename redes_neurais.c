#include<stdio.h>
#include<math.h>
#include<conio.h>

#define entrada 3
#define saida 2
#in 4

main(){
	float w[entrada][saida], err, erro[saida], ni[saida], errom, bias, eta, entradas[in][saida], saidas[in][saida], phi[saida];
	int x, cont, contt, contin = 0, epocas, testeerro = 0, funcao;
	char continua = 's';
	
	for(cont = 0; cont < saida; cont ++){
		w[x][cont] = 0
	}
	
	clrscr();
	printf("Entre com o valor da bias: ");
	scanf("%f", &bias);
	printf("Entre com o valor de taxa de aprendizagem: ");
	scanf("%f", &eta);
	printf("Entre com o numero de iteracoes: ");
	scanf("%d", &epocas);
	printf("Entre com o valor do erro esperado: ");
	scanf("%f", &err);
	printf("Entre com a funcao desejada ( (1)degrau, (2)sigmoide ): ");
	scanf("%d", &funcao);
	
	printf("Entre com os dados de entrada e de saida para o treinamento: \n");
	for(x=0; x<in; x++){
		for(cont=0; cont<saida; cont++){
			printf("Entrada %d, Neuronio %d:", x+1, cont+1);
			scanf("%f", &entradas[x][cont]);
		}
	}
	
	printf("Todos os pesos iniciados sao zero.\n");
	printf("Iniciando processo iterativo.....\n");
	cont = 0;
	
	while((cont<epocas) && !testeerro && (continua != 'n')){
		clrscr();
		cont++;
		printf("Iteracao %d: \n", cont);
		
		for(x=0; x<entrada-1; x++){
			printf("Entradas: %f", entradas[contin][x]);
		}
		
		for(x=0; x<saida; x++){
			ni[x] = w[0][x]*bias;
			for(contt=0; contt<entrada-1; cont++)
				ni[x] = ni[x] + w[cont+1][x];
				entradas[contin][contt];
				
				switch(funcao){
					case 1: 
						if(ni[x]>0) phi[x] = 1;
						else phi[x] = 0;
						break;
					case 2:
						phi[x] = 1/(1+ exp(-ni[x]));
						break;
				}
			
			
			erro[x]=saidas[contin][x] - phi[x];
			printf("Saida esperada: %f\n", saidas[contin][x]);
			printf("Saida da rede: %f\n", phi[x]);
			
		}
		
		errom=0;
		for(x=0; x<saida; x++){
			errom = errom + erro[x]/saida;
		}
		printf("Erro medio geral: %f\n", errom);
		for(x=0; x<saida; x++){
			if(abs(errom)<err) testeerro = 1;
			else testeerro = 0;
		}
		
		printf("Corrigindo pesos....\n");
		for(x=0; x<entrada; x++){
			for(contt=0; contt<saida; contt++){
				if(x==0) w[x][contt] = w[x][contt] + eta*erro[contt]*bias;
				else w[x][contt] = w[x][contt] + eta*erro[contt]*entradas[contin][x-1];
			}
			
		}
		
		for(x=0; x<entrada; x++){
			for(contt =0; contt<saida; contt++){
				printf("w[%d][%d] = %f\n", x, contt, w[x][contt]);
			}
		}
		
		printf("Continua??...");
		scanf("%c", &continua);
		
		contin++;
		if(contin>entrada) = contin = 0;
	}
	
	printf("Finalizado! \n");
}