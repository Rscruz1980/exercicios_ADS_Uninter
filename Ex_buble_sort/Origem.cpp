#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int vet[]);
#define tamanhovetor 10

int main() {
	int vet[tamanhovetor] = { 0 };
	srand(time(NULL));             //gera a semente aleatoria

	// Inserção de dados
	for (int i = 0; i < tamanhovetor; i++)
		vet[i] = rand() % 100;     // gera os valores aleatórios

	printf("Vetor nao ordenado: \n");
	for (int i = 0; i < tamanhovetor; i++)
		printf("%d\n", vet[i]);

	BubbleSort(vet);

	printf("Vetor ordenado: \n");
	for (int i = 0; i < tamanhovetor; i++)
		printf("%d\n", vet[i]);

	system("pause");
	return 0;
}

void BubbleSort(int vet[])
{
	int aux;
	for (int n = 1; n <= tamanhovetor; n++) {
		for (int i = 0; i < (tamanhovetor - 1); i++)
		{
			if (vet[i] > vet[i + 1])  // crescente
			{
				aux = vet[i];
				vet[i] = vet[i + 1];
				vet[i + 1] = aux;

			}
		}

	}

}