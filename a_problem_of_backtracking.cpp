#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

const int TAM_PERM = 10;

void imprimePerm(int* perm, int indiceAtual) 
{
    for(int i = 0; i < indiceAtual; i++) 
        cout << perm[i] << " ";
    
    cout << "\n";
}

bool backtrack(int* perm, int indiceAtual, int somaAtual, const int* const entrada, int K) 
{ 
    if(indiceAtual > TAM_PERM) 
    return false;

    if(somaAtual > K)
    return false;

    if(indiceAtual == TAM_PERM) 
	{
        imprimePerm(perm, indiceAtual);
        return true;
    }

    for(int j = 0; j < 10; j++) 
	{
        bool tudoBlzinha = true;
        
        for(int b = 0; b < indiceAtual; b++) 
		{
            if(perm[b] == j) 
			{
                tudoBlzinha = false;
                break;
            }
        }
        
        if(!tudoBlzinha) 
        continue;
        

        perm[indiceAtual] = j;
        int somaProx = somaAtual + j * entrada[indiceAtual];
        
        if(backtrack(perm, indiceAtual + 1, somaProx, entrada, K))
        return true;
    } 

    return false;
}

/////////////////////////////////////////////////////

void LeEntrada(int* entrada, int& K) 
{
    string entrada;
    getline(cin, entrada);
    stringstream stream(entrada);
    
    for(int i = 0; i < TAM_PERM; ++i) 
	{
        if(!(stream >> entrada[i])) 
        throw std::runtime_error("lascou-se\n");      
    }

    getline(cin, entrada);
    K = std::stoi(entrada);
}


int main(int argc, char* argv[]) 
{
    unsigned t;

    string entrada;
    getline(std::cin, entrada);
    t = std::stoi(entrada);
    
    if(t == 0)
    return 0;

    for(int i = 0; i < t; i++) 
	{
        int entrada[TAM_PERM];
        int K;
        LeEntrada(entrada, K);

        int perm[TAM_PERM + 1];
        
        if(!backtrack(perm, 0, 0, entrada, K)) 
        cout << "-1\n";
    }

    return 0;
}
