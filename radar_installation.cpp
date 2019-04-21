#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct intervalo
{
    double ini, fim;
    
    bool operator < (const intervalo &i) const 
	{
        return (i.fim == fim) ? (ini < i.ini) : (fim < i.fim);
    }
    
} Intervalo;

long double x[10000], y[10000];

Intervalo inter[10000];

int main() 
{
    int n, d, t = 1;
    
    while(cin >> n >> d && !(n == 0 && d == 0)) 
	{
        for(int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
            
        int cont = 0, tudoBlz = true;
        
        for(int i = 0; i < n; i++) 
		{
            if(d < y[i]) 
			{
                tudoBlz = false;
                break;
            } 
            
			else 
			{
                long double raizd = sqrt(d * d - y[i] * y[i]);
                inter[i].ini = x[i] - raizd;
                inter[i].fim = x[i] + raizd;
            }
        }
        
        if(tudoBlz == false) 
		{
            cout << "Case " << t++ << ": " << -1 << "\n";
            continue;
        }
        
        sort(inter, inter + n);

        for(int i = 0; i < n;) 
		{
            int j;
            
            for(j = 0; j < n; j++) 
			{
                if(inter[j].ini > inter[i].fim)
                break;
            }
            
            i = j;
            cont++;
        }
        
        cout << "Case " << t++ << ": " << cont << "\n";
    }
    
    return 0;
}
