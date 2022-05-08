#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct sAluno
{
    char nome[15];       // 15
    int nota;            // 19
    struct sAluno* prox; // 23
} Aluno;

void add(Aluno** head, char* nome, int nota)
{

    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    novo->nota = nota;
    strcpy_s(novo->nome, nome);
    novo->prox = NULL;
    if (*head == NULL)
    {
        *head = novo;
        return;
    }
    Aluno* ptr = *head;
    while (ptr->prox != NULL)
        ptr = ptr->prox;

    ptr->prox = novo;
}

void imprimir(Aluno* head)
{

    while (head != NULL)
    {
        printf("Nome: %s Nota:%d\n", head->nome, head->nota);
     
        head = head->prox;
    }
}

void remover(Aluno** head, char* nome)
{
    Aluno* ptr = *head;
    Aluno* anterior = NULL;

    while (ptr != NULL && strcmp(ptr->nome, nome) != 0)
    {
        anterior = ptr;
        ptr = ptr->prox;
    }

    if (ptr == NULL)
    {
        printf("nome nao encontrado\n");
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

int main()
{

    Aluno* head = NULL;

    char nome[15];
    int nota;
    int opcao;
    printf("\nDigite uma opcao:\n");
    printf("1-Add:\n");
    printf("2-Remover:\n");
    printf("3-Listar:\n");
    printf("0-Sair:\n");
    scanf_s("%d", &opcao);

    while (opcao != 0)
    {

        if (opcao == 1)
        {
            printf("Digite um nome:\n");
            scanf_s("%s", &nome, 50);
            printf("Digite uma nota:\n");
            scanf_s("%d", &nota);
            add(&head, nome, nota);
        }
        else if (opcao == 2)
        {
            printf("Digite o nome de quem deseja remover:\n");
            scanf_s("%s", &nome, 50);
            remover(&head, nome);
        }
        else if (opcao == 3)
        {
            imprimir(head);
        }

        printf("\n\nDigite uma opcao:\n");
        printf("1-Add:\n");
        printf("2-Remover:\n");
        printf("3-Listar:\n");
        printf("0-Sair:\n");
        scanf_s("%d", &opcao);
    }

   

  

    return opcao;


}