#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool equal_subset(ll a[], ll sum, ll n)
{
	bool dp[n + 1][sum + 1];
	for(ll i=0;i<sum+1;i++)
	{
		dp[0][i]=0;
	}
	for(ll i=0;i<n+1;i++)
	{
		dp[i][0]=1;
	}
	for (ll i = 1; i < n + 1; i++)
	{
		for (ll j = 1; j < sum + 1; j++)
		{
			if (a[i - 1] <= j)
			{
				dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[n][sum];

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n; cin >> n;
	ll a[n], sum = 0;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	if (sum % 2 != 0)
	{
		cout << false;
	}
	else
	{cout << equal_subset(a, sum / 2, n);}




	return 0;
}