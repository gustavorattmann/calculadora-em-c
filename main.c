#include <stdio.h> // Biblioteca padr�o para aloca��o de mem�ria, controle de processos, convers�es e outras coisas.
#include <stdlib.h> // Biblioteca padr�o para entrada e sa�da de dados.
#include <ctype.h> // Bibliote para fun��es como isalnum, isalfa, toupper, tolower e outros.
#include <math.h> // Biblioteca para opera��es matem�ticas como ra�z quadrada ou eleva��o.
#include <locale.h> // Biblioteca de idioma.

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"portuguese"); // Define o idioma de qualquer texto que ser� apresentado no console como Portugu�s, ou seja, apresentar� caracteres com assento.
	
	menu();	// Realiza invoca��o do m�todo menu.
	
	return 0; // Retorno 0 (falso) indica que n�o houve nenhum erro.
}

menu() // M�todo Menu.
{
	// Declarando vari�veis globais.
	int tipo;
	
	printf("Dica: para que se ter uma melhor experi�ncia visualmente com a janela de prompt de comando, maximize a tela.\n\n");
	printf("Observa��es: Se quiser usar n�meros reais, utilize v�rgula, pois se usar ponto, ser� considerado como inteiro.\n\n");
	printf("Escolha uma das op��es abaixo:");
	printf("\n(1 - Tabuada / 2 - Ra�z Quadrada / 3 - C�lculo / 4 - F�rmula de Bhaskara / 5 - Fun��es Trigonom�tricas / 6 - Sair): ");
	scanf("%i",&tipo); // %i, aloca e exibe apenas n�meros antes da v�rgula.
	fflush(stdin); // Limpa o buffer do teclado, para que n�o seja alocado a tecla enter em uma mem�ria tempor�ria,
				   // pois assim que ele for alocar a pr�xima vari�vel, ele checar� antes nessa mem�ria.
	
	switch(tipo){ // Verifica a vari�vel tipo.
		case 1: // Se for digitado o n�mero 1, faz o seguinte procedimento.
			printf("\n"); // Serve para pular para a pr�xima linha, se for \n\n, pula duas linhas.
			tabuada(); // Realiza invoca��o do m�todo tabuada.
		break; // Ap�s executar os procedimentos acima, finaliza a escolha de caso.
		case 2:
			printf("\n");
			raiz(); // Realiza invoca��o do m�todo raiz.
		break;
		case 3:
			printf("\n");
			calculo(); // Realiza invoca��o do m�todo calculo.
		break;
		case 4:
			printf("\n");
			bhaskara(); // Realiza invoca��o do m�todo bhaskara.
		break;
		case 5:
			printf("\n");
			trigonometria(); // Realiza invoca��o do m�todo trigonometria.
		break;
		case 6:
			printf("\n");
			sair(); // Realiza invoca��o do m�todo sair.
		break;
		default: // Se nenhum dos n�meros solicitado for digitado, executar� os procedimentos desse escolha de caso padr�o.
			system("cls"); // Limpa a tela, apaga tudo que foi digitado anteriormente.
			printf("Por favor, preencha como solicitado!\n\n");
			menu(); // Realiza invoca��o do pr�prio m�todo, para que ele seja repetido
		break;
	}
}

tabuada() // M�todo Tabuada.
{
    // Declarando vari�veis globais.
	int valor, contador, resultado;
	char verifica[3];
	
	printf("Digite um n�mero: ");
    scanf("%i",&valor);
    fflush(stdin);
	
    for(contador = 0; contador < 11; contador++){
        resultado = contador * valor;
        printf("%i x %i = %i\n",valor,contador,resultado);
    }
	
    printf("\nDeseja ver a tabuada com outro n�mero? (sim / nao): ");
    scanf("%s",&verifica);
    fflush(stdin);
    
	strupr(verifica);
	
	if(strcmp(verifica, "SIM") == 0){
		system("cls");
		tabuada();
	}else if(strcmp(verifica, "NAO") == 0){
		system("cls");
		menu();
	}else{
		system("cls");
		printf("Por favor, preencha como solicitado!\n\n");
		menu();
	}
}

