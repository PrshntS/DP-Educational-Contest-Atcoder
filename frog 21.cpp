#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	ll n,k;
	cin>>n>>k;
	ll a[n];
	ll dp[n+1];
		for(ll i = 0;i < n;i++){
		cin >> a[i];
	}
	dp[0] = 0;
	dp[1] = abs(a[1] - a[0]);
	for(ll i = 2;i < n+1;i++){
		dp[i] = INT_MAX;
		for(ll j = 0;j < min(k + 1 , i + 1);j++){
			dp[i] = min(dp[i] , abs(a[i] - a[i - j]) + dp[i - j]);
		}
	}
	cout << dp[n - 1] << endl;
	
	return 0;
}