#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  int n,w[10001]={},dp[10001]={},mx;
  cin >> n;
  for (int i=1; i<=n; i++) cin >> w[i];
  dp[1]=w[1];
  dp[2]=w[1]+w[2];
  mx=max(dp[1],dp[2]);
  for (int i=3; i<=n; i++) {
    dp[i]=max({dp[i-1],dp[i-2]+w[i],dp[i-3]+w[i-1]+w[i]});
    if (dp[i]>mx) mx=dp[i];
  }
  cout << mx;
}