raiz(){ // M�todo Ra�z
	// Declarando vari�veis globais.
	float valor;
	char verifica[3];
	
	printf("Digite um n�mero: ");
    scanf("%f",&valor);
    fflush(stdin);
    
    if(valor == (int)valor){ //Realizado compara��o verificando se o valor digitado � decimal ou se � inteiro. Ap�s a compara��o de igual, � realizado um Cast (Convers�o) do valor decimal para inteiro.
    	int resultado; // Se for decimal, ser� criado a vari�vel resultado como inteiro.
		resultado = sqrt((int)valor); // A vari�vel resultado recebe resultado da ra�z como inteiro.
		printf("A ra�z quadrada de %i � %i\n\n",(int)valor,resultado); // � exibido o resultado, convertendo o valor que � decimal para inteiro, para n�o exibir nenhum n�mero depois da v�rgula.
	}else{ // Se o valor for decimal, far� os procedimentos abaixo
		double resultado;
    	resultado = sqrt(valor);
    	printf("A ra�z quadrada de %f � %f\n\n",valor,resultado);
	}
	
    printf("Deseja ver a ra�z quadrada de outro n�mero? (sim / nao): ");
    scanf("%s",&verifica);
    fflush(stdin);
	
	strupr(verifica);
	
	if(strcmp(verifica, "SIM") == 0){
		system("cls");
		raiz();
	}else if(strcmp(verifica, "NAO") == 0){
		system("cls");
		menu();
	}else{
		system("cls");
		printf("Por favor, preencha como solicitado!\n\n");
		menu();
	}
}

