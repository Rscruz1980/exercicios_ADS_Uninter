#include <stdio.h>
#include <stdlib.h>

int main() {
	int cont, RU[7], * ponteiro, maior = 0, posicaoMaior, menor = 50, posicaoMenor;

	//criei aqui um contador e o vetor[7] para armazenar o RU

	for (cont = 0; cont < 7; cont++) {// aqui cada valor e guardadado em um vetor de 0 at� 7 com o cont++
		printf("Digite o %d digito do seu RU: ", cont + 1);
		scanf_s("%d", &RU[cont]);//a posicao de memoria � incrementada pelo contador

	}
	ponteiro = RU; // criei um *ponteiro e ele recebe o endereco de memoria do vetor RU

	for (cont = 0; cont < 7; cont++) { // criei a variavel maior e posicao maior,
		if (ponteiro[cont] > maior) {  // iniciei a veriavel em "0" e quando o valor � > que maior
			maior = ponteiro[cont]; // maior recebe esse valor, assim achei o maior valor.
			posicaoMaior = cont; // coloquei tambem qual a sua posicao. 
		}
	}
	printf("\n O maior valor digitado foi ( %d ), e esta na posicao: %d", maior, posicaoMaior + 1);// coloquei possicao++
								   // para ser a posicao em que esta o numero e n�o a posicao do vetor.
	for (cont = 0; cont < 7; cont++) {
		if (ponteiro[cont] < menor) {// fiz o mesmo com o menor. Iniciei a variavel com "50" , sabendo que os 
			menor = ponteiro[cont];   // valores digitados seriam menores que isso.
			posicaoMenor = cont;
		}
	}
	printf("\n\nO menor valor digitado foi ( %d ), e esta na posicao %d", menor, posicaoMenor + 1);
	printf("\n\n\n");

	return 0;
}