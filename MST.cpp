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
	ll l, r;
	cin >> l >> r;
	ll dp[l][r];
	f(i, 0, l)
	{
		f(j, 0, r)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 1;
			}
			else
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
	cout << dp[l - 1][r - 1];
	return 0;
}