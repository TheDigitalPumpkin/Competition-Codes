#include <iostream>
using namespace std;

int main() 
{
    int t, n, dados[1001];
    scanf("%d", &t);
    
    while(t--) 
    {
        scanf("%d", &n);
        
        for (int i = 0; i < n; i++) 
	scanf("%d", dados + i);
        
        int resultado = 0, soma = 0;
        
        for (int i = 0; i < n - 1; i++) 
        {
            if(soma + dados[i] < dados[i + 1])
            ++resultado, soma += dados[i];
        }
        
        ++resultado;
        printf("%d\n", resultado);
    }
    
    return 0;
}
