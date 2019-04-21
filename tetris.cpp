#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct jogadores
{
    char nome[16];
    int pontuacao;
};

struct jogadores players[1001];

void troca(int* a, int* b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int cmp(const void * p1, const void * p2)
{
	int retorno = ((struct jogadores*)p2)->pontuacao - ((struct jogadores*)p1)->pontuacao;
	
	if(retorno != 0) return retorno;
	
	return strcmp(((struct jogadores*)p1)->nome, ((struct jogadores*)p2)->nome);
}

int partition(int vet[], int low, int high)
{
    int pivo = vet[high];
    int i = low - 1;
	int j = 0;
	
    for(j = low; j <= high - 1; j++)
    {
        if(vet[j] <= pivo)
        {
            i++;
            troca(&vet[i], &vet[j]);
        }
    }

    troca(&vet[i + 1], &vet[high]);
    return i + 1;
}

void quickSort(int vet[], int low, int high)
{
    if(low < high)
    {
        int pivot = partition(vet, low, high);

        quickSort(vet, low, pivot - 1);
        quickSort(vet, pivot + 1, high);
    }
}

int main()
{
    int J, pontos[12], posi = 1, teste = 1, n = 15000;

    while(scanf("%d", &J) && J != 0)
    {
        int pontuacoes[J];
		int i = 0, j = 0;

        for(i = 0; i < J; i++)
        {
            scanf("%s", players[i].nome);

            for(j = 0; j < 12; j++)
            {
                scanf("%d", &pontos[j]);
            }

            quickSort(pontos, 0, 11);

            for(j = 1; j < 11; j++)
            {
                players[i].pontuacao += pontos[j];
            }
        }

        qsort(players, J, sizeof(struct jogadores), cmp);
        
        int prev = n;
        printf("Teste %d\n", teste);
		teste++;

		for(i = 0; i < J; i++)
		{
			if(players[i].pontuacao != prev)
			posi = i + 1;
			
			printf("%d %d %s", posi, players[i].pontuacao, players[i].nome);
			printf("\n");
			prev = players[i].pontuacao;
		}
		
		for(i = 0; i < J; i++)
		{
			players[i].pontuacao = 0;
		}
		
		printf("\n");
    }

    return 0;
}