calculo() // M�todo C�lculo
{
    // Declarando vari�veis globais.
    int operador;
	float valor1, valor2;
	double resultado;
    char verifica[3];
	
	printf("Para efetuarmos um c�lculo, ser� solicitado para digitar dois n�meros em sequ�ncia e, por �ltimo, um n�mero referente ao tipo de c�lculo que deseja fazer.\n");
	printf("Digite um n�mero: ");
    scanf("%f",&valor1);
    fflush(stdin);
    printf("Digite outro n�mero: ");
    scanf("%f",&valor2);
    fflush(stdin);
    printf("\nQual opera��o deseja realizar?\n");
	printf("(1 - soma, 2 - subtra��o, 3 - multiplica��o, 4 - divis�o, 5 - resto de divis�o, 6 - eleva��o de um n�mero): ");
    scanf("%i",&operador);
    fflush(stdin);

    switch(operador){
        case 1:
        	resultado = valor1 + valor2;
			
			if(valor1 == (int)valor1 && valor2 == (int)valor2){
				printf("%i + %i = %i\n\n",(int)valor1,(int)valor2,(int)resultado);
			}else if(valor1 == (int)valor1 && valor2 == valor2){
				printf("%i + %g = %lg\n\n",(int)valor1,valor2,resultado);
			}else if(valor1 == valor1 && valor2 == (int)valor2){
				printf("%g + %i = %lg\n\n",valor1,(int)valor2,resultado);
			}else{
		    	printf("%g + %g = %lg\n\n",valor1,valor2,resultado);
			}
        break;
        case 2:
            resultado = valor1 - valor2;
			
			if(valor1 == (int)valor1 && valor2 == (int)valor2){
		    	printf("%i - %i = %i\n\n",(int)valor1,(int)valor2,(int)resultado);
			}else if(valor1 == (int)valor1 && valor2 == valor2){
				printf("%i - %g = %lg\n\n",(int)valor1,valor2,resultado);
			}else if(valor1 == valor1 && valor2 == (int)valor2){
				printf("%g - %i = %lg\n\n",valor1,(int)valor2,resultado);
			}else{
		    	printf("%g - %g = %lg\n\n",valor1,valor2,resultado);
			}
        break;
        case 3:
            resultado = valor1 * valor2;
            
			if(valor1 == (int)valor1 && valor2 == (int)valor2){
				printf("%i x %i = %i\n\n",(int)valor1,(int)valor2,(int)resultado);
			}else if(valor1 == (int)valor1 && valor2 == valor2){
				printf("%i x %g = %lg\n\n",(int)valor1,valor2,resultado);
			}else if(valor1 == valor1 && valor2 == (int)valor2){
				printf("%g x %i = %lg\n\n",valor1,(int)valor2,resultado);
			}else{
		    	printf("%g x %g = %lg\n\n",valor1,valor2,resultado);
			}
        break;
        case 4:
			resultado = valor1 / valor2;
				
			if(valor1 == (int)valor1 && valor2 == (int)valor2){
				if((int)valor1 < (int)valor2){
					printf("%i / %i = %lg\n\n",(int)valor1,(int)valor2,resultado);
				}else{
					printf("%i / %i = %i\n\n",(int)valor1,(int)valor2,(int)resultado);
				}
			}else if(valor1 == (int)valor1 && valor2 == valor2){
				if((int)valor1 < valor2){
					printf("%i / %g = %lg\n\n",(int)valor1,valor2,resultado);
				}else{
					printf("%i / %g = %i\n\n",(int)valor1,valor2,(int)resultado);
				}
			}else if(valor1 == valor1 && valor2 == (int)valor2){
				if(valor1 < (int)valor2){
					printf("%g / %i = %lg\n\n",valor1,(int)valor2,resultado);
				}else{
					printf("%g / %i = %i\n\n",valor1,(int)valor2,(int)resultado);
				}
			}
			else{
				printf("%g / %g = %lg\n\n",valor1,valor2,resultado);
			}
        break;
        case 5:
			resultado = (int)valor1 % (int)valor2;
			
			if(valor1 == (int)valor1 && valor2 == (int)valor2){
				printf("O resto de %i divido por %i � %i\n\n",(int)valor1,(int)valor2,(int)resultado);
			}else{
				system("cls");
            	printf("Por favor, digite n�meros sem v�rgula para realizar este c�lculo!\n\n");
            	calculo();
			}
        break;
        case 6:
			if(valor1 == (int)valor1 && valor2 == (int)valor2){
				printf("A eleva��o de %i por %i � %i\n\n",(int)valor1,(int)valor2,pow((int)valor1,(int)valor2));
			}else if(valor1 == valor1 && valor2 == (int)valor2){
				printf("A eleva��o de %g por %i � %lg\n\n",valor1,(int)valor2,pow(valor1,(int)valor2));
			}else{
				system("cls");
            	printf("Por favor, digite o segundo n�mero sem v�rgula para realizar este c�lculo!\n\n");
            	calculo();
			}
        break;
        default:
            system("cls");
            printf("Por favor, escreva o operador como solicitado!\n\n");
            calculo();
        break;
    }

    printf("Deseja fazer um novo c�lculo? (sim / nao): ");
    scanf("%s",&verifica);
    fflush(stdin);
	
	strupr(verifica);
	
	if(strcmp(verifica, "SIM") == 0){
		system("cls");
		calculo();
	}else if(strcmp(verifica, "NAO") == 0){
		system("cls");
		menu();
	}else{
		system("cls");
		printf("Por favor, preencha como solicitado!\n\n");
		menu();
	}
}

