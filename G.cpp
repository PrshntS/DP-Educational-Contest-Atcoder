#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx INT_MAX
#define mn INT_MIN
#define f(i,s,e) for(ll i=(s);i<(e);i++)
#define mod 1e9+7
ll size=1e5+5;
vector<ll> a[100005];
vector<bool> visited(size,false);
vector<ll> dp(size,0);
void dfs(ll b)
{
	visited[b]=true;
	for(auto x: a[b])
	{
		if(!visited[x])
		{
			dfs(x);
		}
		dp[b]=max(dp[b],dp[x]+1);
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll ans=0;
	ll n,m; cin>>n>>m;
	f(i,0,m)
	{
		ll x,y;
		cin>>x>>y;
		a[x].push_back(y);
	}
	f(i,1,n+1)
	{
		if(!visited[i])
			dfs(i);
	}
	f(i,1,n+1)
	{
		ans=max(ans,dp[i]);
	}
	cout<<ans;


	return 0;
}