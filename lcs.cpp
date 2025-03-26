#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char X[]="AGGTAB";
    char Y[]="GXTXAYB";
    int m=strlen(X);
	int n =strlen(Y);
    int dp[m + 1][n + 1];
    char path[m][n];
    for (int i = 0; i <= m; i++) 
	{
        for (int j = 0; j <= n; j++) 
		{
            if (i==0 || j==0)
                dp[i][j]=0;
            else if (X[i-1]==Y[j-1]) 
			{
                dp[i][j]=dp[i-1][j-1]+1;
                path[i-1][j-1] = '\\'; 
            } 
			else if (dp[i-1][j] > dp[i][j-1]) 
			{
                dp[i][j] = dp[i-1][j];
                path[i-1][j-1] = '^';
            } 
			else 
			{
                dp[i][j] = dp[i][j-1];
                path[i-1][j-1] = '<';
            }
        }
    }
    int length=dp[m][n];
    cout<<"length of lcs:"<<length<<endl;
    cout<<"\nlcs length table:\n";
    for (int i=0;i<= m;i++) 
	{
        for (int j=0;j<=n;j++) 
		{
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\nbacktracking path table:\n";
    for (int i=0;i<m;i++)
	{
        for (int j=0; j<n;j++) 
		{
            cout<<path[i][j]<<" ";
        }
        cout << endl;
    }
    char lcs[length + 1];
    lcs[length] = '\0';
    int i=m-1,j=n-1;
	int index=length-1;
    while (i>=0 && j>=0) 
	{
        if (path[i][j]=='\\') 
		{
            lcs[index] = X[i];
            index--;
            i--;
            j--;
        } 
		else if (path[i][j]=='^') 
		{
            i--;
        } 
		else 
		{
            j--;
        }
    }
    cout<<"lcs:"<<lcs<<endl;
    return 0;
}