bhaskara() // M�todo Bhaskara
{
	// Declarando vari�veis globais.
	float valor1, valor2, valor3, delta, x1, x2;
	char verifica[3];
	
	printf("Digite um n�mero para A: ");
	scanf("%f",&valor1);
	fflush(stdin);
	printf("Digite um n�mero para B: ");
	scanf("%f",&valor2);
	fflush(stdin);
	printf("Digite um n�mero para C: ");
	scanf("%f",&valor3);
	fflush(stdin);
	
	if(valor1 == (int)valor1 && valor2 == (int)valor2 && valor3 == (int)valor3){
    	int delta;
		delta = sqrt(pow((int)valor2,2) - (4 * (int)valor1 * (int)valor3));
		
		if(delta > 0){
			x1 = ((-(int)valor2) + delta) / (2 * (int)valor1);
			x2 = ((-(int)valor2) - delta) / (2 * (int)valor1);
			
			if(x1 == (int)x1 && x2 == (int)x2){
				printf("A ra�z de X� � %i\n",(int)x1);
				printf("A ra�z de X� � %i\n\n",(int)x2);
			}else if(x1 == (int)x1 && x2 == x2){
				printf("A ra�z de X� � %i\n",(int)x1);
				printf("A ra�z de X� � %g\n\n",x2);
			}else if(x1 == x1 && x2 == (int)x2){
				printf("A ra�z de X� � %g\n",x1);
				printf("A ra�z de X� � %i\n\n",(int)x2);
			}else{
				printf("A ra�z de X� � %g\n",x1);
				printf("A ra�z de X� � %g\n\n",x2);
			}
		}else if(delta == 0){
			x1 = ((-(int)valor2) + delta) / (2 * (int)valor1);
			
			if(x1 == (int)x1){
				printf("Delta possui valor de %i, que � nulo, portanto h� apenas uma ra�z.\n",delta);
				printf("A ra�z de X� � %i\n\n",(int)x1);
			}else{
				printf("Delta possui valor de %i, que � nulo, portanto h� apenas uma ra�z.\n",delta);
				printf("A ra�z de X� � %g\n\n",x1);
			}
		}else{
			printf("Delta possui valor de %i, que � negativo, portanto n�o h� nenhuma ra�z.\n\n",delta);	
		}
	}else if(valor1 == (int)valor1 && valor2 == (int)valor2 && valor3 == valor3){
		float delta;
		delta = sqrt(pow((int)valor2,2) - (4 * (int)valor1 * valor3));
		
		if(delta >= 1){
			x1 = ((-(int)valor2) + delta) / (2 * (int)valor1);
			x2 = ((-(int)valor2) - delta) / (2 * (int)valor1);
			
			if(x1 == (int)x1 && x2 == (int)x2){
				printf("A ra�z de X� � %i\n",(int)x1);
				printf("A ra�z de X� � %i\n\n",(int)x2);
			}else if(x1 == (int)x1 && x2 == x2){
				printf("A ra�z de X� � %i\n",(int)x1);
				printf("A ra�z de X� � %g\n\n",x2);
			}else if(x1 == x1 && x2 == (int)x2){
				printf("A ra�z de X� � %g\n",x1);
				printf("A ra�z de X� � %i\n\n",(int)x2);
			}else{
				printf("A ra�z de X� � %g\n",x1);
				printf("A ra�z de X� � %g\n\n",x2);
			}
		}else if(delta == 0){
			x1 = ((-(int)valor2) + delta) / (2 * (int)valor1);
			
			if(x1 == (int)x1){
				printf("Delta possui valor de %i, que � nulo, portanto h� apenas uma ra�z.\n",delta);
				printf("A ra�z de X� � %i\n\n",(int)x1);
			}else{
				printf("Delta possui valor de %i, que � nulo, portanto h� apenas uma ra�z.\n",delta);
				printf("A ra�z de X� � %g\n\n",x1);
			}
		}else{
			printf("Delta possui valor de %f, que � negativo, portanto n�o h� nenhuma ra�z.\n\n",delta);	
		}
	}else if(valor1 == valor1 && valor2 == (int)valor2 && valor3 == (int)valor3){
		float delta;
		delta = sqrt(pow((int)valor2,2) - (4 * valor1 * (int)valor3));
		
		if(delta >= 1){
			x1 = ((-(int)valor2) + delta) / (2 * valor1);
			x2 = ((-(int)valor2) - delta) / (2 * valor1);
			
			if(x1 == (int)x1 && x2 == (int)x2){
				printf("A ra�z de X� � %i\n",(int)x1);
				printf("A ra�z de X� � %i\n\n",(int)x2);
			}else if(x1 == (int)x1 && x2 == x2){
				printf("A ra�z de X� � %i\n",(int)x1);
				printf("A ra�z de X� � %g\n\n",x2);
			}else if(x1 == x1 && x2 == (int)x2){
				printf("A ra�z de X� � %g\n",x1);
				printf("A ra�z de X� � %i\n\n",(int)x2);
			}else{
				printf("A ra�z de X� � %g\n",x1);
				printf("A ra�z de X� � %g\n\n",x2);
			}
		}else if(delta == 0){
			x1 = ((-(int)valor2) + delta) / (2 * valor1);
			
			if(x1 == (int)x1){
				printf("Delta possui valor de %i, que � nulo, portanto h� apenas uma ra�z.\n",delta);
				printf("A ra�z de X� � %i\n\n",(int)x1);
			}else{
				printf("Delta possui valor de %i, que � nulo, portanto h� apenas uma ra�z.\n",delta);
				printf("A ra�z de X� � %g\n\n",x1);
			}
		}else{
			printf("Delta possui valor de %f, que � negativo, portanto n�o h� nenhuma ra�z.\n\n",delta);	
		}
	}else if(valor1 == (int)valor1 && valor2 == valor2 && valor3 == (int)valor3){
		float delta;
		delta = sqrt(pow(valor2,2) - (4 * (int)valor1 * (int)valor3));
		
		if(delta >= 1){
			x1 = ((-valor2) + delta) / (2 * (int)valor1);
			x2 = ((-valor2) - delta) / (2 * (int)valor1);
			
			if(x1 == (int)x1 && x2 == (int)x2){
				printf("A ra�z de X� � %i\n",(int)x1);
				printf("A ra�z de X� � %i\n\n",(int)x2);
			}else if(x1 == (int)x1 && x2 == x2){
				printf("A ra�z de X� � %i\n",(int)x1);
				printf("A ra�z de X� � %g\n\n",x2);
			}else if(x1 == x1 && x2 == (int)x2){
				printf("A ra�z de X� � %g\n",x1);
				printf("A ra�z de X� � %i\n\n",(int)x2);
			}else{
				printf("A ra�z de X� � %g\n",x1);
				printf("A ra�z de X� � %g\n\n",x2);
			}
		}else if(delta == 0){
			x1 = ((-valor2) + delta) / (2 * (int)valor1);
			
			if(x1 == (int)x1){
				printf("Delta possui valor de %i, que � nulo, portanto h� apenas uma ra�z.\n",delta);
				printf("A ra�z de X� � %i\n\n",(int)x1);
			}else{
				printf("Delta possui valor de %i, que � nulo, portanto h� apenas uma ra�z.\n",delta);
				printf("A ra�z de X� � %g\n\n",x1);
			}
		}else{
			printf("Delta possui valor de %f, que � negativo, portanto n�o h� nenhuma ra�z.\n\n",delta);	
		}
	}else{
		float delta;
		delta = sqrt(pow(valor2,2) - (4 * valor1 * valor3));
		
		x1 = ((-valor2) + delta) / (2 * valor1);
			x2 = ((-valor2) - delta) / (2 * valor1);
		
		if(delta >= 1){
			printf("A ra�z de X� � %g\n",x1);
			printf("A ra�z de X� � %g\n\n",x2);
		}else if(delta == 0){
			x1 = ((-(int)valor2) + delta) / (2 * (int)valor1);
			
			
			printf("Delta possui valor de %i, que � nulo, portanto h� apenas uma ra�z.\n",delta);
			printf("A ra�z de X� � %g\n\n",x1);
		}else{
			printf("Delta possui valor de %f, que � negativo, portanto n�o h� nenhuma ra�z.\n\n",delta);	
		}
	}
	
	printf("Deseja realizar uma nova f�rmula de Bhaskara? (sim / nao): ");
	scanf("%s",&verifica);
	fflush(stdin);
	
	strupr(verifica);
	
	if(strcmp(verifica, "SIM") == 0){
		system("cls");
		bhaskara();
	}else if(strcmp(verifica, "NAO") == 0){
		system("cls");
		menu();
	}else{
		system("cls");
		printf("Por favor, preencha como solicitado!\n");
		menu();
	}
}

