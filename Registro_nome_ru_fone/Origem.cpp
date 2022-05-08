#include <stdio.h>
#include <stdlib.h>

void limpa_buffer() { //elimina o buffer usado nos scanf
	int ch;
	while ((ch = fgetc(stdin)) != EOF && ch != '\n') {}
}

struct dados { // armazenando os dados da struct
	char Nome[50];
	int Ru;
	int Tel;
	char Email[40];
};

FILE* stream; // ponteiro Stream, do tipo FILe para manipular os arquivos

int main() {

	struct dados registro[10]; // inserindo � struct como "registro"
	int cont; // criando um contador
	errno_t err; // para tratar o erro de abertura do arquivo

	for (cont = 0; cont < 10; cont++) {//criando o la�o  para os 10 registros inseridos
		printf("\nDigite o Nome do Registro %d   ", cont + 1);
		gets_s(registro[cont].Nome, 50);  // inserindo o Nome solicitado    

		printf("Digite o RU do Registro   %d   ", cont + 1);
		scanf_s("%d", &registro[cont].Ru); // inserindo o RU solicitado
		limpa_buffer();

		printf("Digite o Tel do Registro  %d   ", cont + 1);
		scanf_s("%d", &registro[cont].Tel); // inserindo telefone solicitado
		limpa_buffer();

		printf("Digite o Email do Registro %d  ", cont + 1);
		gets_s(registro[cont].Email, 29); // inserindo e-mail solicitado

	}

	err = fopen_s(&stream, "Ru_3657975.CSV", "w"); //criando o arquivo.CSV
	if (err == 0) { // com nu do RU e modo "w" para escrever
		printf("\n\nArquivo criado com sucesso.\n");
	} // se apresentar erro 
	else {
		printf("DEU ERRO!!!"); // se der erro exibir � mensagem e encerrar o programa
		exit(1);
	}
	fprintf(stream, "Nome;Ru;Telefone;Email\n");

	for (cont = 0; cont < 10; cont++) {
		fprintf(stream, "%s;%d;%d;%s\n", registro[cont].Nome, registro[cont].Ru, registro[cont].Tel, registro[cont].Email);
		//no fluxo stream, armazenado todas as vari�veis e separadas por ";"
	}
	_fcloseall(); //fechando e encerrando arquivo
	printf("\n\nArquivo gerado com sucesso.\n\n");

	return 0;

}