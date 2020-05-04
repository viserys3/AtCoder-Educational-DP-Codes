#include<bits/stdc++.h>
#include<iostream>
using namespace std;
long long util(vector<int> heights,int n,int k)
{
  long long dp[n];
  for(int i=0;i<n;i++)
  dp[i]=INT_MAX;
  dp[0]=0;
  dp[1]=abs(heights[0]-heights[1]);
  for(int i=2;i<n;i++)
  {
    for(int j=1;j<=k;j++)
    {
      if(i-j>=0)
      dp[i]=min(dp[i],dp[i-j]+abs(heights[i]-heights[i-j]));
    }
  }
  return dp[n-1];
}
int main()
{
  int n,k;
  cin>>n>>k;
  vector<int> heights;
  for(int i=0;i<n;i++)
  {
    int temp;
    cin>>temp;
    heights.push_back(temp);
  }
  long long ans=util(heights,n,k);
  cout<<ans<<endl;
  return 0;
}
