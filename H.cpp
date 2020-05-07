#include<iostream>
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int util(vector<vector<char>>&grid)
{
  int h=grid.size(),w=grid[0].size();
  long long dp[h][w];
  for(int i=0;i<h;i++)
  {
    for(int j=0;j<w;j++)
    dp[i][j]=0;
  }
  dp[0][0]=1;
  for(int i=1;i<h;i++)
    if(grid[i][0]!='#')
    dp[i][0]=dp[i-1][0];
  for(int j=1;j<w;j++)
    if(grid[0][j]!='#')
    dp[0][j]=dp[0][j-1];
  for(int i=1;i<h;i++)
  {
    for(int j=1;j<w;j++)
    {
      if(grid[i][j]!='#')
      dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
    }
  }
  return dp[h-1][w-1]%mod;
}
int main()
{
  int h,w;
  cin>>h>>w;
  vector<vector<char>> grid;
  for(int i=0;i<h;i++)
  {
    vector<char> temp;
    for(int j=0;j<w;j++)
    {
      char c;
      cin>>c;
      temp.push_back(c);
    }
    grid.push_back(temp);
  }
  int ans=util(grid);
  cout<<ans<<endl;
  return 0;
}
