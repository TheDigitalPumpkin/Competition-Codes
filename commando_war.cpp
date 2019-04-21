#include <iostream>
#include <algorithm>
using namespace std;

typedef struct tarefa
{
	int fala; int exec;
	
	friend bool operator < (const tarefa& a, const tarefa& b) 
	{
        return a.exec > b.exec;
    }   
} Tarefa;

int maximo(int a, int b)
{
	return a > b ? a : b;
}

Tarefa tarefas[1024];

int main()
{
	int n, f, e, c = 1;
	
	while(cin >> n && n != 0)
	{
		int x = 0, resposta = 0;
		
		for(int i = 0; i < n; i++)
		{
			cin >> f >> e;
			tarefas[i].fala = f;
			tarefas[i].exec = e;
		}
		
		sort(tarefas, tarefas + n);
		
		for(int i = 0; i < n; i++)
		{
			x += tarefas[i].fala;
			resposta = maximo(resposta, tarefas[i].exec + x);
		}
		
		cout << "Case " << c++ << ": " << resposta << "\n";
	}
	
	return 0;
}
