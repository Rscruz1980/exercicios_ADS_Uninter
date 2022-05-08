#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sAluno // criada a estrutura
{
    int ru;
    char nome[30];
    char email[30];
    struct sAluno* dir = NULL;
    struct sAluno* esq = NULL;

}Aluno;

typedef struct sArvore // estrutura da nossa arvore
{
    Aluno* raiz = NULL;

} Arvore;

void add(Arvore* arvore, char* nome, char* email, int ru)
{
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    strcpy_s(novo->email, email);
    novo->ru = ru;     //função que adiciona os dados
    novo->esq = NULL;
    novo->dir = NULL;
    strcpy_s(novo->nome, nome);

    if (arvore->raiz == NULL)//se a arvore estiver vazia
    {
        arvore->raiz = novo;
        return;
    }

    Aluno* ponteiro = arvore->raiz;
    Aluno* pai = NULL;
    while (ponteiro != NULL)
    {
        pai = ponteiro;
        if (ru > ponteiro->ru) {
            ponteiro = ponteiro->dir;
        }
        else {
            ponteiro = ponteiro->esq;
        }
    }
    if (ru > pai->ru) {
        pai->dir = novo;
    }
    else {
        pai->esq = novo;
    }
}

void imprimir(Aluno* ponteiro)// fazer a impressão 
{
    if (ponteiro == NULL)
        return;

    imprimir(ponteiro->esq);
    printf("\Ru : %d\nAluno: %s --- Email: %s \n", ponteiro->ru, ponteiro->nome, ponteiro->email);
    imprimir(ponteiro->dir);
}

void busca(Arvore arvore, int ru) {// fazendo a busca pelo RU

    Aluno* ponteiro = arvore.raiz;
    Aluno* pai = NULL;
    while (ponteiro != NULL && ru != ponteiro->ru)
    {
        if (ru > ponteiro->ru) {
            ponteiro = ponteiro->dir;
        }
        else {
            ponteiro = ponteiro->esq;
        }
    }

    if (ponteiro == NULL) {
        printf("\RU nao encontrado\n");
    }
    else {
        printf("\nRU : %d\nAluno: %s --- Email: %s \n", ponteiro->ru, ponteiro->nome, ponteiro->email);
    }


}

int menu()// não foi pedido, mas criei um menu,dá a opção de continuar consultando
{
    int op, c;


    printf("\nDigite a opcao desejada :\n");
    printf("1. Digitar o Numero do RU \n");
    printf("2. Sair\n");
    scanf_s("%d", &op);
    while ((c = getchar()) != '\n' && c != EOF) {}

    return op;

}



int main()
{
    int op, c;
    Arvore ab; // adicionei estes dados, Ru de 3640050 até 3640060, o Meu RU é 3640055.

    add(&ab, (char*)"Vinicius Borin", (char*)"vini_borin@hotmail.com", 3640050);
    add(&ab, (char*)"Luiza dos Santos", (char*)"lu_santos@gmail.com", 3640051);
    add(&ab, (char*)"Giseli Ribeiro", (char*)"gisele_1203@hotmail.com", 3640052);
    add(&ab, (char*)"Mariana Alice Cruz", (char*)"maricruz@gmail.com", 3640053);
    add(&ab, (char*)"Isabela Aline Cruz", (char*)"isabelaacruz@hotmail.com", 3640054);
    add(&ab, (char*)"Rodrigo da Silva Cruz", (char*)"1586.rodrigo@gmail.com", 3640055);
    add(&ab, (char*)"Vani dos Santos Cruz", (char*)"iva_gsantos@hotmail.com", 3640056);
    add(&ab, (char*)"Ana Paula de Almeida", (char*)"aninha_paula@gmail.com", 3640057);
    add(&ab, (char*)"Ana Claudia de Almeida", (char*)"claudinha_ana@hotmail.com", 3640058);
    add(&ab, (char*)"Davi Freitas", (char*)"davizinho_af@gmail.com", 3640059);
    add(&ab, (char*)"Zenilda da silva", (char*)"donazene@hotmail.com", 3640060);

    while (1)  // um switch para as opções do menu.
    {
        op = menu();
        switch (op)
        {
        case 1:
            int valor;
            printf("Digite o RU \n");
            scanf_s("%d", &valor);
            while ((c = getchar()) != '\n' && c != EOF) {}
            busca(ab, valor);
            break;
        case 2:
            return 0;

        default:
            printf("\nOpcao Invalida\n");// caso o RU não seja encontrado
        }

    }
    return 0;
}