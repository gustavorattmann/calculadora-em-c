#include <stdio.h> // Biblioteca padrão para alocação de memória, controle de processos, conversões e outras coisas.
#include <stdlib.h> // Biblioteca padrão para entrada e saída de dados.
#include <ctype.h> // Bibliote para funções como isalnum, isalfa, toupper, tolower e outros.
#include <math.h> // Biblioteca para operações matemáticas como raíz quadrada ou elevação.
#include <locale.h> // Biblioteca de idioma.

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"portuguese"); // Define o idioma de qualquer texto que será apresentado no console como Português, ou seja, apresentará caracteres com assento.
	
	menu();	// Realiza invocação do método menu.
	
	return 0; // Retorno 0 (falso) indica que não houve nenhum erro.
}

menu() // Método Menu.
{
	// Declarando variáveis globais.
	int tipo;
	
	printf("Dica: para que se ter uma melhor experiência visualmente com a janela de prompt de comando, maximize a tela.\n\n");
	printf("Observações: Se quiser usar números reais, utilize vírgula, pois se usar ponto, será considerado como inteiro.\n\n");
	printf("Escolha uma das opções abaixo:");
	printf("\n(1 - Tabuada / 2 - Raíz Quadrada / 3 - Cálculo / 4 - Fórmula de Bhaskara / 5 - Funções Trigonométricas / 6 - Sair): ");
	scanf("%i",&tipo); // %i, aloca e exibe apenas números antes da vírgula.
	fflush(stdin); // Limpa o buffer do teclado, para que não seja alocado a tecla enter em uma memória temporária,
				   // pois assim que ele for alocar a próxima variável, ele checará antes nessa memória.
	
	switch(tipo){ // Verifica a variável tipo.
		case 1: // Se for digitado o número 1, faz o seguinte procedimento.
			printf("\n"); // Serve para pular para a próxima linha, se for \n\n, pula duas linhas.
			tabuada(); // Realiza invocação do método tabuada.
		break; // Após executar os procedimentos acima, finaliza a escolha de caso.
		case 2:
			printf("\n");
			raiz(); // Realiza invocação do método raiz.
		break;
		case 3:
			printf("\n");
			calculo(); // Realiza invocação do método calculo.
		break;
		case 4:
			printf("\n");
			bhaskara(); // Realiza invocação do método bhaskara.
		break;
		case 5:
			printf("\n");
			trigonometria(); // Realiza invocação do método trigonometria.
		break;
		case 6:
			printf("\n");
			sair(); // Realiza invocação do método sair.
		break;
		default: // Se nenhum dos números solicitado for digitado, executará os procedimentos desse escolha de caso padrão.
			system("cls"); // Limpa a tela, apaga tudo que foi digitado anteriormente.
			printf("Por favor, preencha como solicitado!\n\n");
			menu(); // Realiza invocação do próprio método, para que ele seja repetido
		break;
	}
}