trigonometria() // M�todo Trigonometria
{
	// Declarando vari�veis globais.
	int tipo;
	float valor1, valor2;
	char verifica[3];
	
	printf("Qual fun��o de trigonometria deseja realizar?\n");
	printf("(1 - Seno / 2 - Cosseno / 3 - Tangente / 4 - Voltar ao menu): ");
	scanf("%i",&tipo);
	fflush(stdin);
	
	switch(tipo){
		case 1:
			printf("\nDigite um n�mero para o cateto oposto: ");
			scanf("%d",&valor1);
			fflush(stdin);
			printf("Digite um n�mero para a hipotenusa: ");
			scanf("%d",&valor2);
			fflush(stdin);
			
			if(valor1 == (int)valor1 && valor2 == (int)valor2){
				printf("O resultado de Seno � %i\n\n",((int)valor1/(int)valor2));
			}else if(valor1 == (int)valor1 && valor2 == valor2){
				printf("O resultado de Seno � %g\n\n",((int)valor1/valor2));
			}else if(valor1 == valor1 && valor2 == (int)valor2){
				printf("O resultado de Seno � %g\n\n",(valor1/(int)valor2));
			}else{
				printf("O resultado de Seno � %g\n\n",(valor1/valor2));
			}
			
			printf("Deseja realizar uma outra fun��o de trigonometria? (sim / nao): ");
			scanf("%s",&verifica);
			fflush(stdin);
			
			strupr(verifica);
			
			if(strcmp(verifica, "SIM") == 0){
				system("cls");
				trigonometria();
			}else if(strcmp(verifica, "NAO") == 0){
				system("cls");
				menu();
			}else{
				system("cls");
        		printf("Por favor, preencha como solicitado!\n\n");
        		menu();
			}
		break;
		case 2:
			printf("\nDigite um n�mero para o cateto adjacente: ");
			scanf("%d",&valor1);
			fflush(stdin);
			printf("Digite um n�mero para a hipotenusa: ");
			scanf("%d",&valor2);
			fflush(stdin);
			
			if(valor1 == (int)valor1 && valor2 == (int)valor2){
				printf("O resultado de Cosseno � %i\n\n",((int)valor1/(int)valor2));
			}else if(valor1 == (int)valor1 && valor2 == valor2){
				printf("O resultado de Cosseno � %g\n\n",((int)valor1/valor2));
			}else if(valor1 == valor1 && valor2 == (int)valor2){
				printf("O resultado de Cosseno � %g\n\n",(valor1/(int)valor2));
			}else{
				printf("O resultado de Cosseno � %g\n\n",(valor1/valor2));
			}
			
			printf("Deseja realizar uma outra fun��o de trigonometria? (sim / nao): ");
			scanf("%s",&verifica);
			fflush(stdin);
			
			strupr(verifica);
			
			if(strcmp(verifica, "SIM") == 0){
				system("cls");
				trigonometria();
			}else if(strcmp(verifica, "NAO") == 0){
				system("cls");
				menu();
			}else{
				system("cls");
        		printf("Por favor, preencha como solicitado!\n\n");
        		menu();
			}
		break;
		case 3:
			printf("\nDigite um n�mero para o cateto oposto: ");
			scanf("%d",&valor1);
			fflush(stdin);
			printf("Digite um n�mero para o cateto adjacente: ");
			scanf("%d",&valor2);
			fflush(stdin);
			
			if(valor1 == (int)valor1 && valor2 == (int)valor2){
				printf("O resultado de Tangente � %i\n\n",((int)valor1/(int)valor2));
			}else if(valor1 == (int)valor1 && valor2 == valor2){
				printf("O resultado de Tangente � %g\n\n",((int)valor1/valor2));
			}else if(valor1 == valor1 && valor2 == (int)valor2){
				printf("O resultado de Tangente � %g\n\n",(valor1/(int)valor2));
			}else{
				printf("O resultado de Tangente � %g\n\n",(valor1/valor2));
			}
			
			printf("Deseja realizar uma outra fun��o de trigonometria? (sim / nao): ");
			scanf("%s",&verifica);
			fflush(stdin);
			
			strupr(verifica);
			
			if(strcmp(verifica, "SIM") == 0){
				system("cls");
				trigonometria();
			}else if(strcmp(verifica, "NAO") == 0){
				system("cls");
				menu();
			}else{
				system("cls");
        		printf("Por favor, preencha como solicitado!\n\n");
        		menu();
			}
		break;
		case 4:
			system("cls");
			menu();
		break;
		default:
			system("cls");
        	printf("Por favor, preencha como solicitado!\n\n");
        	trigonometria();
		break;
	}
}

sair()
{
	system("cls");
	printf("Obrigado por utilizar nosso programa. Ele ser� encerrado agora!");
	exit(0);
}
