#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int numTestes, numCarros, minutos, m, resposta = 0, posi = 0;
	int carritos[1440];
	
	cin >> numTestes;
	
	for(int i = 0; i < numTestes; i++)
	{
		cin >> numCarros >> minutos >> m;
		
		for(int j = 0; j < m; j++)
			cin >> carritos[j];
		
		resposta = 0;
		posi = 0;
		
		if(m % numCarros)
		{
			resposta = carritos[m % numCarros - 1] + 2 * minutos;
			posi = m % numCarros;
		}
		
		else
		{
			resposta = carritos[numCarros - 1] + 2 * minutos;
			posi = numCarros;
		}
		
		while(posi < m)
		{
			if(resposta >= carritos[posi + numCarros - 1])
			resposta += 2 * minutos;
			
			else
			resposta = carritos[posi + numCarros - 1] + 2 * minutos;
			
			posi += numCarros;
		}
		
		resposta -= minutos;
		
		cout << resposta << " " << (m + numCarros - 1) / numCarros << "\n";
	}
	
	return 0;
}
