#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n, w;
	cin >> n >> w;
	ll wt[n + 1], v[n + 1];
	ll sum = 0;
	for (ll i = 0; i < n; i++)
	{
		cin >> wt[i] >> v[i];
		sum += v[i];
	}
	vector<vector<ll>>dp(n + 1, vector<ll>(sum + 1, INT_MAX));
	dp[0][0] = 0;
	ll ans = 0;
	for (ll i = 1; i < n + 1; i++)
	{
		for (ll j = 0; j < sum + 1; j++)
		{
			if (j == 0)
			{
				dp[i][j] = 0;
			}
			else if (v[i - 1] <= j)
			{
				dp[i][j] = min(wt[i - 1] + dp[i - 1][j - v[i - 1]], dp[i - 1][j]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
			if (dp[i][j] <= w)
			{
				ans = max(ans, j);
			}

		}
	}
	cout << ans;


	return 0;
}
