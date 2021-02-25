#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n;
	cin >> n;
	ll a[n], sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}
	// cout<<sum;
	bool dp[n + 1][sum + 1];
	for (ll i = 0; i < sum + 1; i++)
	{

		dp[0][i] = false;


	}
	for (ll i = 0; i < n + 1; i++)
	{
		dp[i][0] = true;
	}
	for (ll i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < sum + 1; ++j)
		{
			if (a[i - 1] <= j)
			{
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	vector<ll> ans;
	for (ll i = 0; i < sum / 2; i++)
	{
		if (dp[n][i] == true)
		{
			ans.push_back(i);
		}
	}
	ll m = INT_MAX;
	for (int i = 0; i < ans.size(); i++)
	{
		m = min(m, sum - 2 * ans[i]);
	}
	cout << m;


	return 0;
}