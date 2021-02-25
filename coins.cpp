#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx INT_MAX
#define mn INT_MIN
#define f(i,s,e) for(ll i=(s);i<(e);i++)
#define mod 1e9+7
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n; cin >> n;
	
	
	double a[n];
	f(i, 0, n) {cin >> a[i];}

	double dp[n+1][n+1];
	memset(dp,0.0,sizeof(dp));
	//initaliation
	dp[0][0] = 1.0;
	f(i, 1, n+1)
	{
		f(j, 0, i + 1)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j] * (1.0 - a[i - 1]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j] * (1.0 - a[i - 1]) + dp[i - 1][j - 1] * a[i - 1];
			}
		}

	}
	// cout<<dp[2][1];
	double ans=0.0;


	f(i,(n/2)+1,n+1)
	{
		ans+=dp[n][i];

	}
	cout<<setprecision(15)<<ans;

	return 0;
}