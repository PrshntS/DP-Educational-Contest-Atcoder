#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string a, b;
	cin >> a >> b;
	// cout<<a<<b;
	ll m = a.length();
	ll n = b.length();
	// cout<<m<<n;
	ll dp[m + 1][n + 1];
	for (ll i = 0; i < m + 1; i++)
	{
		for (ll j = 0; j < n + 1; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	string ans="";
	ll i=m,j=n;
	while(i>0&&j>0)
	{
		if(a[i-1]==b[j-1])
		{
			ans+=a[i-1];
			i--;
			j--;
		}

		else
		{
			if(dp[i-1][j]>dp[i][j-1])
			{
				i--;
			}
			else
			{
				j--;
			}
		}
	}
	for(int i=ans.length()-1;i>=0;i--)
	{
		cout<<ans[i];
	}

	return 0;
}