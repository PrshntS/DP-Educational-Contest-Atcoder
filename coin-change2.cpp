#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx INT_MAX
#define mn INT_MIN
#define f(i,s,e) for(ll i=(s);i<(e);i++)
#define mod 1e9+7
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	ll n; cin>>n;
	ll a[n];
	f(i,0,n)
	{
		cin>>a[i];
	}
	ll sum=0; cin>>sum;
	ll dp[n+1][sum+1];
	for(ll i=0;i<sum+1;i++)
	{
		dp[0][i]=INT_MAX;
	}
	for(ll i=1;i<n+1;i++)
	{
		dp[i][0]=0;
	}
	f(i,1,n+1)
	{
		f(j,1,sum+1)
		{
			if(a[i-1]<=j)
			{
				dp[i][j]=min(dp[i-1][j-a[i-1]]+1,dp[i-1][j]);
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<<dp[n][sum];
	
	return 0;
}