#include <iostream>
using namespace std;
int min(int a, int b) 
{
    if (a < b) 
	{
		return a;
	}
    else 
	{
		return b;
	}
}
int main() {
    int n;
    cout<<"enter number of matrices:";
    cin >> n;
    int p[n];
    cout<<"enter dimensions:";
    for (int i = 0; i < n; i++) 
	{
		cin >> p[i];
	}
    int dp[n][n];
    for (int i = 1; i < n; i++) 
	{
		dp[i][i] = 0;
	}
    for (int l = 2; l < n; l++) 
	{
        for (int i = 1; i < n - l + 1; i++) 
		{
            int j = i + l - 1;
            dp[i][j] = 99999999;
            for (int k = i; k < j; k++) 
			{
                int q = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
                dp[i][j] = min(dp[i][j], q);
            }
        }
    }
    cout << dp[1][n-1] << endl;
    return 0;
}
