#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int util(vector<int>&a,vector<int>&b,vector<int>&c)
{
  int n=a.size();
  int dp[n][3];
  for(int i=0;i<n;i++)
  {
    dp[i][0]=dp[i][1]=dp[i][2]=0;
  }
  dp[0][0]=a[0];
  dp[0][1]=b[0];
  dp[0][2]=c[0];
  for(int i=1;i<n;i++)
  {
    dp[i][0]=a[i]+max(dp[i-1][1],dp[i-1][2]);
    dp[i][1]=b[i]+max(dp[i-1][0],dp[i-1][2]);
    dp[i][2]=c[i]+max(dp[i-1][0],dp[i-1][1]);
  }
  return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
}
int main()
{
  int n;
  cin>>n;
  vector<int> a,b,c;
  for(int i=0;i<n;i++)
  {
    int ta,tb,tc;
    cin>>ta>>tb>>tc;
    a.push_back(ta);
    b.push_back(tb);
    c.push_back(tc);
  }
  int ans=util(a,b,c);
  cout<<ans<<endl;
  return 0;
}
