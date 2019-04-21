#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<char> vc;
char s1[1005], s2[1005];
int dp[105][105];

void backtrack(int i, int j)
{
    if(i == 0 || j == 0) return;
    
    else if(s1[i - 1] == s2[j - 1]) 
	{
        backtrack(i - 1, j - 1);
        vc.push_back(s1[i - 1]);
    }
    
    else 
	{
        if(dp[i][j - 1] > dp[i - 1][j])
        backtrack(i, j - 1);
        
        else
        backtrack(i - 1, j);
    }
}

void lcs()
{
    int n = strlen(s1);
    int m = strlen(s2);

    memset(dp, 0, sizeof(dp));

    for(int i = 0; i <= n; i++) 
		dp[i][0] = 0;
		
    for(int i = 0; i <= m; i++) 
		dp[0][i] = 0;	 

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i - 1] == s2[j - 1])
            dp[i][j] = dp[i - 1][j - 1] + 1;
            
            else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}

int main()
{
    while(scanf("%s %s", s1, s2) == 2)
    {
        vc.clear();
        int n = strlen(s1);
        int m = strlen(s2);
        lcs();
        backtrack(n, m);

        int l1 = 0, l2 = 0;

        for(int i = 0; i < vc.size(); i++)
        {
            while(l1 < n && s1[l1] != vc[i])
            {
                cout << s1[l1];
                ++l1;
            }

            while(l2 < m && s2[l2] != vc[i])
            {
                cout << s2[l2];
                ++l2;
            }

            cout << vc[i];
            ++l2;
            ++l1;
        }

        while(l1 < n)
        	cout << s1[l1++];
        	
        while(l2 < m)
            cout << s2[l2++];
            
        cout << "\n";
	}
	
	return 0;
}
