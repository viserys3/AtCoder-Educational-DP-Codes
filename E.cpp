#include<iostream>
#include<bits/stdc++.h>
#define vSumMax 100010
#define nMax 110
#define wMax 1000000000
using namespace std;
int dp[vSumMax][nMax]={INT_MAX};
bool vals[vSumMax][nMax]={0};
int fun(int value,int i,vector<int>&w,vector<int>&v,int n)
{
  if(value<=0)
  return 0;
  if(i==n)
  return wMax;
  if(vals[value][i])
  return dp[value][i];
  vals[value][i]=1;
  dp[value][i]=min(fun(value,i+1,w,v,n),w[i]+fun(value-v[i],i+1,w,v,n));
  return dp[value][i];
}
int util(vector<int>&w,vector<int>&v,int W)
{
  int n=w.size(),vSum=0;
  for(auto val:v)
  vSum+=val;
  for(int i=vSum;i>=0;i--)
  {
    if(fun(i,0,w,v,n)<=W)
    return i;
  }
  return 0;
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
  int ans=util(w,v,W);
  cout<<ans<<endl;
  return 0;
}
