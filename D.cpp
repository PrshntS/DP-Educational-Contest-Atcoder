#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, w;
	cin >> n >> w;
	int wt[n], val[n];
	for (int i = 0; i < n; i++)he
	{
		cin >> wt[i] >> val[i];
	}
	int dp[n + 1][w + 1];
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < w + 1; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else {
				if (wt[i - 1] <= j)
				{
					dp[i][j] = max((val[i - 1] + dp[i - 1][j - wt[i - 1]]), (dp[i - 1][j]));
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
				}
			}


		}
	}
	cout << dp[n][w];

	return 0;
}