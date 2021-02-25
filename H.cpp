#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	ll H,W; cin>>H>>W;
	char maze[H][W];
	for(ll i=0;i<H;i++)
	{
		for(ll j=0;j<W;j++)
		{
			cin>>maze[i][j];
		}
	}
	ll dp[H][W];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(ll i=1;i<W;i++)
	{
		if(maze[0][i]=='.')
		{
			dp[0][i]=dp[0][i-1];
		}

	}
	for(ll i=1;i<H;i++)
	{
		if(maze[i][0]=='.')
		{
			dp[i][0]=dp[i-1][0];
		}
	}
	for(ll i=1;i<H;i++)
	{
		for(ll j=1;j<W;j++)
		{
			if(maze[i][j]=='.')
			{
				dp[i][j]=(dp[i-1][j]+dp[i][j-1]);
			}
		}
	}
cout<<dp[H-1][W-1];
	return 0;
}