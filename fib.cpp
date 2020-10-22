#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int t;
	cin>>t;
	int fib[t+1];
	fib[0]=0;
	fib[1]=1;
	for(int i=2;i<t+1;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
	cout<<fib[t-1];

	return 0;
}