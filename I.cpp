#include<iostream>
#include<bits/stdc++.h>
#define ld long double
#define Size 3000
using namespace std;
ld dp[Size][Size],prods[Size],rprods[Size];
ld util(int idx,int t,int n,vector<ld>&probs)
{
  if(t<0||idx>=n||idx<0)
  return 0;
  if(t>n-idx)
  return 0;
  if(t==n-idx)
  {
    if(idx==0)
    return dp[idx][t]=rprods[n-1];
    else
    return dp[idx][t]=rprods[n-1]/rprods[idx-1];
  }
  if(t==0)
  {
    if(idx==0)
    return dp[idx][t]=prods[n-1];
    else
    return dp[idx][t]=prods[n-1]/prods[idx-1];
  }
  if(dp[idx][t]>=0)
  return dp[idx][t];

  dp[idx][t]=(1-probs[idx])*util(idx+1,t-1,n,probs) + probs[idx]*util(idx+1,t,n,probs);
  return dp[idx][t];
}
int main()
{
  int n;
  cin>>n;
  vector<ld> probs;
  for(int i=0;i<n;i++)
  {
    ld temp;
    cin>>temp;
    probs.push_back(temp);
  }
  prods[0]=probs[0];
  for(int i=1;i<n;i++)
  prods[i]=probs[i]*prods[i-1];

  rprods[0]=1-prods[0];
  for(int i=1;i<n;i++)
  rprods[i]=(1-probs[i])*rprods[i-1];

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n+1;j++)
    dp[i][j]=(ld)-1;
  }
  ld ans=0;
  for(int i=0;i<=n/2;i++)
  {
    ans+=util(0,i,n,probs);
  }
  /*for(int i=0;i<n;i++)
  cout<<prods[i]<<" ";
  cout<<endl;
  for(int i=0;i<n;i++)
  cout<<rprods[i]<<" ";
  cout<<endl;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n+1;j++)
    cout<<dp[i][j]<<" ";
    cout<<endl;
  }*/
  cout<<setprecision(10)<<ans<<endl;
  return 0;
}
