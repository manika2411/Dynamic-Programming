#include <iostream>
using namespace std;
int main() 
{
    int n,w;
    cout<<"enter number of items:";
    cin>>n;
    int val[n],wt[n];
    cout<<"enter values of items:";
    for (int i=0; i<n; i++)
    {
    	cin>>val[i]; 
	}       
    cout<<"enter weights of items:";
    for (int i=0; i<n; i++)
    {
    	cin>>wt[i];
	}   
    cout<<"enter knapsack capacity:";
    cin>>w;   
    int dp[n+1][w+1];   
    for (int i=0; i<=n; i++) 
	{
        for (int j=0; j<= w;j++) 
		{
            if (i== 0|| j==0)
            {
            	dp[i][j]=0;
			}
            else if (wt[i-1]<=j)
            {
            	dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
			}
            else
            {
            	dp[i][j]=dp[i-1][j];
			}
        }
    }  
    cout<<"maximum value in knapsack:"<<dp[n][w]<<endl;
    cout<<"items chosen:";
    int i= n;
	int j = w;
    while (i>0 && j>0) 
	{
        if (dp[i][j]!=dp[i-1][j]) 
		{
            cout<<i<<" ";
            j=j-wt[i-1];
        }
        i--;
    }
    cout<<endl;
    return 0;
}
