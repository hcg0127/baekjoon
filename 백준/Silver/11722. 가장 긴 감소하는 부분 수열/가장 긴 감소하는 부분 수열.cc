#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n,arr[1001]={},dp[1001]={},ans=0;
  cin >> n;
  for (int i=1; i<=n; i++) cin >> arr[i];
  for (int i=1; i<=n; i++) {
    dp[i]=1;
    for (int j=1; j<=i; j++) {
      if (arr[i]<arr[j]) dp[i]=max(dp[i],dp[j]+1);
    }
  }
  cout << *max_element(dp,dp+n+1);
}