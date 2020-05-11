#include<iostream>
#include<bits/stdc++.h>
#define Size 100005
using namespace std;
int dp[Size];
int util(int k,vector<int>&vec)
{
  if(dp[k]>0)
  return dp[k];
  for(auto v:vec)
  {
    if(k>=v&&util(k-v,vec)==2)
    {
      dp[k]=1;
      return dp[k];
    }
  }
  dp[k]=2;
  return dp[k];
}
int main()
{
  int n,k;
  cin>>n>>k;
  vector<int> vec;
  for(int i=0;i<n;i++)
  {
    int temp;
    cin>>temp;
    vec.push_back(temp);
  }
  for(int i=0;i<=k;i++)
  dp[i]=-1;
  dp[0]=2;
  int ans=util(k,vec);
  if(ans==1)
  cout<<"First"<<endl;
  else
  cout<<"Second"<<endl;
  return 0;
}
