#include <bits/stdc++.h>
using namespace std;
double dp[301][301][301];
double solve(int x,int y,int z,int &n)
{
    if(x<0||y<0||z<0)
    return 0;
    if(x==0 && y==0 && z==0)
    return 0;
    if(dp[x][y][z] > -0.9)
    return dp[x][y][z];
    int rem = x+y+z;
    double exp = n + x*solve(x-1,y,z,n) + y*solve(x+1,y-1,z,n) + z*solve(x,y+1,z-1,n);
    return dp[x][y][z] = exp/rem;  
}
int main() 
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    int x;
    int first = 0,second = 0,third = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x==1)
        first++;
        else if(x==2)
        second++;
        else if(x==3)
        third++;
    }
    cout<<fixed<<setprecision(10)<<solve(first,second,third,n);
}