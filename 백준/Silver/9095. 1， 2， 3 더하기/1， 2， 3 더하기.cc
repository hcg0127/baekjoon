#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t,n,dp[11]={},tmp;
  dp[1]=1;
  dp[2]=2;
  dp[3]=4;
  for (int i=4; i<11; i++) dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
  cin >> t;
  while (t--) {
    cin >> n;
    cout << dp[n] << '\n';
  }
}