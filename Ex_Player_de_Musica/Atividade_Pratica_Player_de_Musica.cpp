#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


typedef struct lista { // criada a estrutura com nome, artista e duração.
	char nome[30];
	char artista[30];
	char duracao[10];

	struct lista* prox;

}Lista;

void InsereMusica_Inicio(Lista** head, char* nome, char* artista, char* duracao)
{

	lista* Novo = (Lista*)malloc(sizeof(Lista));
	strcpy_s(Novo->nome, nome);
	Novo->prox = NULL;
	strcpy_s(Novo->artista, artista);// Função para inserir músicas no Inicio da Lista.
	Novo->prox = NULL;
	strcpy_s(Novo->duracao, duracao);
	Novo->prox = NULL;

	if (*head == NULL)
	{
		*head = Novo;
		return;
	}
	else
	{
		Novo->prox = *head;
		*head = Novo;
	}

}

void InsereMusica_Fim(Lista** head, char* nome, char* artista, char* duracao)
{

	lista* Novo = (Lista*)malloc(sizeof(Lista));
	strcpy_s(Novo->nome, nome);
	Novo->prox = NULL;         // Função para inserir músicas no Final da Lista.
	strcpy_s(Novo->artista, artista);
	Novo->prox = NULL;
	strcpy_s(Novo->duracao, duracao);
	Novo->prox = NULL;

	if (*head == NULL)
	{
		*head = Novo;
		return;
	}
	Lista* ptr = *head;
	while (ptr->prox != NULL)
		ptr = ptr->prox;

	ptr->prox = Novo;
}

void listar(Lista* head)
{
	while (head != NULL)// Função para listar a playlist criada.
	{
		printf("  %s\n  %s\n  [%s]min. \n\n", head->nome, head->artista, head->duracao);

		head = head->prox;

	}

}

void Remover_faixa(Lista** head, char* nome)
{
	Lista* ptr = *head;
	Lista* anterior = NULL;// Função para remover uma Música.

	while (ptr != NULL && strcmp(ptr->nome, nome) != 0)
	{
		anterior = ptr;
		ptr = ptr->prox;
	}

	if (ptr == NULL)
	{
		printf("Faixa nao encontrada\n");
	}
	else if (anterior == NULL)
	{
		*head = ptr->prox;
		free(ptr);
	}
	else
	{
		anterior->prox = ptr->prox;
		free(ptr);
	}
}

int menu() {//criei um menu que pede ao usuário escolher entre 5 opções.

	int op, c;

	printf("\n Digite a opcao desejada:\n");
	printf(" 1. Incluir Nova Musica no Inicio da lista:\n");
	printf(" 2. Incluir Nova Musica no Fim da lista:\n");
	printf(" 3. Listar Playlist:\n");
	printf(" 4. Remover faixa:\n");
	printf(" 5. Sair:\n");
	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {}

	return op;
}


int main() {
	                                                                               
	Lista* head = NULL;												       
	char nome[30];                                                         
	char artista[30];
	char duracao[10];
	int op,c;

	while (1) {

		op = menu();
		switch (op)
		{
		case 1://caso digite 1, insere música no início.
			printf("Digite o nome da Musica : \n");
			gets_s(nome);
			printf("Digite o nome do Artista :\n");
			gets_s(artista);
			printf("Digite a duracao :\n");
			gets_s(duracao);
			InsereMusica_Inicio(&head, nome, artista, duracao);
			break;
		case 2://digitando 2, insere no final.
			printf("Digite o nome da Musica : \n");
			gets_s(nome);
			printf("Digite o nome do Artista :\n");
			gets_s(artista);
			printf("Digite a duracao :\n");
			gets_s(duracao);
			InsereMusica_Fim(&head, nome, artista, duracao);
			break;
		case 3:
			listar(head);//Mostra a playlist criada

			break;
		case 4:// Remove a faixa indicada pelo usuário
			printf("Digite o nome de quem deseja remover:\n");
			gets_s(nome);
			Remover_faixa(&head, nome);
			break;
		case 5:// encerra o programa.
			return 0;
		default:
			printf("Invalido");

		}
	}

	return 0;
}