tabuada() // Método Tabuada.
{
    // Declarando variáveis globais.
	int valor, contador, resultado;
	char verifica[3];
	
	printf("Digite um número: ");
    scanf("%i",&valor);
    fflush(stdin);
	
    for(contador = 0; contador < 11; contador++){
        resultado = contador * valor;
        printf("%i x %i = %i\n",valor,contador,resultado);
    }
	
    printf("\nDeseja ver a tabuada com outro número? (sim / nao): ");
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

raiz(){ // Método Raíz
	// Declarando variáveis globais.
	float valor;
	char verifica[3];
	
	printf("Digite um número: ");
    scanf("%f",&valor);
    fflush(stdin);
    
    if(valor == (int)valor){ //Realizado comparação verificando se o valor digitado é decimal ou se é inteiro. Após a comparação de igual, é realizado um Cast (Conversão) do valor decimal para inteiro.
    	int resultado; // Se for decimal, será criado a variável resultado como inteiro.
		resultado = sqrt((int)valor); // A variável resultado recebe resultado da raíz como inteiro.
		printf("A raíz quadrada de %i é %i\n\n",(int)valor,resultado); // É exibido o resultado, convertendo o valor que é decimal para inteiro, para não exibir nenhum número depois da vírgula.
	}else{ // Se o valor for decimal, fará os procedimentos abaixo
		double resultado;
    	resultado = sqrt(valor);
    	printf("A raíz quadrada de %f é %f\n\n",valor,resultado);
	}
	
    printf("Deseja ver a raíz quadrada de outro número? (sim / nao): ");
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

calculo() // Método Cálculo
{
    // Declarando variáveis globais.
    int operador;
	float valor1, valor2;
	double resultado;
    char verifica[3];
	
	printf("Para efetuarmos um cálculo, será solicitado para digitar dois números em sequência e, por último, um número referente ao tipo de cálculo que deseja fazer.\n");
	printf("Digite um número: ");
    scanf("%f",&valor1);
    fflush(stdin);
    printf("Digite outro número: ");
    scanf("%f",&valor2);
    fflush(stdin);
    printf("\nQual operação deseja realizar?\n");
	printf("(1 - soma, 2 - subtração, 3 - multiplicação, 4 - divisão, 5 - resto de divisão, 6 - elevação de um número): ");
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
				printf("O resto de %i divido por %i é %i\n\n",(int)valor1,(int)valor2,(int)resultado);
			}else{
				system("cls");
            	printf("Por favor, digite números sem vírgula para realizar este cálculo!\n\n");
            	calculo();
			}
        break;
        case 6:
			if(valor1 == (int)valor1 && valor2 == (int)valor2){
				printf("A elevação de %i por %i é %i\n\n",(int)valor1,(int)valor2,pow((int)valor1,(int)valor2));
			}else if(valor1 == valor1 && valor2 == (int)valor2){
				printf("A elevação de %g por %i é %lg\n\n",valor1,(int)valor2,pow(valor1,(int)valor2));
			}else{
				system("cls");
            	printf("Por favor, digite o segundo número sem vírgula para realizar este cálculo!\n\n");
            	calculo();
			}
        break;
        default:
            system("cls");
            printf("Por favor, escreva o operador como solicitado!\n\n");
            calculo();
        break;
    }

    printf("Deseja fazer um novo cálculo? (sim / nao): ");
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

bhaskara() // Método Bhaskara
{
	// Declarando variáveis globais.
	float valor1, valor2, valor3, delta, x1, x2;
	char verifica[3];
	
	printf("Digite um número para A: ");
	scanf("%f",&valor1);
	fflush(stdin);
	printf("Digite um número para B: ");
	scanf("%f",&valor2);
	fflush(stdin);
	printf("Digite um número para C: ");
	scanf("%f",&valor3);
	fflush(stdin);
	
	if(valor1 == (int)valor1 && valor2 == (int)valor2 && valor3 == (int)valor3){
    	int delta;
		delta = sqrt(pow((int)valor2,2) - (4 * (int)valor1 * (int)valor3));
		
		if(delta > 0){
			x1 = ((-(int)valor2) + delta) / (2 * (int)valor1);
			x2 = ((-(int)valor2) - delta) / (2 * (int)valor1);
			
			if(x1 == (int)x1 && x2 == (int)x2){
				printf("A raíz de X¹ é %i\n",(int)x1);
				printf("A raíz de X² é %i\n\n",(int)x2);
			}else if(x1 == (int)x1 && x2 == x2){
				printf("A raíz de X¹ é %i\n",(int)x1);
				printf("A raíz de X² é %g\n\n",x2);
			}else if(x1 == x1 && x2 == (int)x2){
				printf("A raíz de X¹ é %g\n",x1);
				printf("A raíz de X² é %i\n\n",(int)x2);
			}else{
				printf("A raíz de X¹ é %g\n",x1);
				printf("A raíz de X² é %g\n\n",x2);
			}
		}else if(delta == 0){
			x1 = ((-(int)valor2) + delta) / (2 * (int)valor1);
			
			if(x1 == (int)x1){
				printf("Delta possui valor de %i, que é nulo, portanto há apenas uma raíz.\n",delta);
				printf("A raíz de X¹ é %i\n\n",(int)x1);
			}else{
				printf("Delta possui valor de %i, que é nulo, portanto há apenas uma raíz.\n",delta);
				printf("A raíz de X¹ é %g\n\n",x1);
			}
		}else{
			printf("Delta possui valor de %i, que é negativo, portanto não há nenhuma raíz.\n\n",delta);	
		}
	}else if(valor1 == (int)valor1 && valor2 == (int)valor2 && valor3 == valor3){
		float delta;
		delta = sqrt(pow((int)valor2,2) - (4 * (int)valor1 * valor3));
		
		if(delta >= 1){
			x1 = ((-(int)valor2) + delta) / (2 * (int)valor1);
			x2 = ((-(int)valor2) - delta) / (2 * (int)valor1);
			
			if(x1 == (int)x1 && x2 == (int)x2){
				printf("A raíz de X¹ é %i\n",(int)x1);
				printf("A raíz de X² é %i\n\n",(int)x2);
			}else if(x1 == (int)x1 && x2 == x2){
				printf("A raíz de X¹ é %i\n",(int)x1);
				printf("A raíz de X² é %g\n\n",x2);
			}else if(x1 == x1 && x2 == (int)x2){
				printf("A raíz de X¹ é %g\n",x1);
				printf("A raíz de X² é %i\n\n",(int)x2);
			}else{
				printf("A raíz de X¹ é %g\n",x1);
				printf("A raíz de X² é %g\n\n",x2);
			}
		}else if(delta == 0){
			x1 = ((-(int)valor2) + delta) / (2 * (int)valor1);
			
			if(x1 == (int)x1){
				printf("Delta possui valor de %i, que é nulo, portanto há apenas uma raíz.\n",delta);
				printf("A raíz de X¹ é %i\n\n",(int)x1);
			}else{
				printf("Delta possui valor de %i, que é nulo, portanto há apenas uma raíz.\n",delta);
				printf("A raíz de X¹ é %g\n\n",x1);
			}
		}else{
			printf("Delta possui valor de %f, que é negativo, portanto não há nenhuma raíz.\n\n",delta);	
		}
	}else if(valor1 == valor1 && valor2 == (int)valor2 && valor3 == (int)valor3){
		float delta;
		delta = sqrt(pow((int)valor2,2) - (4 * valor1 * (int)valor3));
		
		if(delta >= 1){
			x1 = ((-(int)valor2) + delta) / (2 * valor1);
			x2 = ((-(int)valor2) - delta) / (2 * valor1);
			
			if(x1 == (int)x1 && x2 == (int)x2){
				printf("A raíz de X¹ é %i\n",(int)x1);
				printf("A raíz de X² é %i\n\n",(int)x2);
			}else if(x1 == (int)x1 && x2 == x2){
				printf("A raíz de X¹ é %i\n",(int)x1);
				printf("A raíz de X² é %g\n\n",x2);
			}else if(x1 == x1 && x2 == (int)x2){
				printf("A raíz de X¹ é %g\n",x1);
				printf("A raíz de X² é %i\n\n",(int)x2);
			}else{
				printf("A raíz de X¹ é %g\n",x1);
				printf("A raíz de X² é %g\n\n",x2);
			}
		}else if(delta == 0){
			x1 = ((-(int)valor2) + delta) / (2 * valor1);
			
			if(x1 == (int)x1){
				printf("Delta possui valor de %i, que é nulo, portanto há apenas uma raíz.\n",delta);
				printf("A raíz de X¹ é %i\n\n",(int)x1);
			}else{
				printf("Delta possui valor de %i, que é nulo, portanto há apenas uma raíz.\n",delta);
				printf("A raíz de X¹ é %g\n\n",x1);
			}
		}else{
			printf("Delta possui valor de %f, que é negativo, portanto não há nenhuma raíz.\n\n",delta);	
		}
	}else if(valor1 == (int)valor1 && valor2 == valor2 && valor3 == (int)valor3){
		float delta;
		delta = sqrt(pow(valor2,2) - (4 * (int)valor1 * (int)valor3));
		
		if(delta >= 1){
			x1 = ((-valor2) + delta) / (2 * (int)valor1);
			x2 = ((-valor2) - delta) / (2 * (int)valor1);
			
			if(x1 == (int)x1 && x2 == (int)x2){
				printf("A raíz de X¹ é %i\n",(int)x1);
				printf("A raíz de X² é %i\n\n",(int)x2);
			}else if(x1 == (int)x1 && x2 == x2){
				printf("A raíz de X¹ é %i\n",(int)x1);
				printf("A raíz de X² é %g\n\n",x2);
			}else if(x1 == x1 && x2 == (int)x2){
				printf("A raíz de X¹ é %g\n",x1);
				printf("A raíz de X² é %i\n\n",(int)x2);
			}else{
				printf("A raíz de X¹ é %g\n",x1);
				printf("A raíz de X² é %g\n\n",x2);
			}
		}else if(delta == 0){
			x1 = ((-valor2) + delta) / (2 * (int)valor1);
			
			if(x1 == (int)x1){
				printf("Delta possui valor de %i, que é nulo, portanto há apenas uma raíz.\n",delta);
				printf("A raíz de X¹ é %i\n\n",(int)x1);
			}else{
				printf("Delta possui valor de %i, que é nulo, portanto há apenas uma raíz.\n",delta);
				printf("A raíz de X¹ é %g\n\n",x1);
			}
		}else{
			printf("Delta possui valor de %f, que é negativo, portanto não há nenhuma raíz.\n\n",delta);	
		}
	}else{
		float delta;
		delta = sqrt(pow(valor2,2) - (4 * valor1 * valor3));
		
		x1 = ((-valor2) + delta) / (2 * valor1);
			x2 = ((-valor2) - delta) / (2 * valor1);
		
		if(delta >= 1){
			printf("A raíz de X¹ é %g\n",x1);
			printf("A raíz de X² é %g\n\n",x2);
		}else if(delta == 0){
			x1 = ((-(int)valor2) + delta) / (2 * (int)valor1);
			
			
			printf("Delta possui valor de %i, que é nulo, portanto há apenas uma raíz.\n",delta);
			printf("A raíz de X¹ é %g\n\n",x1);
		}else{
			printf("Delta possui valor de %f, que é negativo, portanto não há nenhuma raíz.\n\n",delta);	
		}
	}
	
	printf("Deseja realizar uma nova fórmula de Bhaskara? (sim / nao): ");
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

trigonometria() // Método Trigonometria
{
	// Declarando variáveis globais.
	int tipo;
	float valor1, valor2;
	char verifica[3];
	
	printf("Qual função de trigonometria deseja realizar?\n");
	printf("(1 - Seno / 2 - Cosseno / 3 - Tangente / 4 - Voltar ao menu): ");
	scanf("%i",&tipo);
	fflush(stdin);
	
	switch(tipo){
		case 1:
			printf("\nDigite um número para o cateto oposto: ");
			scanf("%d",&valor1);
			fflush(stdin);
			printf("Digite um número para a hipotenusa: ");
			scanf("%d",&valor2);
			fflush(stdin);
			
			if(valor1 == (int)valor1 && valor2 == (int)valor2){
				printf("O resultado de Seno é %i\n\n",((int)valor1/(int)valor2));
			}else if(valor1 == (int)valor1 && valor2 == valor2){
				printf("O resultado de Seno é %g\n\n",((int)valor1/valor2));
			}else if(valor1 == valor1 && valor2 == (int)valor2){
				printf("O resultado de Seno é %g\n\n",(valor1/(int)valor2));
			}else{
				printf("O resultado de Seno é %g\n\n",(valor1/valor2));
			}
			
			printf("Deseja realizar uma outra função de trigonometria? (sim / nao): ");
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
			printf("\nDigite um número para o cateto adjacente: ");
			scanf("%d",&valor1);
			fflush(stdin);
			printf("Digite um número para a hipotenusa: ");
			scanf("%d",&valor2);
			fflush(stdin);
			
			if(valor1 == (int)valor1 && valor2 == (int)valor2){
				printf("O resultado de Cosseno é %i\n\n",((int)valor1/(int)valor2));
			}else if(valor1 == (int)valor1 && valor2 == valor2){
				printf("O resultado de Cosseno é %g\n\n",((int)valor1/valor2));
			}else if(valor1 == valor1 && valor2 == (int)valor2){
				printf("O resultado de Cosseno é %g\n\n",(valor1/(int)valor2));
			}else{
				printf("O resultado de Cosseno é %g\n\n",(valor1/valor2));
			}
			
			printf("Deseja realizar uma outra função de trigonometria? (sim / nao): ");
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
			printf("\nDigite um número para o cateto oposto: ");
			scanf("%d",&valor1);
			fflush(stdin);
			printf("Digite um número para o cateto adjacente: ");
			scanf("%d",&valor2);
			fflush(stdin);
			
			if(valor1 == (int)valor1 && valor2 == (int)valor2){
				printf("O resultado de Tangente é %i\n\n",((int)valor1/(int)valor2));
			}else if(valor1 == (int)valor1 && valor2 == valor2){
				printf("O resultado de Tangente é %g\n\n",((int)valor1/valor2));
			}else if(valor1 == valor1 && valor2 == (int)valor2){
				printf("O resultado de Tangente é %g\n\n",(valor1/(int)valor2));
			}else{
				printf("O resultado de Tangente é %g\n\n",(valor1/valor2));
			}
			
			printf("Deseja realizar uma outra função de trigonometria? (sim / nao): ");
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
	printf("Obrigado por utilizar nosso programa. Ele será encerrado agora!");
	exit(0);
}
