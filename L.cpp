#include<iostream>
#include<bits/stdc++.h>
#define Size 3001
#define ll long long
using namespace std;
ll dp[Size][Size][2];
ll util(int s,int e,int turn,vector<int>&vec,vector<ll>&sum)
{
  if(s>e)
  return 0;
  if(dp[s][e][turn]>0)
  return dp[s][e][turn];
  ll sum1=sum[e]-sum[s],sum2=0;
  if(s==0)
  sum2=sum[e-1];
  else
  sum2=sum[e-1]-sum[s-1];
  dp[s][e][turn]=max((ll)vec[s]+sum1-util(s+1,e,(turn+1)%2,vec,sum),(ll)vec[e]+sum2-util(s,e-1,(turn+1)%2,vec,sum));
  return dp[s][e][turn];
}
int main()
{
  int n;
  cin>>n;
  vector<ll> sum(n);
  vector<int> vec;
  for(int i=0;i<n;i++)
  {
    int a;
    cin>>a;
    if(i>0)
    sum[i]=(ll)a+sum[i-1];
    else
    sum[i]=a;
    vec.push_back(a);
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    dp[i][j][0]=0,dp[i][j][1]=0;
  }
  for(int i=0;i<n;i++)
  dp[i][i][0]=(ll)vec[i],dp[i][i][1]=(ll)vec[i];
  ll T=util(0,n-1,0,vec,sum);
  ll J=sum[n-1]-T;
  cout<<T-J<<endl;
  return 0;
}
