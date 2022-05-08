#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));

	int x = rand() % 1000;
	int chute;
	
	while (true)
	{
		printf("Chute um numero entre 0 e 1000 :\n");
		scanf_s("%d",&chute);
		if (chute > x)
			printf("Seu chute foi maior que o numero sorteado\n\n");
		else if (chute < x)
			printf("Seu chute foi menor que o numero sorteado\n\n");
		else {
			printf("\nDemorou...\n Mas agora acertou!!!\n\n");
			break;
		}

	}
	return 0;

}