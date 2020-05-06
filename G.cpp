#include<iostream>
#include<bits/stdc++.h>
#define nodes 100010
using namespace std;
int dp[nodes];
int util(vector<vector<int>>&edges,int i)
{
  if(dp[i]>=0)
  return dp[i];
  if(edges[i].size()==0)
  {
    dp[i]=0;
    return dp[i];
  }
  for(auto v:edges[i])
    dp[i]=max(dp[i],1+util(edges,v));
  return dp[i];
}
int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int>> edges(n+1);
  for(int i=0;i<=n;i++)
  dp[i]=-1;
  for(int i=0;i<m;i++)
  {
    int x,y;
    cin>>x>>y;
    edges[x].push_back(y);
  }
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    if(dp[i]<0)
      ans=max(ans,util(edges,i));
  }
  cout<<ans<<endl;
  return 0;
}
