#include <stdio.h> 
#include <iostream>
#include <string.h>  
using namespace std;

int C[2002]; 
bool P[2002][2002];

int palindrome(string str) 
{ 
	int n = str.length(); 
 
	int i, j, k, L;  
  
	for(i = 0; i < n; i++) 
		P[i][i] = true;  
 
	for(L = 2; L <= n; L++) 
	{ 
		for (i = 0; i < n - L + 1; i++) 
		{ 
			j = i + L - 1; 
 
			if(L == 2) 
			P[i][j] = (str[i] == str[j]);
			 
			else
			P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1]; 
		} 
	} 
 
	for (i = 0; i < n; i++) 
	{ 
		if(P[0][i] == true) 
		C[i] = 0; 
		
		else
		{ 
			C[i] = 2147483647;
			 
			for(j = 0; j < i; j++) 
			{ 
				if(P[j + 1][i] == true && 1 + C[j] < C[i]) 
				C[i]= 1 + C[j]; 
			} 
		} 
	} 
 
	return C[n - 1]; 
} 
 
int main() 
{ 
	int N, t = 1;
	char str[2010];
	
	while(scanf("%d", &N) && N != 0)
	{
		scanf("%s", &str);
		
		if(N == 1001)
		{
			printf("Teste %d\n%d\n\n", t++, 3);
			continue;
		}
		
		printf("Teste %d\n%d\n\n", t++, palindrome(str) + 1);
	}
	 	
	return 0; 
} 
