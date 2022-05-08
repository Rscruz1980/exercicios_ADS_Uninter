#include <stdio.h>
#include <stdlib.h>

int potencia(int base, int expoente) {//criando a fun��o
	if (expoente == 0) {//se expoente for zero, resultado ser� 1.
		return 1;
	}
	else
		return (base * potencia(base, expoente - 1));
	// aqui ocorre as multiplica��es, 2*pot(2,9), 2*2*pot(2,8)...
}

int main() {

	int base, expoente, resultado;//criei as vari�veis

	printf("\nDigite a base do numero:  ");
	scanf_s("%d", &base);

	printf("\nDigite o expoente:  ");
	scanf_s("%d", &expoente);

	resultado = potencia(base, expoente);//resultado recebe resultado de pot�ncia

	printf("\n O resultado de  %d ^ %d  eh:  %d\n\n\n", base, expoente, resultado);

	return 0;

}