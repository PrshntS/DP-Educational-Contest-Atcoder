#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n; cin >> n;
	ll a[n];
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	// cout<<sum;
	bool dp[n + 1][sum + 1];
	for (ll i = 0; i < n + 1; i++)
	{
		for (ll j = 0; j < sum + 1; j++)
		{
			if (i == 0)
			{
				dp[i][j] = false;
			}
			if (j == 0)
			{
				dp[i][j] = true;
			}
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
	cout << dp[n][sum];


	return 0;
}