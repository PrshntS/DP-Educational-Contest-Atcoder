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
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	vector<ll> ans(n+1);
	ans[0]=0;
	f(i,1,n)
	{
		ans[i]=max(ans[i-1]+a[i],a[i]);
	} 
	cout<<*max_element(ans.begin(),ans.end());


	return 0;
}