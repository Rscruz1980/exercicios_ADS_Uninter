#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Buscasequencial(int vet[], int buscado);
#define tamanhovetor 10

int main() {
	int vet[tamanhovetor] = { 0 };
	int buscado, achou;
	srand(time(NULL));             //gera a semente aleatoria

	// Inserção de dados
	for (int i = 0; i < tamanhovetor; i++)
		vet[i] = rand() % 1000;     // gera os valores aleatórios

	printf("Vetor Gerado: \n");
	for (int i = 0; i < tamanhovetor; i++)
		printf("%d\n", vet[i]);

	printf("Selecione um valor para buscar: \n");
	scanf_s("%d", &buscado);

	achou = Buscasequencial(vet, buscado);
	if (achou == -1)
		printf("Valor nao encontrado");
	else
		printf("Valor encontrado na posicao %d. \n", achou);


	system("pause");
	return 0;
}

int Buscasequencial(int vet[], int buscado)
{
	int achou, i;
	achou = 0;
	i = 0;

	while ((i <= tamanhovetor) && (achou == 0))
	{
		if (vet[i] == buscado)
			achou = 1;
		else i++;
	}
	if (achou == 0)
		return -1;
	else
		return i + 1;
}

