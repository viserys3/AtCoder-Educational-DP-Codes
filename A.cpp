#include<bits/stdc++.h>
#include<iostream>
using namespace std;
long long util(vector<int> heights,int n)
{
  long long dp[n];
  for(int i=0;i<n;i++)
  dp[i]=INT_MAX;
  dp[0]=0;
  dp[1]=abs(heights[0]-heights[1]);
  for(int i=2;i<n;i++)
  {
    dp[i]=min(dp[i-1]+abs(heights[i]-heights[i-1]),dp[i-2]+abs(heights[i]-heights[i-2]));
  }
  return dp[n-1];
}
int main()
{
  int n;
  cin>>n;
  vector<int> heights;
  for(int i=0;i<n;i++)
  {
    int temp;
    cin>>temp;
    heights.push_back(temp);
  }
  long long ans=util(heights,n);
  cout<<ans<<endl;
  return 0;
}
