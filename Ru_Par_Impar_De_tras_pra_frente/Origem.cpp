#include <stdio.h>
#include <stdlib.h>  // iclui todas as bibliotecas.
#include <string.h>  

struct nomeRu {      // criando a struct , que armazena nome e RU.
	char Nome[40];
	int Ru;
};

int main() {
	struct nomeRu Cadastro, * ponteiro;  //Agora j� dentro do Main implemento 
	int tamanho, cont;                  //a struct, com a variavel cadastro.

	printf("\nDigite seu nome: ");     //pegando nome digitado e colocando em 
	fgets(Cadastro.Nome, 39, stdin);    //cadastro.Nome.

	printf("\nDigite o seu RU: ");    //tambem o RU 
	scanf_s("%d", &Cadastro.Ru);

	ponteiro = &Cadastro;    // criei um ponteiro(linha 11) e atribui a ele o 
							 // endereco de memoria da minha struct.
	if (ponteiro->Ru % 2 == 0) {
		printf("\nRU Par\n");
	}                 //neste if e else, testo para saber se o Ru eh par ou impar.
	else
		printf("\nRU Impar\n");

	tamanho = strlen(ponteiro->Nome);//aqui tamanho recebe a quantidade de caracteres 
	for (cont = tamanho; cont >= 0; cont--) { // da string.
		printf("%c", ponteiro->Nome[cont]);// e no for um decremento 
	}                                      // para printar o nome de tras pra frente.
	printf("\n");
	return 0;
};