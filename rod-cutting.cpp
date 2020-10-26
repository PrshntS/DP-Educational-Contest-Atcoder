#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "length", stdout);
#endif
	int n, length;
	cin >> n >> length;
	int len[n], price[n];
	for (int i = 0; i < n; i++)
	{
		cin >> len[i] >> price[i];
	}
	int dp[n + 1][length + 1];
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < length + 1; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else {
				if (len[i - 1] <= j)
				{
					dp[i][j] = max((price[i - 1] + dp[i][j - len[i - 1]]), (dp[i - 1][j]));
				}
				else
				{
					dp[i][j] = dp[i - 1][j];
				}
			}


		}
	}
	cout << dp[n][length];

	return 0;
}