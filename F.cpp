#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string util(string s,string t)
{
  int m=s.length(),n=t.length();
  int dp[m+1][n+1],index[m+1][n+1];
  for(int i=0;i<=m;i++)
  dp[i][0]=0,index[i][0]=-1;
  for(int j=0;j<=n;j++)
  dp[0][j]=0,index[0][j]=-1;
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(s[i-1]==t[j-1])
      dp[i][j]=dp[i-1][j-1]+1,index[i][j]=2;
      else
      {
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        if(dp[i-1][j]>=dp[i][j-1])
        index[i][j]=0;
        else
        index[i][j]=1;
      }
    }
  }
  string ans="";
  int i=m,j=n;
  while(i>0&&j>0)
  {
    if(index[i][j]==2)
    {
      ans=s[i-1]+ans;
      i--,j--;
    }
    else if(index[i][j]==1)
    j--;
    else
    i--;
  }
  return ans;
}
int main()
{
  string s,t;
  cin>>s>>t;
  string ans=util(s,t);
  cout<<ans<<endl;
  return 0;
}
