#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long util(vector<int>&w,vector<int>&v,int W)
{
  int n=w.size();
  long long dp[n+1][W+1];
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=W;j++)
    dp[i][j]=0;
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=W;j++)
    {
      if(w[i-1]>j)
      dp[i][j]=dp[i-1][j];
      else
      {
        dp[i][j]=max(dp[i-1][j],(long long)v[i-1]+dp[i-1][j-w[i-1]]);
      }
    }
  }
  return dp[n][W];
}
int main()
{
  int n,W;
  cin>>n>>W;
  vector<int> w,v;
  for(int i=0;i<n;i++)
  {
    int tw,tv;
    cin>>tw>>tv;
    w.push_back(tw);
    v.push_back(tv);
  }
  long long ans=util(w,v,W);
  cout<<ans<<endl;
  return 0;
}
