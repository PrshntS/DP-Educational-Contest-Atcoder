#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n;
	cin>>n;
	vector<int> ans(3);
	for(int i=0;i<n;i++)
	{
		vector<int> dp(3,0);
		vector<int> a(3);
		for(int i=0;i<3;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(i!=j)
				{
					dp[j]=max(dp[j],ans[i]+a[j]);
				}
			}
		}
		ans=dp;
	}
	cout<<max({ans[0],ans[1],ans[2]});




	return 0;
}