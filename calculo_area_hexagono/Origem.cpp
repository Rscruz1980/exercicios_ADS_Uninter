#include <stdio.h>
#include <stdlib.h>

void calc_hexa(float l, float* area, float* perimetro); // cabe�alho da fun��o

int main() {
	float area_hex, perimetro_hexa, lado;
	printf(" Digite o lado do Hexagono: ");
	scanf_s("%f", &lado);
	if (lado < 0) {                                      // Aqui caso o lado digitado pelo usu�rio 
		printf("\n\n\"Algo de errado nao esta certo\" hahaha!!\n");//seja negativo o programa se encerra
		printf("Digite um numero positivo na proxima vez!!\n\n");//e ser� exibida 2 mensagens
		exit(0);                                                 //avisando do erro
	}                                                            //pedindo numero positivo na proxima!!         

	calc_hexa(lado, &area_hex, &perimetro_hexa);// chamando a fun��o e passando o endere�o de mem�ria 
	printf("\n\nO perimetro do hexagono eh : %.3f\n\n", perimetro_hexa);// como par�metro
	printf("A area do hexagono eh : %.3f\n\n", area_hex);
	printf("\n\n\n");
}

void calc_hexa(float l, float* area, float* perimetro) {  // fun��o j� passada pelo exercicio!!

	*perimetro = 6 * l;
	*area = (3 * l * l * 1.732) / 2;
}