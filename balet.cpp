#include <iostream>
#include <string.h>
using namespace std;

typedef struct bailarina
{
    int habilidade;
    int tempo;
} Bailarina;

int mergeConta(Bailarina* vet, int tam_vet)
{
	int meio;
	
	if(tam_vet <= 1)
	return 0;
	
	meio = tam_vet / 2;
	
	int contA = 0, contB = 0, contC = 0;
	contA = mergeConta(vet, meio);
	contB = mergeConta(vet + meio, tam_vet - meio);
	
	Bailarina* vetorParteA = new Bailarina[meio];
	Bailarina* vetorParteB = new Bailarina[tam_vet - meio];
	
	memcpy(vetorParteA, vet, sizeof(Bailarina) * meio);
	memcpy(vetorParteB, vet + meio, sizeof(Bailarina) * (tam_vet - meio));
	
	int i = 0, j = 0, k = 0;
	
	while(k < tam_vet)
	{
		if(vetorParteA[i].habilidade < vetorParteB[j].habilidade)
		{
			vet[k] = vetorParteA[i++];
			contC += j;
		}
		
		else
		{
			vet[k] = vetorParteB[j++];
			contC++;
		}
		
		k++;
		
		if(i >= meio || j >= (tam_vet - meio))
		break;
	}
	
	contC -= j;
	
	while(i < meio)
	{
		vet[k++] = vetorParteA[i++];
		contC += j;
	}
	
	while(j < (tam_vet - meio))
	{
		vet[k++] = vetorParteB[j++];
	}
	
	delete []vetorParteA;
	delete []vetorParteB;
	
	int cont = contA + contB + contC;
	
	return cont;
}

int main()
{
    int N;

    cin >> N;

    Bailarina* bailarinas = new Bailarina[N];
    int t = N;

    for(int i = 0; i < N; i++)
    {
        cin >> bailarinas[i].habilidade;
        bailarinas[i].tempo = t;
        t--;
    }

    int pares = 0;

    pares = mergeConta(bailarinas, N);

	cout << pares << "\n";

    return 0;
}
