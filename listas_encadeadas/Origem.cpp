#include <stdio.h>
#include <stdlib.h>

int menu();
void InserirInicio(int num);
void InserirMeio(int num, int posicao);
void InserirFim(int num);
int Remover(int num);
void Listar();

struct ElementoDaLista_simples
{
	int dado;
	struct ElementoDaLista_simples *prox;

} *Head;   // head declarado como global

int main() {

	int op, num, pos, c;
	Head = NULL;

	while (1) {

		op = menu();
		switch (op){

		case 1:  // inserir no inicio da lista
			printf("Digite o numero desejado: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {}
			InserirInicio(num);
			break;
		case 2:  // inserir no fim da lista
			printf("Digite o numero desejado: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {}
			InserirFim(num);
			break;
		case 3:  // inserir no meio da lista
			printf("Digite o numero desejado: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {}
			printf("Digite a posicao desejada: ");
			scanf_s("%d", &pos);
			while ((c = getchar()) != '\n' && c != EOF) {}
			InserirMeio(num, pos);
			break;
		case 4:  // remover da lista
			int res;
			printf("Digite o numero a ser removido: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
			res = Remover(num);
			if (res == 1)
				printf("Numero removido.");
			else
				printf("Numero nao encontrado.");
			break;
		case 5: // mostrar toda lista
			Listar();

			break;
		case 6:    // Sair do programa
			return 0;
		default:
			printf("Invalido\n");
		}

		
	}
	return 0;
}

int menu() {

	int op, c;
	system("Cls");

	printf("1. Inserir no inicio da lista encadeada simples\n");
	printf("2. Inserir no fim da lista encadeada simples\n");
	printf("3. Inseri no meio da lista encadeada simples\n");
	printf("4. Remover da lista encadeada simples\n");
	printf("5. Mostrar a lista encadeada simples\n");
	printf("6. Sair\n");
	printf("Digite sua escolha: ");

	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o 

	system("Cls");
	return op;

}

void InserirInicio(int num)
{
	ElementoDaLista_simples* NovoElemento;
	//linha de baixo aloca o elemento na memoria
	NovoElemento = (struct  ElementoDaLista_simples *)malloc(sizeof(struct ElementoDaLista_simples));
	NovoElemento->dado = num;


	if (Head == NULL)
	{
		Head = NovoElemento;  // caso a lista esteja vazia
		Head->prox = NULL;
	}
	else
	{
		NovoElemento->prox = Head; // senao insere novo no lugar do head e ele passa a ser o red
		Head = NovoElemento;
	}
}

void InserirMeio(int num, int posicao) 
{

	ElementoDaLista_simples* NovoElemento;
	NovoElemento = (struct  ElementoDaLista_simples*)malloc(sizeof(struct ElementoDaLista_simples));
	ElementoDaLista_simples* ElementoVarredura;
	ElementoVarredura = (struct  ElementoDaLista_simples*)malloc(sizeof(struct ElementoDaLista_simples));
	ElementoDaLista_simples* ElementoAuxiliar;
	ElementoAuxiliar = (struct  ElementoDaLista_simples*)malloc(sizeof(struct ElementoDaLista_simples));

	NovoElemento->dado = num;

	if (posicao == 0) 
	{
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		ElementoVarredura = Head;
		for (int i = 0; i < posicao - 1; i++)
			ElementoVarredura = ElementoVarredura->prox;

		ElementoAuxiliar = ElementoVarredura->prox;
		ElementoVarredura->prox = NovoElemento;
		NovoElemento->prox = ElementoAuxiliar;
	}
}

void InserirFim(int num) {

	ElementoDaLista_simples* NovoElemento;
	NovoElemento = (struct  ElementoDaLista_simples*)malloc(sizeof(struct ElementoDaLista_simples));

	ElementoDaLista_simples* ElementoVarredura;
	ElementoVarredura = (struct  ElementoDaLista_simples*)malloc(sizeof(struct ElementoDaLista_simples));

	NovoElemento->dado = num;
	if (Head == NULL) {
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else {
		ElementoVarredura = Head;
		while (ElementoVarredura->prox != NULL)
			ElementoVarredura = ElementoVarredura->prox;

		ElementoVarredura->prox = NovoElemento;
		NovoElemento->prox = NULL;
		
	}

}

int Remover(int num)
{
	ElementoDaLista_simples* ElementoVarredura;
	ElementoVarredura = (struct  ElementoDaLista_simples*)malloc(sizeof(struct ElementoDaLista_simples));
	ElementoDaLista_simples* Anterior;
	Anterior = (struct  ElementoDaLista_simples*)malloc(sizeof(struct ElementoDaLista_simples));

	ElementoVarredura = Head;
	while (ElementoVarredura != NULL) {
		if (ElementoVarredura->dado == num) {
			if (ElementoVarredura == Head) {
				Head = ElementoVarredura->prox;
				free(ElementoVarredura);
				return 1;
			}
			else {
				Anterior->prox = ElementoVarredura->prox;
				free(ElementoVarredura);
				return 1;
			}
		}
		else {
			Anterior = ElementoVarredura;
			ElementoVarredura = ElementoVarredura->prox;
		}
	}
	return 0;
}

void Listar()
{
	ElementoDaLista_simples* ElementoVarredura;
	ElementoVarredura = (struct  ElementoDaLista_simples*)malloc(sizeof(struct ElementoDaLista_simples));

	ElementoVarredura = Head;
	if (ElementoVarredura == NULL) {
		return;
	}
	while (ElementoVarredura != NULL) {
		printf("%d ", ElementoVarredura->dado);
		ElementoVarredura = ElementoVarredura->prox;
	}
	printf("\n");

	system("pause");
	return;
}
